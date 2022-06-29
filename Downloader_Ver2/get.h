#ifndef _GET_H
#define _GET_H
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
class Base_Get
{
    protected:
        Base_Get();
        QString url;
        int code;
        int size;
        QByteArray content;
    public:
        virtual ~Base_Get();
        int getCode() const;
        int getSize() const;
        QByteArray getContent() const;
        QString getText() const;
};
class Get: public Base_Get
{
    public:
        Get(const QString& url, const QMap<QByteArray, QByteArray>* header = nullptr);
        ~Get();
};
#endif // _GET_H
