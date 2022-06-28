#include "line_edit.h"
#include "QLabel"
#include "QPushButton"
#include "QDebug"

Line_Edit::Line_Edit(QWidget *parent_,int PX_,int PY_) : parent(parent_),PX(PX_),PY(PY_)
{
    setSize(600,50);
    init();
}

void Line_Edit::init()
{
    QWidget *box = new QWidget(parent);
    box->setGeometry(PX,PY,W,H);
    QFrame *icon = new QFrame(box);
    icon->setGeometry(0,0,50,50);
    icon->setStyleSheet("background-image:url(:/Icon/logo_.png)");
    QWidget *search_bar = new QWidget(box);
    search_bar->setGeometry(50,0,W-110,H);
    search_bar->setStyleSheet("background: rgb(247, 247, 247);border-radius: 16px;");
    line_edit = new QLineEdit(search_bar);
    line_edit->setGeometry(0,0,W-110,H);
    line_edit->setAlignment(Qt::AlignCenter);
    line_edit->setPlaceholderText("输入下载资源的URL");
    line_edit->setStyleSheet("position: absolute;color: rgb(150, 150, 150);"
                             "font-family: 微软雅黑;font-size: 16px;font-weight: 400;"
                             "line-height: 20px;text-align: left");
}

void Line_Edit::setPos(int PX_,int PY_)
{
    PX = PX_;
    PY = PY_;
}

void Line_Edit::setSize(int W_,int H_)
{
    W = W_;
    H = H_;
}
