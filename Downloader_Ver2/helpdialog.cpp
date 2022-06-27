#include "helpdialog.h"

HelpDialog::HelpDialog()
{
    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);
    setAttribute (Qt::WA_DeleteOnClose);

    Init_Dialog();
}

void HelpDialog::Init_Dialog()
{
    this->setObjectName("help_log");
    this->setStyleSheet("background:rgb(255,255,255)");
    this->deleteLater();
    this->setWindowTitle("Help");
    this->resize(400,600);
}
