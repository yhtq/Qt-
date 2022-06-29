#include "get.h"

Base_Get::Base_Get()
{
    this->url = "";
    this->code = 0;
    this->size = 0;
    this->content = QByteArray();
}
int Base_Get::getCode() const
{
    return code;
}
int Base_Get::getSize() const
{
    return size;
}
QByteArray Base_Get::getContent() const
{
    return content;
}
QString Base_Get::getText() const
{
    return QString::fromUtf8(content);
}
Base_Get::~Base_Get()
{
}
Get::Get(const QString& url, const QMap<QByteArray, QByteArray>* header):Base_Get()
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
Get::~Get()
{
}
