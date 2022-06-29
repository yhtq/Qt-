#ifndef DOWNLOADDIALOG2_H
#define DOWNLOADDIALOG2_H

#include "qlabel.h"
#include <QDialog>
#include <QObject>
#include <QWidget>

class DownloadDialog2 : public QDialog
{
    Q_OBJECT

    QLabel *pathLabel;
public:
    DownloadDialog2(QWidget *parent = nullptr);

private slots:
    void selectPath();
    void startGetCurrentItemQnList();
};

#endif // DOWNLOADDIALOG2_H
