#include "downloadbar.h"

DownloadBar::DownloadBar(QWidget *parent,int px,int py) : QMainWindow(parent)
{
    bar = new QToolButton(parent);
    bar->setGeometry(px,py,700,50);

    info = new QToolButton(bar);
    info->setGeometry(50,50,40,40);
    info->show();

    progress_bar = new QProgressBar(bar);
    progress_bar->setGeometry(60,0,50,40);
    progress_bar->show();
}

void DownloadBar::setParent(QWidget *parent)
{
    bar->setParent(parent);
    bar->setGeometry(80,60,700,50);
}

void DownloadBar::show()
{
    bar->show();
}
