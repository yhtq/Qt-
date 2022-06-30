#ifndef DOWNLOADDIALOG2_H
#define DOWNLOADDIALOG2_H

#include "qlabel.h"
#include <QDialog>
#include <QObject>
#include <QWidget>
#include <QComboBox>

class DownloadDialog2 : public QDialog
{
    Q_OBJECT

    QLabel *pathLabel;
    QComboBox *qnComboBox;
public:
    DownloadDialog2(QVector<QString> qualities, QString default_path, QWidget *parent = nullptr);

    QString Get_Choose_Quality();

private slots:
    void selectPath();
    void startGetCurrentItemQnList();
};

#endif // DOWNLOADDIALOG2_H
