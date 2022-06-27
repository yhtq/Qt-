#ifndef _GET_H
#define _GET_H
#include "get.h"
#include <iostream>
#include <QFile>
#include <QMap>
#include <QString>
#include <QTextStream>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QEventLoop>
#include <QApplication>

int Get::getCode() const
{
    return code;
}
int Get::getSize() const
{
    return size;
}
QByteArray Get::getContent() const
{
    return content;
}
Get::Get(const QString& url, const QMap<QByteArray, QByteArray>* header)
{
    QNetworkAccessManager AccessManager;
    QNetworkRequest request(url);
    if (header != nullptr)
    {
        for (auto& i : *header)
        {
            request.setRawHeader(i, header->value(i));
        }
    }
    QNetworkReply* reply = AccessManager.get(request);
    QEventLoop loop;
    QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
    code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    size = reply->header(QNetworkRequest::ContentLengthHeader).toInt();
    content = reply->readAll();
    reply->deleteLater();
}
QString Get::getText() const
{
    return QString::fromUtf8(content);
}
Get::~Get()
{
}
#endif 