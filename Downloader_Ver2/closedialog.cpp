#include "closedialog.h"
#include "QLabel"
#include "QPushButton"

CloseDialog::CloseDialog()
{
    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);
    setAttribute (Qt::WA_DeleteOnClose);

    Init_Dialog();
}

void CloseDialog::Init_Dialog()
{
    this->setObjectName("close_log");
    this->setStyleSheet("#close_log{background:rgb(255,255,255)}");
    this->deleteLater();
    this->setWindowTitle("Close Downloader");
    this->resize(360,200);
    QLabel* lel = new QLabel(this);
    lel->setGeometry(80,50,200,50);
    lel->setText("确定关闭下载器吗?");
    lel->setStyleSheet("QLabel{font-family:'微软雅黑';font-size:17px;color:rgb(0,0,0);}");
    lel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    QPushButton* okBtn = new QPushButton(this);
    okBtn->setGeometry(65,140,100,30);
    okBtn->setText("确定");
    QPushButton* clsBtn = new QPushButton(this);
    clsBtn->setGeometry(195,140,100,30);
    clsBtn->setText("取消");
    okBtn->setMaximumWidth(100);
    clsBtn->setMaximumWidth(100);

    connect(okBtn,&QPushButton::clicked,okBtn,[=]{
        this->done(QDialog::Accepted);
    });
    connect(clsBtn,&QPushButton::clicked,clsBtn,[=]{
        this->done(QDialog::Rejected);
    });
}
