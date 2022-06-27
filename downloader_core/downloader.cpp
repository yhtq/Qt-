#ifndef _DOWNLOADER_H
#define _DOWNLOADER_H
#include "get.h"
#include "downloader.h"
#include <iostream>
#include <QFile>
#include <unordered_map>
#include <QString>
#include <QTextStream>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QEventLoop>
#include <QVector>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QApplication>
#include <QRegExp>

Downloader::Downloader(const QString& bvid, const QString& file_path)
{
    this->bvid = bvid;
    this->file_path = file_path;

}
void Downloader::download_cover(const QString& cover_path) const
{
    //TODO
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
}
QVector<QString> Downloader::get_accept_quality()
{
    QJsonObject jsonObject = info.object();
    QJsonArray jsonArray = jsonObject["data"].toObject()["accept_quality"].toArray();
    for (int i = 0; i < jsonArray.size(); i++)
    {
        accept_quality.push_back(jsonArray.at(i).toString());
    }
    return accept_quality;
}
QString Downloader::download(const QString& quality)
{   
    if (accept_quality.indexOf(quality) == -1)
    {
        return "视频质量不可用";
    }
    auto response = Get("https://api.bilibili.com/x/player/playurl?cid=" + this->cid + "&bvid=" + this->bvid + "&qn=" + quality + "&type=&otype=json");
    if (response.getCode() != 0)
    {
        return "获取视频失败";
    }
    QJsonDocument jsonDocument = QJsonDocument::fromJson(response.getContent());
    this->size = jsonDocument.object()["data"].toObject()["size"].toInteger();
    QString url = jsonDocument.object()["data"].toObject()["durl"].toArray().at(0).toObject()["url"].toString();
    QString file_name = this->file_path + "/" + this->bvid + "." + quality + ".mp4";
    QFile file(file_name);
    if (!file.open(QIODevice::WriteOnly))
    {
        return "文件打开失败";
    }
    QMap<QByteArray, QByteArray> headers;
    headers["User-Agent"] = "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/80.0.3987.149 Safari/537.36";
    headers["Referer"] = "https://www.bilibili.com/";
    headers["Origin"] = "https://www.bilibili.com";
    QRegExp rx("https://(.*?cn)");
    rx.indexIn(url);
    QString host = rx.cap(1);
    if (host == "")
    {
        rx = QRegExp("https://(.*?com)");
        rx.indexIn(url);
        host = rx.cap(1);
    }
    if (host == "")
    {
        return "获取视频失败";
    }
    headers["Host"] = host.toUtf8();
    auto res = Get(url, &headers);
    if (res.getCode() != 206)
    {
        return "获取视频失败";
    }
    QByteArray data = res.getContent();
    file.write(data);
    file.close();
    return "下载成功";
}
#endif // _DOWNLOADER_H