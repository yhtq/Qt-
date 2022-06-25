#include "widget.h"
#include "ui_widget.h"
#include <QMouseEvent>
#include "QFrame"
#include "QLabel"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    Init_Widget();
    Init_Top();
    Init_SideBar();
    Init_Cell();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::Init_Widget()
{
    this->setWindowFlags(Qt::FramelessWindowHint);//设置无窗口框架边界
    //this->setAttribute();//设置背景透明

    this->resize(1080,720);
    this->setStyleSheet("background:rgb(255,255,255)");

}

void Widget::Init_Top()
{
    top = new QWidget(this);
    top->setGeometry(0,0,1080,40);
    top->setStyleSheet("background:rgb(255,255,255)");

    QWidget *logo = new QWidget(top);
    logo->setGeometry(20,10,24,20);
    QFrame *logo_icon = new QFrame(logo);
    logo_icon->setStyleSheet("background-image:url(:/Icon/MainWidget/Top/logo_icon.png)");

    QLabel *title = new QLabel(top);
    title->setGeometry(57,10,312,24);
    title->setText(QString("独立应用"));
    title->setStyleSheet("position: absolute;color: rgb(38, 38, 38);"
                         "font-family: PingFang SC;font-size: 14px;font-weight: 400;"
                         "line-height: 24px;text-align: left");
    QWidget *search_bar = new QWidget(top);
    search_bar->setGeometry(400,4,280,32);
    search_bar->setStyleSheet("background: rgb(247, 247, 247);border-radius: 16px;");
    QFrame *search_bar_icon = new QFrame(search_bar);
    search_bar_icon->setGeometry(92,6,20,20);
    search_bar_icon->setStyleSheet("background-image:url(:/Icon/MainWidget/Top/search_bar_icon.png)");
    QLabel *search_bar_text = new QLabel(search_bar);
    search_bar_text->setGeometry(120,6,56,20);
    search_bar_text->setText(QString("搜索名称"));
    search_bar_text->setStyleSheet("position: absolute;color: rgb(191, 191, 191);"
                                   "font-family: PingFang SC;font-size: 14px;font-weight: 400;"
                                   "line-height: 20px;text-align: left");

    QWidget *right = new QWidget(top);
    right->setGeometry(826,8,238,23);
    QFrame *right_ = new QFrame(right);
    right_->setGeometry(0,0,238,23);
    right_->setStyleSheet("background-image:url(:/Icon/MainWidget/Top/right_.png)");
}

void Widget::Init_SideBar()
{
    sideBar = new QWidget(this);
    sideBar->setGeometry(22,88,209,257);
    sideBar->setStyleSheet("background:rgb(255,255,255)");

    QWidget *divider = new QWidget(sideBar);
    divider->setGeometry(6,168,197,1);
    divider->setStyleSheet("background:rgb(229,229,229)");

    QWidget *btn1 = new QWidget(sideBar);
    btn1->setGeometry(0,0,209,40);
    btn1->setStyleSheet("background:rgb(255,255,255)");
    QFrame *icon1 = new QFrame(btn1);
    icon1->setGeometry(16,10,20,20);
    icon1->setStyleSheet("background-image:url(:/Icon/MainWidget/SideBar/icon1.png)");
    QLabel *text1 = new QLabel(btn1);
    text1->setGeometry(44,10,110,20);
    text1->setText(QString("一级菜单"));
    text1->setStyleSheet("position: absolute;color: rgb(70, 70, 70);"
                         "font-family: PingFang SC;font-size: 14px;font-weight: 500;"
                         "line-height: 20px;text-align: left");

    QWidget *btn2 = new QWidget(sideBar);
    btn2->setGeometry(0,80,209,40);
    btn2->setStyleSheet("background:rgb(255,255,255)");
    QFrame *icon2 = new QFrame(btn2);
    icon2->setGeometry(16,10,20,20);
    icon2->setStyleSheet("background-image:url(:/Icon/MainWidget/SideBar/icon2.png)");
    QLabel *text2 = new QLabel(btn2);
    text2->setGeometry(44,10,110,20);
    text2->setText(QString("一级菜单"));
    text2->setStyleSheet("position: absolute;color: rgb(140, 140, 140);"
                         "font-family: PingFang SC;font-size: 14px;font-weight: 400;"
                         "line-height: 20px;text-align: left");

    QWidget *btn_ = new QWidget(sideBar);
    btn_->setGeometry(0,177,209,40);
    btn_->setStyleSheet("background:rgb(255,255,255)");
    QFrame *icon_ = new QFrame(btn_);
    icon_->setGeometry(16,10,20,20);
    icon_->setStyleSheet("background-image:url(:/Icon/MainWidget/SideBar/icon_.png)");
    QLabel *text_ = new QLabel(btn_);
    text_->setGeometry(44,10,110,20);
    text_->setText(QString("成员管理"));
    text_->setStyleSheet("position: absolute;color: rgb(120, 120, 120);"
                         "font-family: PingFang SC;font-size: 14px;font-weight: 400;"
                         "line-height: 20px;text-align: left");

    QWidget *btn_set = new QWidget(sideBar);
    btn_set->setGeometry(0,217,209,40);
    btn_set->setStyleSheet("background:rgb(255,255,255)");
    QFrame *icon_set = new QFrame(btn_set);
    icon_set->setGeometry(16,10,20,20);
    icon_set->setStyleSheet("background-image:url(:/Icon/MainWidget/SideBar/icon_set.png)");
    QLabel *text_set = new QLabel(btn_set);
    text_set->setGeometry(44,10,110,20);
    text_set->setText(QString("应用设置"));
    text_set->setStyleSheet("position: absolute;color: rgb(120, 120, 120);"
                            "font-family: PingFang SC;font-size: 14px;font-weight: 400;"
                            "line-height: 20px;text-align: left");
}

void Widget::Init_Cell()
{
    QWidget *_ = new QWidget(this);
    _->setGeometry(256,88,812,80);
    _->setStyleSheet("background:rgb(255,255,255)");
    QFrame *_icon = new QFrame(_);
    _icon->setStyleSheet("background-image:url(:/Icon/MainWidget/_icon.png)");

    cell = new QWidget(this);
    cell->setGeometry(256,188,812,426);
    cell->setStyleSheet("background:rgb(255,255,255)");

    QWidget *ele = new QWidget(cell);
    ele->setGeometry(0,0,812,49);
    QWidget *ele_divider = new QWidget(ele);
    ele_divider->setGeometry(49,48,763,1);
    ele_divider->setStyleSheet("background:rgb(229,229,229)");
    QFrame *ele_icon = new QFrame(ele);
    ele_icon->setGeometry(0,0,40,40);
    ele_icon->setStyleSheet("background-image:url(:/Icon/MainWidget/Cell/ele_icon.png)");
    QLabel *ele_text = new QLabel(ele);
    ele_text->setGeometry(52,10,177,14);
    ele_text->setText(QString("Download_task1"));
    ele_text->setStyleSheet("position: absolute;color: rgb(38, 38, 38);"
                            "font-family: PingFang SC;font-size: 14px;font-weight: 500;"
                            "line-height: 20px;text-align: left");
    QWidget *ele_extra = new QWidget(ele);
    ele_extra->setGeometry(742,5,60,22);
    ele_extra->setStyleSheet(".QWidget{border: 1px solid rgb(229, 229, 229);border-radius: 4px;}");
    QLabel *ele_extra_text = new QLabel(ele_extra);
    ele_extra_text->setGeometry(7,1,50,20);
    ele_extra_text->setText(QString("企业可见"));
    ele_extra_text->setStyleSheet("position: absolute;color: rgb(140, 140, 140);"
                                  "font-family: PingFang SC;font-size: 12px;font-weight: 400;"
                                  "line-height: 20px;text-align: left");

}

//copy from https://www.cnblogs.com/MakeView660/p/10619334.html#:~:text=%E6%88%91%E4%BB%AC%E7%9F%A5%E9%81%93%EF%BC%8C%E8%A6%81%E5%AE%9E%E7%8E%B0,veEvent%E3%80%82
/* QPoint QMouseEvent::pos() const
    Returns the position of the mouse cursor, relative to the widget that received the event.
    If you move the widget as a result of the mouse event, use the global position returned by globalPos() to avoid a shaking motion.
 */

//拖拽操作
void Widget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        m_bDrag = true;
        //获得鼠标的初始位置
        mouseStartPoint = event->globalPos();
        //mouseStartPoint = event->pos();
        //获得窗口的初始位置
        windowTopLeftPoint = this->frameGeometry().topLeft();
    }
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if(m_bDrag)
    {
        //获得鼠标移动的距离
        QPoint distance = event->globalPos() - mouseStartPoint;
        //QPoint distance = event->pos() - mouseStartPoint;
        //改变窗口的位置
        this->move(windowTopLeftPoint + distance);
    }
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        m_bDrag = false;
    }
}
