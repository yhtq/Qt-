#include "downloadbar.h"

DownloadBar::DownloadBar(QMainWindow *parent,int px,int py)
{
    dbar = new QToolButton(parent);
    dbar->setGeometry(px,py,690,70);
    dbar->setStyleSheet("QToolButton{background-color:rgba(191,213,217,0.2);border-radius:10px}");
    dbar->setText("Test");

    btn = new QToolButton(dbar);
    btn->setGeometry(10,10,300,50);
    btn->setStyleSheet("QToolButton{background-color:rgba(191,213,217,0);border:none}");
    btn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    btn->setIcon(QIcon(":/Icons/21021411.jpg"));
    btn->setIconSize(QSize(40,40));

    QFont* btn_font = new QFont;
    btn_font->setPointSize(10);
    btn_font->setFamily(("黑体"));
    btn->setFont(*btn_font);
    btn->setText("    爱你，就多判你一年");

    QProgressBar* progress_bar = new QProgressBar(dbar);
    progress_bar->setGeometry(480,20,200,30);
    progress_bar->setMinimum(0);
    progress_bar->setMaximum(100);
    progress_bar->setValue(47);
}
