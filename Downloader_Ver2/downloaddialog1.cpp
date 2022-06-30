#include "downloaddialog1.h"

DownloadDialog1::DownloadDialog1(QStringList parts, QWidget *parent) :
    QDialog(parent)
{
    this->resize(550, 480);
    this->setWindowTitle("请选择下载分p");
    this->setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);
    this->setWindowIcon(QIcon(":/Icon/logo.png"));
    partList = new QListWidget(this);
    partList->setGeometry(30, 30, 490, 360);
    partList->setSelectionMode(QAbstractItemView::SingleSelection);
    partList->setStyleSheet("position: absolute;color: rgb(30, 30, 30);"
                            "font-family: 微软雅黑;font-size: 16px;font-weight: 450;"
                            "line-height: 20px;text-align: left");

    for (auto part : parts) {
        QListWidgetItem *listItem = new QListWidgetItem(part);
        listItem->setSizeHint(QSize(490,40));
        //listItem->setCheckState(Qt::Unchecked);
        partList->addItem(listItem);
    }

    QPushButton * acceptBtn = new QPushButton(this);
    QPushButton * rejectBtn = new QPushButton(this);
    acceptBtn->setGeometry(165, 410, 100, 38);
    acceptBtn->setText("确定");
    rejectBtn->setGeometry(285, 410, 100, 38);
    rejectBtn->setText("取消");

    connect(acceptBtn, &QPushButton::clicked, this, &DownloadDialog1::accept);

    connect(rejectBtn, &QPushButton::clicked, this, [=]{
        partList->clearSelection();
        DownloadDialog1::reject();
    });
}

QList<QListWidgetItem*> DownloadDialog1::selectedItems() {
    return partList->selectedItems();
}
