#include "line_edit.h"
#include "QLabel"
#include "QPushButton"
#include "QDebug"

Line_Edit::Line_Edit(QWidget *parent_,int PX_,int PY_) : parent(parent_),PX(PX_),PY(PY_)
{
    setSize(730,50);
    init();
}

void Line_Edit::init()
{
    QWidget *box = new QWidget(parent);
    box->setGeometry(PX,PY,W,H);
    QFrame *icon = new QFrame(box);
    icon->setGeometry(1,1,48,48);
    icon->setStyleSheet("background-image:url(:/Icon/MainWidget/ChildWidget1/SearchBar/icon.png)");
    QFrame *text = new QFrame(box);
    text->setGeometry(49,5,100,37);
    text->setStyleSheet("background-image:url(:/Icon/MainWidget/ChildWidget1/SearchBar/text.png)");
    QWidget *search_bar = new QWidget(box);
    search_bar->setGeometry(180,0,W-200,H);
    search_bar->setStyleSheet("background: rgb(247, 247, 247);border-radius: 0px;");
    line_edit = new QLineEdit(search_bar);
    line_edit->setGeometry(0,0,W-200,H);
    line_edit->setAlignment(Qt::AlignCenter);
    line_edit->setPlaceholderText("输入下载资源的URL");
    line_edit->setStyleSheet("position: absolute;color: rgb(140, 140, 140);"
                             "font-family: 微软雅黑;font-size: 17px;font-weight: 450;"
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
