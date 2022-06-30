#include "logindialog.h"
#include "QLabel"

LoginDialog::LoginDialog()
{
    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);
    setAttribute (Qt::WA_DeleteOnClose);

    Init_Dialog();
}

void LoginDialog::Init_Dialog()
{
    this->setObjectName("login_log");
    this->setStyleSheet("background:rgb(255,255,255)");
    this->deleteLater();
    this->setWindowTitle("Login");
    this->resize(250,200);

    QLabel *text = new QLabel(this);
    text->setGeometry(75,70,100,30);
    text->setText(QString("功能暂未开放"));
    text->setStyleSheet("position: absolute;color: rgb(100, 100, 100);"
                        "font-family: 微软雅黑;font-size: 16px;font-weight: 400;"
                        "line-height: 20px;text-align: left");
}
