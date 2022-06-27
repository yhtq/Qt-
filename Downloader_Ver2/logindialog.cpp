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
}
