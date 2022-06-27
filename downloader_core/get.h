#include <iostream>
#include <QString>
class Get
{
    private:
        QString url;
        int code = 0;
        int timeout = 10;
        int size = 0;
        QByteArray content;
    public:
        Get(const QString& url, const QMap<QByteArray, QByteArray>* header = nullptr);
        ~Get();
        int getCode() const;
        int getSize() const ;
        QByteArray getContent() const;
        QString getText() const;
};