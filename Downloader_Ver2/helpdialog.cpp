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
    this->resize(450,250);

    QTextEdit *help_txt = new QTextEdit(this);
    help_txt->setGeometry(40,30,370,250);
    help_txt->setStyleSheet("position: absolute;color: rgb(30, 30, 30);"
                            "font-family: 微软雅黑;font-size: 18px;font-weight: 450;"
                            "line-height: 20px;text-align: left;"
                            "border-width:0;border-style:outset");
    help_txt->setText("操作流程：\n"
                      "1:在Setting里确认默认下载地址\n"
                      "2:获取需下载视频的bv号,在输入框内输入(不带前缀)\n"
                      "3:选择分p(如果多p)和清晰度(高清晰度可能需要会员而导致下载失败)");
    help_txt->setReadOnly(true);
}
