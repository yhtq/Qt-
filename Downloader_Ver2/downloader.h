#ifndef _DOWNLOADER_H
#define _DOWNLOADER_H
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
#include <ctime>
#include <QRegularExpression>
#include <QFileInfo>
#include <QtConcurrent>
#include <sstream>
class Downloader: public QObject
{
    Q_OBJECT
public:
    //流程：
    //1. 构造对象，根据bvid和file_path初始化，file_path是保存路径，当前路径就写".",当前目录下的temp文件夹就写".\temp"
    //2. 选定分p，调用select_page()，返回值是一个QString，表示选定的p的cid
    //3. 调用get_accept_quality()，返回值是一个QVector<QString>，表示支持的视频质量
    //4. 调用download_prepare()，参数是quality, 返回值是一个QString，表示准备下载的结果，如果准备下载成功，则返回"准备下载"，否则返回错误信息
    //  (这个函数内部会自动获取url，size，确定文件名，请求头等信息)
    //5. 调用start_download(), 返回值是一个future, 可以将future加入到QFutureSynchronizer中，以便同步下载
    //6. download过程中每次接收到数据会发送一个信号，参数是当前下载进度和上一次发送信号的下载进度（似乎没啥用），单位是字节
    //7. 下载完成（或者连接意外中断）会发送finish信号，参数是下载结果，如果下载成功，则返回1，否则返回0
    static void delay(int ms);
    Downloader(const QString& bvid, const QString& file_path);  // cid, bvid均不含前缀
    Downloader(const QString& log);  //读取log文件，获取信息，输入参数为log文件内容，读取正常完成后可以直接执行下载
    QMap<QString, QString> get_video_info() const; // 获取视频信息,key分别为title (标题)， desc (简介)， owner (up主名)
    QMap<QString, QString> get_page_info(); //得到分p信息，内容是一个map，key为cid，value为分p标题
    void select_page(const QString& cid); //选择分p,输入cid不含前缀
    void download_cover(const QString& cover_path) const; //下载封面（还没写）
    QVector<QString> get_accept_quality();    //得到支持的视频质量
    QString download_prepare(const QString& quality);    // 获得下载链接，请求头等信息,参数为清晰度,返回状态，执行前必须执行上面的函数确定可行质量
    QFuture<void> start_download(bool& valid); //开始下载
    void pause_download(); //暂停下载
    //virtual QList<long long> download_progress(int cur_byte, int last_byte); //下载进度，建议继承按照需求重写”
    bool is_download() const; //是否正在下载
    bool is_complete() const; //是否下载完成
    void wait_for_complete();
    long long getSize() const;
    QString save_as_audio();
    ~Downloader();
signals:
    void download_progress(int cur_byte, int last_byte);
    void finish(int result);
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
    QNetworkAccessManager* manager = nullptr;
    QNetworkReply* reply = nullptr;
    QFuture<void> download_future;
    void get_header();
    void download();
};
#endif // _DOWNLOADER_H