#include "downloaddialog1.h"

DownloadDialog1::DownloadDialog1(QStringList parts, QWidget *parent) :
    QDialog(parent)
{
    this->resize(400, 360);
    this->setWindowTitle("请选择下载分p");
    this->setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);
    partList = new QListWidget(this);
    partList->setGeometry(20, 20, 360, 280);

    for (auto part : parts) {
        QListWidgetItem *listItem = new QListWidgetItem(part);
        listItem->setCheckState(Qt::Unchecked);
        partList->addItem(listItem);
    }

    QPushButton * acceptBtn = new QPushButton(this);
    QPushButton * rejectBtn = new QPushButton(this);
    acceptBtn->setGeometry(210, 310, 80, 30);
    acceptBtn->setText("确定");
    rejectBtn->setGeometry(300, 310, 80, 30);
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
