#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_StyledBackground,true);

    QDir dir;
    QString userName = dir.home().dirName();
    default_path = "C:/Users/";
    default_path.append(userName);
    default_path.append("/Desktop");

    Init_Widget();
    Init_Top();
    Init_SideBar();
    Init_ChildWidget1();
    Init_ChildWidget2();
    Init_DownloadCell();
    childWidget2->close();

    //分割线
    QWidget *divider = new QWidget(this);
    divider->setGeometry(1,31,1078,1);
    divider->setStyleSheet("background:rgb(245,245,245)");
    menu_state = 0;

}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::Init_Widget()
{
    this->setWindowFlags(Qt::FramelessWindowHint);//设置无窗口框架边界
    //this->setAttribute();//设置背景透明

    this->resize(1080,720);
    this->setStyleSheet(".MainWidget{background:rgb(255,255,255);border:1px solid rgb(200,200,200)}");
}

void MainWidget::Init_Top()
{
    top = new QWidget(this);
    top->setGeometry(1,1,1078,30);
    //top->setStyleSheet("background:rgb(191,244,248)");
    top->setStyleSheet("background:rgb(136,178,210)");

    //登录按钮
    QPushButton *logo = new QPushButton(top);
    logo->setGeometry(20,5,24,20);
    logo->setIcon(QIcon(":/Icon/MainWidget/Top/logo_icon.png"));
    logo->setStyleSheet("border:0px");

    QLabel *title = new QLabel(top);
    title->setGeometry(57,2,312,24);
    title->setText(QString("bilibili Downloader!!!"));
    title->setStyleSheet("position: absolute;color: rgb(20, 20, 20);"
                         "font-family: 微软雅黑;font-size: 16px;font-weight: 480;"
                         "line-height: 24px;text-align: left");
    connect(logo,&QPushButton::clicked,logo,[=]{
        LoginDialog *log = new LoginDialog;
        log->exec();
    });


    //最小化和关闭按钮
    QWidget *widget_control = new QWidget(top);
    widget_control->setGeometry(920,0,160,30);
    widget_control->setStyleSheet("background:rgb(250,250,250)");
    QPushButton *widget_minimize = new QPushButton(widget_control);
    widget_minimize->setGeometry(0,0,80,30);
    widget_minimize->setIcon(QIcon(":/Icon/MainWidget/Top/minimize.png"));
    widget_minimize->setStyleSheet("QPushButton{background:rgb(250,250,250);border:0px}"
                                   "QPushButton:hover{background:rgb(240,240,240);border:0px}"
                                   "QPushButton:pressed{background:rgb(230,230,230);border:0px}");
    connect(widget_minimize,&QPushButton::clicked,widget_minimize,[=]{
       this->showMinimized();
    });

    QPushButton *widget_close = new QPushButton(widget_control);
    widget_close->setGeometry(80,0,80,30);
    widget_close->setIcon(QIcon(":/Icon/MainWidget/Top/close.png"));
    widget_close->setStyleSheet("QPushButton{background:rgb(250,250,250);border:0px}"
                                "QPushButton:hover{background:rgb(240,240,240);border:0px}"
                                "QPushButton:pressed{background:rgb(230,230,230);border:0px}");
    connect(widget_close,&QPushButton::clicked,widget_close,[=]{
        CloseDialog *log = new CloseDialog;
        int opt = log->exec();
        if(opt == QDialog::Accepted) this->close();
    });
}

void MainWidget::Init_SideBar()
{
    //菜单按钮
    menu = new QPushButton(this);
    menu->setGeometry(15,40,40,40);
    menu->setStyleSheet(".QPushButton{background:rgb(255,255,255);border:0px;border-radius:4px}"
                        "QPushButton::hover{background:rgb(240,240,240);border-radius:4px}"
                        "QPushButton::pressed{background:rgb(230,230,230);border-radius:4px}");
    QFrame *menu_icon = new QFrame(menu);
    menu_icon->setGeometry(4,4,36,36);
    menu_icon->setStyleSheet("background-image:url(:/Icon/MainWidget/SideBar/menu.png)");

    //侧栏
    sideBar = new QWidget(this);
    sideBar->setObjectName("sideBar");
    sideBar->setGeometry(15,80,211,209);
    sideBar->setStyleSheet("#sideBar{background:rgb(255,255,255);border:1px solid rgb(235,235,235)}");

    //分割线
    QWidget *divider = new QWidget(sideBar);
    divider->setGeometry(1,102,209,1);
    divider->setStyleSheet("background:rgb(229,229,229)");

    //按钮选项
    ToolWidget *btn1 = new ToolWidget(sideBar);
    btn1->setGeometry(1,1,209,50);
    btn1->setStyleSheet("background:rgb(237,247,255)");
    QFrame *icon1 = new QFrame(btn1);
    icon1->setGeometry(13,10,24,24);
    icon1->setStyleSheet("background-image:url(:/Icon/MainWidget/SideBar/icon1.png)");
    QLabel *text1 = new QLabel(btn1);
    text1->setGeometry(54,6,110,30);
    text1->setText(QString("b站资源下载"));
    text1->setStyleSheet("position: absolute;color: rgb(100, 100, 100);"
                         "font-family: 微软雅黑;font-size: 16px;font-weight: 450;"
                         "line-height: 20px;text-align: left");

    ToolWidget *btn2 = new ToolWidget(sideBar);
    btn2->setGeometry(1,51,209,50);
    btn2->setStyleSheet("background:rgb(255,255,255)");
    QFrame *icon2 = new QFrame(btn2);
    icon2->setGeometry(13,10,24,24);
    icon2->setStyleSheet("background-image:url(:/Icon/MainWidget/SideBar/icon2.png)");
    QLabel *text2 = new QLabel(btn2);
    text2->setGeometry(52,5,110,30);
    text2->setText(QString("下载音频播放"));
    text2->setStyleSheet("position: absolute;color: rgb(100, 100, 100);"
                         "font-family: 微软雅黑;font-size: 16px;font-weight: 450;"
                         "line-height: 20px;text-align: left");

    connect(btn1,&ToolWidget::Widget_mouseReleased,btn1,[=]{
        btn1->setStyleSheet("background:rgb(237,247,255)");
        btn2->setStyleSheet("background:rgb(255,255,255)");

        childWidget2->close();
        childWidget1->show();
    });
    connect(btn2,&ToolWidget::Widget_mouseReleased,btn2,[=]{
        btn1->setStyleSheet("background:rgb(255,255,255)");
        btn2->setStyleSheet("background:rgb(237,247,255)");

        childWidget1->close();
        childWidget2->show();
    });

    //Help Button
    ToolWidget *btn_help = new ToolWidget(sideBar);
    btn_help->setGeometry(1,108,209,50);
    btn_help->setStyleSheet("background:rgb(255,255,255)");
    QFrame *icon_help = new QFrame(btn_help);
    icon_help->setGeometry(13,10,24,24);
    icon_help->setStyleSheet("background-image:url(:/Icon/MainWidget/SideBar/icon_help.png)");
    QLabel *text_help = new QLabel(btn_help);
    text_help->setGeometry(54,5,110,30);
    text_help->setText(QString("Help"));
    text_help->setStyleSheet("position: absolute;color: rgb(100, 100, 100);"
                         "font-family: 微软雅黑;font-size: 16px;font-weight: 450;"
                         "line-height: 20px;text-align: left");
    //HoverEnter Event
    connect(btn_help,&ToolWidget::hoverEnter,btn_help,[=]{
        btn_help->setStyleSheet("background:rgb(245,245,245)");
    });
    //HoverLeave Event
    connect(btn_help,&ToolWidget::hoverLeave,btn_help,[=]{
        btn_help->setStyleSheet("background:rgb(255,255,255)");
    });
    //Pressed Event
    connect(btn_help,&ToolWidget::Widget_mousePressed,btn_help,[=]{
        btn_help->setStyleSheet("background:rgb(235,235,235)");
    });
    //Released Event
    connect(btn_help,&ToolWidget::Widget_mouseReleased,btn_help,[=]{
        btn_help->setStyleSheet("background:rgb(245,245,245)");
    });
    //Eject the Dialog
    connect(btn_help,&ToolWidget::Widget_mouseReleased,this,[=]{
        HelpDialog *help = new HelpDialog;
        help->show();
        help->exec();
    });

    //Setting Button
    ToolWidget *btn_set = new ToolWidget(sideBar);
    btn_set->setGeometry(1,158,209,50);
    btn_set->setStyleSheet("background:rgb(255,255,255)");
    QFrame *icon_set = new QFrame(btn_set);
    icon_set->setGeometry(13,10,24,24);
    icon_set->setStyleSheet("background-image:url(:/Icon/MainWidget/SideBar/icon_set.png)");
    QLabel *text_set = new QLabel(btn_set);
    text_set->setGeometry(54,5,110,30);
    text_set->setText(QString("Setting"));
    text_set->setStyleSheet("position: absolute;color: rgb(100, 100, 100);"
                            "font-family: 微软雅黑;font-size: 16px;font-weight: 450;"
                            "line-height: 20px;text-align: left");
    //HoverEnter Event
    connect(btn_set,&ToolWidget::hoverEnter,btn_set,[=]{
        btn_set->setStyleSheet("background:rgb(245,245,245)");
    });
    //HoverLeave Event
    connect(btn_set,&ToolWidget::hoverLeave,btn_set,[=]{
        btn_set->setStyleSheet("background:rgb(255,255,255)");
    });
    //Pressed Event
    connect(btn_set,&ToolWidget::Widget_mousePressed,btn_set,[=]{
        btn_set->setStyleSheet("background:rgb(235,235,235)");
    });
    //Released Event
    connect(btn_set,&ToolWidget::Widget_mouseReleased,btn_set,[=]{
        btn_set->setStyleSheet("background:rgb(245,245,245)");
    });

    //链接菜单按钮和侧栏
    connect(menu,&QPushButton::clicked,this,[=]{
        if(menu_state == 0)
        {
            menu_state = 1;
            sideBar->close();
        }
        else
        {
            menu_state = 0;
            sideBar->show();
        }
    });

    //设置框
    connect(btn_set, &ToolWidget::Widget_mouseReleased, [=]{
        QDialog *setting_dialog = new QDialog(this);
        setting_dialog->resize(550,300);
        setting_dialog->setWindowTitle("Setting");
        setting_dialog->setStyleSheet("background:rgb(255,255,255)");
        setting_dialog->deleteLater();
        QLineEdit *path_edit = new QLineEdit(setting_dialog);
        path_edit->setGeometry(80,30,300,30);
        path_edit->setPlaceholderText(default_path);
        path_edit->setStyleSheet("position: absolute;color: rgb(140, 140, 140);"
                                 "font-family: 微软雅黑;font-size: 14px;font-weight: 450;"
                                 "line-height: 20px;text-align: left");

        QFont font = this->font();
        font.setPointSize(11);
        font.setFamily("微软雅黑");

        QPushButton *get_path = new QPushButton(setting_dialog);
        get_path->setGeometry(380,30,60,30);
        get_path->setText(QString("File"));
        get_path->setFont(font);
        get_path->setStyleSheet("QPushButton{background: rgb(245, 245, 245);border-radius: 0px;border:1px solid rgb(205,205,205)}"
                                "QPushButton:hover{background: rgb(235, 235, 235)}"
                                "QPushButton:pressed{background: rgb(225, 225, 225);border:1px solid rgb(225,225,225)}");
        connect(get_path, &QPushButton::clicked, [=]{
            auto path = QFileDialog::getExistingDirectory(this, QString(), path_edit->text());
            if (!path.isNull()) {
                path_edit->setText(QDir::toNativeSeparators(path));
            }
        });

        QPushButton *save = new QPushButton(setting_dialog);
        save->setGeometry(440,30,60,30);
        save->setText(QString("Save"));
        save->setFont(font);
        save->setStyleSheet("QPushButton{background: rgb(245, 245, 245);border-radius: 0px;border:1px solid rgb(205,205,205)}"
                            "QPushButton:hover{background: rgb(235, 235, 235)}"
                            "QPushButton:pressed{background: rgb(225, 225, 225);border:1px solid rgb(225,225,225)}");
        connect(save, &QPushButton::clicked, [=]{
            default_path = path_edit->text();
        });
        setting_dialog->show();
        setting_dialog->exec();
    });
}

void MainWidget::Init_ChildWidget1()
{
    childWidget1 = new QWidget(this);
    childWidget1->setGeometry(256,70,802,506);

    //SearchBar
    QWidget *bar = new QWidget(childWidget1);
    bar->setGeometry(0,0,802,80);
    bar->setStyleSheet("background:rgb(255,255,255)");

    //分割线
//    QWidget *divider1 = new QWidget(bar);
//    divider1->setGeometry(0,0,1,61);
//    divider1->setStyleSheet("background:rgb(205,205,205)");
    QWidget *divider2 = new QWidget(bar);
    divider2->setGeometry(0,61,762,1);
    divider2->setStyleSheet("background:rgb(205,205,205)");

    Line_Edit *search_bar = new Line_Edit(bar,0,4);
    //下载按钮
    QPushButton *down_load = new QPushButton(bar);
    down_load->setGeometry(710,5,48,48);
    down_load->setStyleSheet("QPushButton{background: rgb(245, 245, 245);background-image:url(:/Icon/MainWidget/ChildWidget1/SearchBar/download.png);border-radius: 0px;border:1px solid rgb(235,235,235)}"
                             "QPushButton:hover{background: rgb(235, 235, 235);background-image:url(:/Icon/MainWidget/ChildWidget1/SearchBar/download.png)}"
                             "QPushButton:pressed{background: rgb(225, 225, 225);background-image:url(:/Icon/MainWidget/ChildWidget1/SearchBar/download.png);border:1px solid rgb(225,225,225)}");
    connect(down_load, &QToolButton::clicked, this, [=]{
        QString url = search_bar -> line_edit ->text();
        QString path = default_path;

        auto d_p =  new Downloader(url, path);
        auto& d = *d_p;

        QMap<QString, QString> info_video = d.get_video_info();
        QMap<QString, QString> info_page = d.get_page_info();

        //这是按顺序的嘛
        QList<QString> allKeys = info_page.keys();
        //qDebug() << allKeys.size();
        QList<QString> allValues = info_page.values();
        //qDebug() << allValues.size();

        QStringList pages;
        QMap<QString, QString> map;
        for(int i=0; i < info_page.size(); i++)
        {
            //qDebug() << allValues[i];
            //qDebug() << info_page.key(allValues[i]);
            pages << allValues[i];
            map[allValues[i]] = allKeys[i];
        }

        QString prepare_result;

        int dialog1_result, dialog2_result;
        if(info_page.size() > 1)
        {
            DownloadDialog1 *dialog1 = new DownloadDialog1(pages,this);
            dialog1_result = dialog1->exec();

            if(dialog1_result == DownloadDialog1::Accepted)
            {
                QList<QListWidgetItem*> choose_page = dialog1->selectedItems();
                //qDebug() << choose_page.size();

                if(choose_page.size()!=0)
                {
                    QString download_page = choose_page[0]->text();
                    //qDebug() << download_page;
                    d.select_page(info_page.key(download_page));

                    QMap<QString,QString> info_quality = d.get_accept_quality();
                    //qDebug() << info_quality.size();

                    DownloadDialog2 *dialog2 = new DownloadDialog2(info_quality, default_path, this);
                    dialog2_result = dialog2->exec();

                    if(dialog2_result == DownloadDialog2::Accepted)
                    {
                        QString download_quality = dialog2->Get_Choose_Quality();
                        //qDebug() << download_quality;

                        QString download_path = dialog2->Get_Choose_Path();
                        qDebug() << download_path;
                        d.change_path(download_path);

                        prepare_result = d.download_prepare(info_quality.key(download_quality));

                        //qDebug() << prepare_result;
                        //prepare_result = "视频已存在";

                        if(prepare_result == "准备下载")
                        {
                            QListWidgetItem *item = new QListWidgetItem(downloadCell, 0);
                            QWidget *box = new QWidget;
                            box->resize(800,70);
                            CellElem *ele = new CellElem(download_page, d, item, downloadCell);
                            ele->setParent(box);
                            QWidget *blank = new QWidget(box);
                            blank->setGeometry(775,0,30,70);
                            blank->setStyleSheet("background:rgb(255,255,255)");

                            item -> setSizeHint(QSize(752, 70));
                            downloadCell -> setItemWidget(item, box);

                            connect(ele,&CellElem::finished,downloadCell,[=](int result){
                                if(result == 0)
                                {
                                    QMessageBox *warning = new QMessageBox(QMessageBox::NoIcon, "下载错误", prepare_result);
                                    warning->setStyleSheet("QLabel{min-width: 120px;min-height: 50px}");
                                    QString message = "<p align='center'>";
                                    message.append("下载失败");
                                    message.append("</p >");
                                    warning->setText(message);
                                    warning->exec();
                                }
                                downloadCell->removeItemWidget(item);
                                delete item;
                            });
                        }
                        else
                        {
                            QMessageBox *warning = new QMessageBox(QMessageBox::NoIcon, "下载错误", prepare_result);
                            warning->setStyleSheet("QLabel{min-width: 120px;min-height: 50px}");
                            QString message = "<p align='center'>";
                            message.append(prepare_result);
                            message.append("</p >");
                            warning->setText(message);
                            warning->exec();
                        }
                    }
                }
            }
        }
        else
        {
            d.select_page(allKeys[0]);
            //qDebug() << allKeys[0];

            QMap<QString,QString> info_quality = d.get_accept_quality();
            //qDebug() << info_quality.size();

            DownloadDialog2 *dialog2 = new DownloadDialog2(info_quality, default_path, this);
            dialog2_result = dialog2->exec();

            if(dialog2_result == DownloadDialog2::Accepted)
            {
                QString download_quality = dialog2->Get_Choose_Quality();
                //qDebug() << download_quality;

                QString download_path = dialog2->Get_Choose_Path();
                d.change_path(download_path);

                prepare_result = d.download_prepare(info_quality.key(download_quality));

                //qDebug() << prepare_result;
                //prepare_result = "视频已存在";

                if(prepare_result == "准备下载")
                {
                    QListWidgetItem *item = new QListWidgetItem(downloadCell, 0);
                    QWidget *box = new QWidget;
                    box->resize(800,70);
                    CellElem *ele = new CellElem(allValues[0], d, item, downloadCell);
                    ele->setParent(box);
                    QWidget *blank = new QWidget(box);
                    blank->setGeometry(775,0,30,70);
                    blank->setStyleSheet("background:rgb(255,255,255)");

                    item -> setSizeHint(QSize(752, 70));
                    downloadCell -> setItemWidget(item, box);

                    connect(ele,&CellElem::finished,downloadCell,[=](int result){
                        if(result == 0)
                        {
                            QMessageBox *warning = new QMessageBox(QMessageBox::NoIcon, "下载错误", prepare_result);
                            warning->setStyleSheet("QLabel{min-width: 120px;min-height: 50px}");
                            QString message = "<p align='center'>";
                            message.append("下载失败");
                            message.append("</p >");
                            warning->setText(message);
                            warning->exec();
                        }
                        downloadCell->removeItemWidget(item);
                        delete item;
                    });
                }
                else
                {
                    QMessageBox *warning = new QMessageBox(QMessageBox::NoIcon, "下载错误", prepare_result);
                    warning->setStyleSheet("QLabel{min-width: 120px;min-height: 50px}");
                    QString message = "<p align='center'>";
                    message.append(prepare_result);
                    message.append("</p >");
                    warning->setText(message);
                    warning->exec();
                }
            }
        }

        QObject::connect(d_p, &Downloader::finish, [d_p]{d_p->deleteLater();});
    });
}

void MainWidget::Init_DownloadCell()
{
    downloadCell = new QListWidget(childWidget1);
    downloadCell -> setGeometry(0, 80, 800, 426);
    downloadCell -> setStyleSheet("QListWidget{background:rgb(255,255,255);outline:none;}"
                                  "QListWidget::item{background:rgb(250,250,250);outline:none;}");
    downloadCell -> setFrameShape(QListWidget::NoFrame);
    downloadCell -> setSelectionMode(QAbstractItemView::SingleSelection);
    // 右键菜单设置
    downloadCell -> setProperty("contextMenuPolicy", Qt::CustomContextMenu);

    popMenu = new QMenu(this);
    connect(downloadCell, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(onCustomContextMenuRequested(QPoint)));

    QAction *deleteElem = new QAction(tr("删除"));
    popMenu -> addAction(deleteElem);
    connect(deleteElem, &QAction::triggered, this, [=]{
        QList<QListWidgetItem*> items = downloadCell -> selectedItems();
        if (items.count() > 0)
        {
            // 弹出询问框
            if (QMessageBox::Yes == QMessageBox::question(this, QStringLiteral("删除任务"),
                QStringLiteral("确认删除%1项任务").arg(QString::number(items.count())), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes))
            {
                foreach(QListWidgetItem* var, items) {
                    downloadCell -> removeItemWidget(var);
                    items.removeOne(var);
                    delete var;
                }
            }
        }
    });
}

void MainWidget::Init_ChildWidget2()
{
    childWidget2 = new QWidget(this);
    childWidget2->setGeometry(256,70,802,506);
    childWidget2->setStyleSheet("background:rgb(240,240,240)");

    QLabel *text = new QLabel(childWidget2);
    text->setGeometry(320,150,200,100);
    text->setText(QString("功能暂未开放"));
    text->setStyleSheet("position: absolute;color: rgb(80, 80, 80);"
                        "font-family: 微软雅黑;font-size: 30px;font-weight: 500;"
                        "line-height: 20px;text-align: left");
}

void MainWidget::onCustomContextMenuRequested(QPoint pos) {
    popMenu -> exec(QCursor::pos());
}

//copy from https://www.cnblogs.com/MakeView660/p/10619334.html#:~:text=%E6%88%91%E4%BB%AC%E7%9F%A5%E9%81%93%EF%BC%8C%E8%A6%81%E5%AE%9E%E7%8E%B0,veEvent%E3%80%82
/* QPoint QMouseEvent::pos() const
    Returns the position of the mouse cursor, relative to the widget that received the event.
    If you move the widget as a result of the mouse event, use the global position returned by globalPos() to avoid a shaking motion.
 */

//拖拽操作
void MainWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        //qDebug() << "1" << mouseStartPoint;
        m_bDrag = true;
        //获得鼠标的初始位置
        mouseStartPoint = event->globalPos();
        //mouseStartPoint = event->pos();
        //获得窗口的初始位置
        windowTopLeftPoint = this->frameGeometry().topLeft();
    }
}

void MainWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(m_bDrag)
    {
        //qDebug() << mouseStartPoint << event->globalPos();
        //获得鼠标移动的距离
        QPoint distance = event->globalPos() - mouseStartPoint;
        //QPoint distance = event->pos() - mouseStartPoint;
        //改变窗口的位置
        this->move(windowTopLeftPoint + distance);
    }
}

void MainWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        m_bDrag = false;
    }
}
