#ifndef _DOWNLOADER_H
#define _DOWNLOADER_H
#include "get.h"
#include "downloader.h"

Downloader::Downloader(const QString& bvid, const QString& file_path)
{
    this->bvid = bvid;
    this->file_path = file_path;
}
void Downloader::download_cover(const QString& cover_path) const
{
    //TODO
}
bool Downloader::is_download() const
{
    return is_downloading;
}
bool Downloader::is_complete() const
{
    return is_completed;
}
QJsonDocument Downloader::get_video_info() const
{
    auto video_info = Get("https://api.bilibili.com/x/web-interface/view?bvid=" + bvid);
    QJsonDocument info = QJsonDocument::fromJson(video_info.getContent());
    return info;
}
QJsonArray Downloader::get_page_info()
{
    auto page_info = Get("https://api.bilibili.com/x/player/pagelist?bvid=" + this->bvid + "&qn=16&type=&otype=json").getContent();
    return QJsonDocument::fromJson(page_info).object()["data"].toArray();
}
void Downloader::select_page(const QString& cid)
{
    this->cid = cid;
    auto res = Get("https://api.bilibili.com/x/player/playurl?cid=" + this->cid + "&bvid=" + this->bvid + "&qn=16&type=&otype=json");
    if (res.getCode() != 200)
    {
        return ;
    }
    std::string content = res.getText().toStdString();
    this->info = QJsonDocument::fromJson(res.getContent());

}
QVector<QString> Downloader::get_accept_quality()
{
    QJsonObject jsonObject = info.object();
    QJsonArray jsonArray = jsonObject["data"].toObject()["accept_quality"].toArray();
    for (int i = 0; i < jsonArray.size(); i++)
    {
        int quality = jsonArray.at(i).toDouble();
        this->accept_quality.push_back(QString::number(quality));
        std::string s = QString::number(quality).toStdString();
    }
    return accept_quality;
}
QString Downloader::download_prepare(const QString& quality)
{   
    if (accept_quality.indexOf(quality) == -1)
    {
        return "视频质量不可用";
    }
    auto response = Get("https://api.bilibili.com/x/player/playurl?cid=" + this->cid + "&bvid=" + this->bvid + "&qn=" + quality + "&type=&otype=json");
    if (response.getCode() != 200)
    {
        return "获取视频失败";
    }
    QJsonDocument jsonDocument = QJsonDocument::fromJson(response.getContent());
    this->size = jsonDocument.object()["data"].toObject()["durl"].toArray().at(0).toObject()["size"].toDouble();
    this->url = jsonDocument.object()["data"].toObject()["durl"].toArray().at(0).toObject()["url"].toString();
    this->_file_name = this->file_path + "/" + this->bvid + "_"+ this->cid + "_" + quality;
    QString file_name = this->file_path + "/" + this->bvid + "_"+ this->cid + "_" + quality + ".tmp";    //  下载过程中使用的临时文件名
    QFileInfo file(file_name);
    if (file.exists())
    {
        cur_progress = file.size();
        pre_progress = cur_progress;
    }
    else if (QFileInfo(this->file_path + "/" + this->bvid + "_"+ this->cid + "_" + quality + ".mp4").exists())
    {
        cur_progress = size;
        pre_progress = cur_progress;
        return "视频已存在";
    }
    else
    {
        cur_progress = 0;
        pre_progress = 0;
    }
    QFile log_file("./log/" + this->bvid + "_"+ this->cid +  "_" + quality + ".log");
    if (!log_file.open(QIODevice::WriteOnly))
    {
        return "log文件打开失败";
    }
    QTextStream out(&log_file);
    out << QString("bvid:%1 cid:%2 quality:%3 file_path:%4").arg(this->bvid).arg(this->cid).arg(quality).arg(this->file_path) << '\n';
    out << QString("url:%1").arg(url) << '\n';
    out << QString("size:%1").arg(size) << '\n';
    log_file.close();
    get_header();
    if (headers["Host"] == "")
    {
        return "获取host失败";
    }
    has_prepared = true;
    return "准备下载";
}
void Downloader::get_header()
{
    headers["User-Agent"] = "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/80.0.3987.149 Safari/537.36";
    headers["Referer"] = "https://www.bilibili.com/";
    headers["Origin"] = "https://www.bilibili.com";
    QRegularExpression rx("https://(.*?\\.cn)");
    auto match = rx.match(url);
    if (!match.hasMatch())
    {
        rx.setPattern("https://(.*?\\.com)");
        match = rx.match(url);
    }
    if (!match.hasMatch())
    {
        headers["Host"] = "";
        return;
    }
    QString host = match.captured(1);
    headers["Host"] = host.toUtf8();
}
Downloader::Downloader(const QString& log)
{
    if (log == "")
    {
        return;
    }
    auto rx = QRegularExpression("bvid:(.*?) cid:(.*?) quality:(.*?) file_path:(.*?)");
    auto match = rx.match(log);
    if (!match.hasMatch())
    {
        return;
    }
    this->bvid = match.captured(1);
    this->cid = match.captured(2);
    QString quality = match.captured(3);
    this->file_path = match.captured(4);
    rx = QRegularExpression("url:(.*?)");
    match = rx.match(log);
    if (!match.hasMatch())
    {
        return;
    }
    this->url = match.captured(1);
    rx = QRegularExpression("size:(.*?)");
    match = rx.match(log);
    if (!match.hasMatch())
    {
        return;
    }
    this->size = match.captured(1).toLongLong();
    this->_file_name = this->file_path + "/" + this->bvid + "_"+ this->cid + "_" + quality;
    this->get_header();
    if (headers["Host"] == "")
    {
        return;
    }
    QFileInfo file_info(this->_file_name + ".tmp");
    if (file_info.exists())
    {
        cur_progress = file_info.size();
        pre_progress = cur_progress;
    }
    else if (QFileInfo(this->_file_name + ".mp4").exists())
    {
        cur_progress = size;
        pre_progress = cur_progress;
        return;
    }
    else
    {
        cur_progress = 0;
        pre_progress = 0;
    }
    has_prepared = true;

}
QString Downloader::start_download()
{
    if (!has_prepared)
    {
        return "未准备下载";
    }
    is_downloading = true;
    download();
    return "下载中";
}
void Downloader::download()
{
    QNetworkRequest request;
    QString down_size = QString::number(size);
    QString cur_size = QString::number(cur_progress);
    headers["Range"] = QString("bytes=" + cur_size + "-" + down_size).toLatin1();
    request.setUrl(QUrl(url));
    for (auto i : headers.keys())
    {
        auto a = i;
        auto b = headers[i];
        request.setRawHeader(i, headers[i]);
    }
    manager = new QNetworkAccessManager();
    reply = manager->get(request);
    QObject::connect(reply, &QNetworkReply::readyRead, [=]()
    {
        QFile file(this->_file_name + ".tmp");
        if (!file.open(QIODevice::Append))
        {
            return;
        }
        file.write(reply->readAll());
        file.close();
        cur_progress += reply->size();
    });
    QObject::connect(reply, &QNetworkReply::finished, [=]()
    {
        reply->deleteLater();
        manager->deleteLater();
        is_downloading = false;
        is_completed = true;
        if (cur_progress == size)
        {
            QFile file(this->_file_name + ".tmp");
            file.rename(this->_file_name + ".mp4");
            QFile::remove(this->_file_name + ".tmp");
            QFile::remove(this->_file_name + ".log");
        }
    });


}
void Downloader::pause_download()
{
    is_downloading = false;
    QObject::disconnect(reply, &QNetworkReply::readyRead, 0, 0);
    QObject::disconnect(reply, &QNetworkReply::finished, 0, 0);
    reply->abort();
    reply->deleteLater();
    manager->deleteLater();

}
void Downloader::download_progress(QTextStream& qts, int time_delta)
{
    if (cur_progress == size)
    {
        return;
    }
    if (!is_downloading)
    {
        return;
    }
    qts << QString("%1 %2").arg(cur_progress).arg(pre_progress) << "\n";
    pre_progress = cur_progress;
    delay(time_delta);
    download_progress(qts, time_delta);
}
void Downloader::delay(int ms)
{
    QEventLoop loop;
    QTimer t;
    t.connect(&t, &QTimer::timeout, &loop, &QEventLoop::quit);
    t.start(ms);
    loop.exec();
} 
#endif // _DOWNLOADER_H