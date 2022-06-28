#include "cellelem.h"

CellElem::CellElem(const QString &taskName, const QString &url, const QString &path, QListWidgetItem *item, QWidget *parent)
    : QWidget{parent},
      m_taskName(taskName)
{
    QWidget *ele_divider = new QWidget(this);
    ele_divider->setGeometry(0,59,753,1);
    ele_divider->setStyleSheet("background:rgb(229,229,229)");
    QFrame *ele_icon = new QFrame(this);
    ele_icon->setGeometry(2,4,40,40);
    ele_icon->setStyleSheet("background-image:url(:/Icon/MainWidget/Cell/ele_icon.png)");
    QLabel *ele_text = new QLabel(this);
    ele_text->setGeometry(52,10,167,14);
    ele_text->setText(m_taskName);
    ele_text->setStyleSheet("position: absolute;color: rgb(38, 38, 38);"
                            "font-family: 微软雅黑;font-size: 14px;font-weight: 500;"
                            "line-height: 20px;text-align: left");
    ele_text -> setAttribute(Qt::WA_TranslucentBackground);
    QWidget *ele_extra = new QWidget(this);
    ele_extra->setGeometry(682,5,60,22);
    ele_extra->setStyleSheet(".QWidget{border: 1px solid rgb(229, 229, 229);border-radius: 4px;}");
    QLabel *ele_extra_text = new QLabel(ele_extra);
    ele_extra_text->setGeometry(7,1,50,20);
    ele_extra_text->setText(QString("企业可见"));
    ele_extra_text->setStyleSheet("position: absolute;color: rgb(140, 140, 140);"
                                  "font-family: 微软雅黑;font-size: 12px;font-weight: 400;"
                                  "line-height: 20px;text-align: left");
    // 下载条相关
    ProgressBar *ele_progress_bar = new ProgressBar(":/Icon/MainWidget/Cell/ele_progress_bar.bmp", this);
    ele_progress_bar -> setGeometry(450, 0, 220, 35);

    // do the download work here.
}
