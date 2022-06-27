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
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile _log("log.txt");
    _log.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream _log_stream(&_log);
    _log_stream << "1" << '\n';
    Downloader d("1oL4y1K7My", ".");
    _log_stream << "2" << '\n';
    d.get_accept_quality();
    _log_stream << "3" << '\n';
    d.select_page("742385024");
    _log_stream << "4" << '\n';
    _log_stream << d.download("16") << '\n';
    _log.close();
    return a.exec();
}
