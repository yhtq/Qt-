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
#include <QObject>
#include <QTimer>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QApplication>
#include <QRegularExpression>
#include <QFileInfo>
class Downloader
{
public:
    static void delay(int ms);
    Downloader(const QString& bvid, const QString& file_path);  // cid, bvid均不含前缀
    Downloader(const QString& log);  //读取log文件，获取信息，输入参数为log文件内容，读取正常完成后可以直接执行下载
    QJsonDocument get_video_info() const; // 获取视频信息,内容是 api.bilibili.com/x/web-interface/view?bvid=BV1zE1y1y7zU
    QJsonArray get_page_info(); //得到分p信息，内容是 api.bilibili.com/x/player/pagelist?bvid={bvid}&jsonp=jsonp 的data值列表
    void select_page(const QString& cid); //选择分p,输入cid不含前缀
    void download_cover(const QString& cover_path) const; //下载封面（还没写）
    QVector<QString> get_accept_quality();    //得到支持的视频质量
    QString download_prepare(const QString& quality);    // 获得下载链接，请求头等信息,参数为清晰度,返回状态，执行前必须执行上面的函数确定可行质量
    QString start_download(); //开始下载
    void pause_download(); //暂停下载
    void download_progress(QTextStream& qts, int time_delta); //下载进度，每隔time_delta毫秒向qts写入一次进度信息，内容为“{当前下载字节数} {上一次调用下载字节数}”
    bool is_download() const; //是否正在下载
    bool is_complete() const; //是否下载完成

private:
    QString cid;
    QString bvid;
    QJsonDocument info;
    bool has_prepared = false;
    bool is_downloading = false;
    bool is_completed = false;
    long long size; // 视频总字节数
    long long pre_progress = 0;
    long long cur_progress = 0;
    QString file_path;
    QString url;
    QString _file_name;  //文件名，不含类型后缀
    QMap <QByteArray, QByteArray> headers;
    QVector<QString> accept_quality;
    QNetworkAccessManager* manager;
    QNetworkReply* reply;
    void get_header();
    void download();
};