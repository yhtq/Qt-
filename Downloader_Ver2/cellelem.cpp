#include "cellelem.h"
#include "QDebug"
extern QFutureSynchronizer<void> sync;
CellElem::CellElem(const QString &taskName, Downloader &d, QListWidgetItem *item, QWidget *parent)
    : QWidget{parent},
      m_taskName(taskName)
{
    QWidget *ele_divider = new QWidget(this);
    ele_divider->setGeometry(0,68,773,1);
    ele_divider->setStyleSheet("background:rgb(229,229,229)");
    QFrame *ele_icon = new QFrame(this);
    ele_icon->setGeometry(13,13,43,43);
    ele_icon->setStyleSheet("background-image:url(:/Icon/MainWidget/ChildWidget1/Cell/ele_icon.png);border-radius:9px");
    QLabel *ele_text = new QLabel(this);
    ele_text->setGeometry(70,15,167,20);
    ele_text->setText(m_taskName);
    ele_text->setStyleSheet("position: absolute;color: rgb(50, 50, 50);"
                            "font-family: 微软雅黑;font-size: 15px;font-weight: 500;"
                            "line-height: 20px;text-align: left");
    ele_text -> setAttribute(Qt::WA_TranslucentBackground);
    QWidget *ele_extra = new QWidget(this);
    ele_extra->setGeometry(710,2,60,22);
    ele_extra->setStyleSheet(".QWidget{border: 1px solid rgb(229, 229, 229);border-radius: 4px;}");
    QLabel *ele_extra_text = new QLabel(ele_extra);
    ele_extra_text->setGeometry(7,1,50,20);
    ele_extra_text->setText(QString("视频下载"));
    ele_extra_text->setStyleSheet("position: absolute;color: rgb(140, 140, 140);"
                                  "font-family: 微软雅黑;font-size: 12px;font-weight: 400;"
                                  "line-height: 20px;text-align: left");
    // 下载条相关
    ProgressBar *ele_progress_bar = new ProgressBar(":/Icon/MainWidget/ChildWidget1/Cell/ele_progress_bar.bmp", this);
    ele_progress_bar -> setGeometry(470, 15, 220, 35);

    QLabel *download_rate = new QLabel(this);
    download_rate->setGeometry(400,22,70,20);
    download_rate->setText(QString("0 KB/s"));
    download_rate->setStyleSheet("position: absolute;color: rgb(80, 80, 80);"
                                 "font-family: 微软雅黑;font-size: 12px;font-weight: 400;"
                                 "line-height: 20px;text-align: left");

    // do the download work here.
    QObject::connect(&d, &Downloader::download_progress, download_rate, [=,&d](int cur_byte, int last_byte) {
        int temp_time = time(0);
        static int cur_time = temp_time;
        static long long last = cur_byte;
        if (temp_time - cur_time > 1)
        {
            //qDebug() << "当前1下载进度：" << cur_byte << "/" << d.getSize();
            //qDebug() << "当前1下载速度：" << (cur_byte - last) / 1024 / (temp_time - cur_time) << "KB/s";

            int rate = (cur_byte - last) / 1024 / (temp_time - cur_time);
            QString c_rate = QString::number(rate);
            c_rate.append(" KB/s");
            download_rate->setText(c_rate);

            cur_time = temp_time;
            last = cur_byte;
        }
    });
    double size = d.getSize();
    QObject::connect(&d, &Downloader::download_progress, ele_progress_bar,[=](int cur, int last){ele_progress_bar->setValue(cur*100/size);});
    bool valid;
    QFuture<void>& future = d.start_download(valid);
    sync.addFuture(future);
    //QObject::connect(d_p, &Downloader::finish, [d_p]{d_p->deleteLater();});

    connect(&d,&Downloader::finish,this,&CellElem::finished);
    //d_p->deleteLater();
    //future.waitForFinished();
}
