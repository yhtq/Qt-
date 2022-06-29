#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H
#include "qwidget.h"
#include <QtGui>
#include <QProgressBar>
#include <QLabel>
#include <QSlider>
#include <QImage>

class ProgressBar : public QWidget
{
    Q_OBJECT

    QProgressBar progBar;
    QLabel       progValue;
    QImage       progImage;

public:
    void  onValueChanged(int value);

public slots:
    void setValue(int value);

public:
    explicit ProgressBar(const QString&  fileName,QWidget *parent = 0);
};

#endif // PROGRESSBAR_H
