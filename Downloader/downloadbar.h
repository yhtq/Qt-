#ifndef DOWNLOADBAR_H
#define DOWNLOADBAR_H

#include <QMainWindow>
#include "QToolButton"
#include "QProgressBar"

class DownloadBar : public QMainWindow
{
    Q_OBJECT
public:
    explicit DownloadBar(QWidget *parent = nullptr,int px=80,int py=60);
    void setParent(QWidget *parent);
    void show();
    //~DownloadBar();

    QToolButton* bar;
    QToolButton* info;
    QProgressBar* progress_bar;
signals:

};

#endif // DOWNLOADBAR_H
