#ifndef DOWNLOADDIALOG1_H
#define DOWNLOADDIALOG1_H

#include <QDialog>
#include <QObject>
#include <QWidget>
#include <QListWidget>
#include <QPushButton>

class DownloadDialog1 : public QDialog
{
    Q_OBJECT

    QListWidget *partList;

public:
    DownloadDialog1(QStringList parts, QWidget *parent = nullptr);
    QList<QListWidgetItem*> selectedItems();
};

#endif // DOWNLOADDIALOG1_H
