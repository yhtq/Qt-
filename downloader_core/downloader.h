#include <iostream>
#include <string>
#include <vector>
#include <QVector>
#include <QJsonDocument>
class Downloader
{
public:
    Downloader(const QString& bvid, const QString& file_path);  // cid, bvid均不含前缀
    QJsonDocument get_video_info() const; // 获取视频信息,内容是 api.bilibili.com/x/web-interface/view?bvid=BV1zE1y1y7zU
    QJsonArray get_page_info(); //得到分p信息，内容是 api.bilibili.com/x/player/pagelist?bvid={bvid}&jsonp=jsonp 的data值列表
    void select_page(const QString& cid); //选择分p,输入cid不含前缀
    void download_cover(const QString& cover_path) const; //下载封面
    QVector<QString> get_accept_quality();    //得到支持的视频质量
    QString download(const QString& quality);    // 下载视频,参数为清晰度,返回下载状态，执行前必须执行上面的函数确定可行质量
private:
    QString cid;
    QString bvid;
    QJsonDocument info;
    long long size;
    QString file_path;
    QVector<QString> accept_quality;
};