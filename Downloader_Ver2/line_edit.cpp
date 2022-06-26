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
    QLineEdit *line_edit = new QLineEdit(search_bar);
    line_edit->setGeometry(0,0,W-110,H);
    line_edit->setAlignment(Qt::AlignCenter);
    line_edit->setPlaceholderText("输入下载资源的URL");
    line_edit->setStyleSheet("position: absolute;color: rgb(150, 150, 150);"
                             "font-family: 微软雅黑;font-size: 16px;font-weight: 400;"
                             "line-height: 20px;text-align: left");
    //下载按钮
    QPushButton *down_load = new QPushButton(box);
    down_load->setGeometry(W-50,0,50,50);
    down_load->setStyleSheet("QPushButton{background: rgb(255, 255, 255);background-image:url(:/Icon/logo_.png);border-radius: 16px;}"
                             "QPushButton:hover{background: rgb(240, 240, 240);background-image:url(:/Icon/logo_.png)}"
                             "QPushButton:pressed{background: rgb(230, 230, 230);background-image:url(:/Icon/logo_.png)}");

//    connect(down_load,&QPushButton::clicked,line_edit,[=]{
//        QString s = line_edit->text();
//        qDebug() << s;
//    });



//    QFrame *search_bar_icon = new QFrame(search_bar);
//    search_bar_icon->setGeometry(92,6,20,20);
//    search_bar_icon->setStyleSheet("background-image:url(:/Icon/MainWidget/Top/search_bar_icon.png)");
//    QLabel *search_bar_text = new QLabel(search_bar);
//    search_bar_text->setGeometry(120,6,56,20);
//    search_bar_text->setText(QString("搜索名称"));
//    search_bar_text->setStyleSheet("position: absolute;color: rgb(191, 191, 191);"
//                                   "font-family: 微软雅黑;font-size: 14px;font-weight: 400;"
//                                   "line-height: 20px;text-align: left");
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
