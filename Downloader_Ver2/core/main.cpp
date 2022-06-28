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
#include <QApplication>
QFile _log("log.txt");
QTextStream _log_stream(&_log);
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    _log.open(QIODevice::WriteOnly | QIODevice::Text);
    _log_stream << "1" << '\n';
    Downloader d("1oL4y1K7My", ".");
    _log_stream << "2" << '\n';
    d.select_page("742385024");
    d.get_accept_quality();
    d.download_prepare("16");
    d.start_download();
    _log_stream << "3" << '\n';
    _log_stream << "4" << '\n';
    _log.close();
    return a.exec();
}
