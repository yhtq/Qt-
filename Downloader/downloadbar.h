#ifndef DOWNLOADBAR_H
#define DOWNLOADBAR_H

#include "QDebug"
#include "QMainWindow"
#include "QToolButton"
#include "QProgressBar"

class DownloadBar
{
public:
    DownloadBar(QMainWindow *ptr=nullptr,int px=95,int py=70);

    QToolButton *dbar;
    QToolButton *btn;
    QProgressBar *progress_bar;
};

#endif // DOWNLOADBAR_H
