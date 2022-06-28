#include "downloader.h"
#include "get.h"
#include <iostream>
#include <QFile>
#include <unordered_map>
#include <QString>
#include <QTextStream>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QEventLoop>
#include <sstream>
#include <QApplication>
std::stringstream _log_stream;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Downloader::delay(10000);
    //Downloader::delay(20000);
    _log_stream << "1" << '\n';
    Downloader d("1oL4y1K7My", ".");
    Downloader d2("1oL4y1K7My", "./temp");
    d.select_page("742385024");
    d2.select_page("742385024");
    d.get_accept_quality();
    d2.get_accept_quality();
    auto result = d.download_prepare("16");
    d2.download_prepare("16");
    if (result != "准备下载")
    {
        std::cout << result.toStdString() << std::endl;
        return 0;
    }
    //下面是一个下载进度的例子，可以根据需求重写
    //利用d与ui控件的connect即可实现进度条的显示
    QObject::connect(&d, &Downloader::download_progress, [&d](int cur_byte, int last_byte) {
        int temp_time = time(0);
        static int cur_time = temp_time;
        static long long last = cur_byte;
        if (temp_time - cur_time > 1)
        {
            std::cout << "当前1下载进度：" << cur_byte << "/" << d.getSize() << std::endl;
            std::cout << "当前1下载速度：" << (cur_byte - last) / 1024 / (temp_time - cur_time) << "KB/s" << std::endl;
            cur_time = temp_time;
            last = cur_byte;
        }
    });
    QObject::connect(&d2, &Downloader::download_progress, [&d2](int cur_byte, int last_byte) {
        int temp_time = time(0);
        static int cur_time = temp_time;
        static long long last = cur_byte;
        if (temp_time - cur_time > 1)
        {
            std::cout << "当前2下载进度：" << cur_byte << "/" << d2.getSize() << std::endl;
            std::cout << "当前2下载速度：" << (cur_byte - last) / 1024 / (temp_time - cur_time) << "KB/s" << std::endl;
            cur_time = temp_time;
            last = cur_byte;
        }
    });
    bool status;
    auto future1 = d.start_download(status);
    auto future2 = d2.start_download(status);
    if (!status)
    {
        std::cout << "下载失败" << std::endl;
        return 0;
    }
    QFutureSynchronizer<void> sync;
    sync.addFuture(future1);            //  多个下载任务用类似的方法addfuture实现
    sync.addFuture(future2);            
    sync.waitForFinished();             //  等待所有下载任务完成
    return a.exec();
}
