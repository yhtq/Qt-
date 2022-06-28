#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_StyledBackground,true);

    Init_Widget();
    Init_Top();
    Init_SideBar();
    Init_ChildWidget1();
    Init_ChildWidget2();
    Init_DownloadCell();
    childWidget2->close();

    //分割线
    QWidget *divider = new QWidget(this);
    divider->setGeometry(1,41,1078,1);
    divider->setStyleSheet("background:rgb(245,245,245)");
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
    top->setGeometry(1,1,1078,40);
    top->setStyleSheet("background:rgb(191,244,248)");

    //登录按钮
    QPushButton *logo = new QPushButton(top);
    logo->setGeometry(20,10,24,20);
    logo->setIcon(QIcon(":/Icon/MainWidget/Top/logo_icon.png"));
    logo->setStyleSheet("border:0px");

    QLabel *title = new QLabel(top);
    title->setGeometry(57,7,312,24);
    title->setText(QString("bilibili Downloader!!!"));
    title->setStyleSheet("position: absolute;color: rgb(60, 60, 60);"
                         "font-family: 微软雅黑;font-size: 16px;font-weight: 480;"
                         "line-height: 24px;text-align: left");
    connect(logo,&QPushButton::clicked,logo,[=]{
        LoginDialog *log = new LoginDialog;
        log->exec();
    });


    //最小化和关闭按钮
    QWidget *widget_control = new QWidget(top);
    widget_control->setGeometry(920,0,160,40);
    widget_control->setStyleSheet("background:rgb(235,235,235)");
    QPushButton *widget_minimize = new QPushButton(widget_control);
    widget_minimize->setGeometry(0,0,80,40);
    widget_minimize->setIcon(QIcon(":/Icon/MainWidget/Top/minimize.png"));
    widget_minimize->setStyleSheet("QPushButton{background:rgb(255,255,255);border:0px}"
                                   "QPushButton:hover{background:rgb(245,245,245);border:0px}"
                                   "QPushButton:pressed{background:rgb(235,235,235);border:0px}");
    connect(widget_minimize,&QPushButton::clicked,widget_minimize,[=]{
       this->showMinimized();
    });

    QPushButton *widget_close = new QPushButton(widget_control);
    widget_close->setGeometry(80,0,80,40);
    widget_close->setIcon(QIcon(":/Icon/MainWidget/Top/close.png"));
    widget_close->setStyleSheet("QPushButton{background:rgb(255,255,255);border:0px}"
                                "QPushButton:hover{background:rgb(245,245,245);border:0px}"
                                "QPushButton:pressed{background:rgb(235,235,235);border:0px}");
    connect(widget_close,&QPushButton::clicked,widget_close,[=]{

        CloseDialog *log = new CloseDialog;
        int opt = log->exec();
        if(opt == QDialog::Accepted) this->close();
    });
}

void MainWidget::Init_SideBar()
{
    //侧栏
    sideBar = new QWidget(this);
    sideBar->setObjectName("sideBar");
    sideBar->setGeometry(21,87,211,259);
    sideBar->setStyleSheet("#sideBar{background:rgb(255,255,255);border:1px solid rgb(235,235,235)}");

    //分割线
    QWidget *divider = new QWidget(sideBar);
    divider->setGeometry(6,88,197,1);
    divider->setStyleSheet("background:rgb(229,229,229)");

    //按钮选项
    ToolWidget *btn1 = new ToolWidget(sideBar);
    btn1->setGeometry(1,1,209,40);
    btn1->setStyleSheet("background:rgb(237,247,255)");
    QFrame *icon1 = new QFrame(btn1);
    icon1->setGeometry(16,10,20,20);
    icon1->setStyleSheet("background-image:url(:/Icon/MainWidget/SideBar/icon1.png)");
    QLabel *text1 = new QLabel(btn1);
    text1->setGeometry(44,10,110,20);
    text1->setText(QString("b站资源下载"));
    text1->setStyleSheet("position: absolute;color: rgb(120, 120, 120);"
                         "font-family: 微软雅黑;font-size: 14px;font-weight: 450;"
                         "line-height: 20px;text-align: left");

    ToolWidget *btn2 = new ToolWidget(sideBar);
    btn2->setGeometry(1,41,209,40);
    btn2->setStyleSheet("background:rgb(255,255,255)");
    QFrame *icon2 = new QFrame(btn2);
    icon2->setGeometry(16,10,20,20);
    icon2->setStyleSheet("background-image:url(:/Icon/MainWidget/SideBar/icon2.png)");
    QLabel *text2 = new QLabel(btn2);
    text2->setGeometry(44,10,110,20);
    text2->setText(QString("下载音频播放"));
    text2->setStyleSheet("position: absolute;color: rgb(120, 120, 120);"
                         "font-family: 微软雅黑;font-size: 14px;font-weight: 400;"
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
    btn_help->setGeometry(1,98,209,40);
    btn_help->setStyleSheet("background:rgb(255,255,255)");
    QFrame *icon_help = new QFrame(btn_help);
    icon_help->setGeometry(16,10,20,20);
    icon_help->setStyleSheet("background-image:url(:/Icon/MainWidget/SideBar/icon_.png)");
    QLabel *text_help = new QLabel(btn_help);
    text_help->setGeometry(44,10,110,20);
    text_help->setText(QString("帮助"));
    text_help->setStyleSheet("position: absolute;color: rgb(120, 120, 120);"
                         "font-family: 微软雅黑;font-size: 14px;font-weight: 400;"
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
    btn_set->setGeometry(1,138,209,40);
    btn_set->setStyleSheet("background:rgb(255,255,255)");
    QFrame *icon_set = new QFrame(btn_set);
    icon_set->setGeometry(16,10,20,20);
    icon_set->setStyleSheet("background-image:url(:/Icon/MainWidget/SideBar/icon_set.png)");
    QLabel *text_set = new QLabel(btn_set);
    text_set->setGeometry(44,10,110,20);
    text_set->setText(QString("应用设置"));
    text_set->setStyleSheet("position: absolute;color: rgb(120, 120, 120);"
                            "font-family: 微软雅黑;font-size: 14px;font-weight: 400;"
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
}

void MainWidget::Init_ChildWidget1()
{
    childWidget1 = new QWidget(this);
    childWidget1->setGeometry(256,88,802,168);

    //SearchBar
    QWidget *bar = new QWidget(childWidget1);
    bar->setGeometry(0,0,802,80);
    bar->setStyleSheet("background:rgb(255,255,255)");

    Line_Edit *search_bar = new Line_Edit(bar,30,4);
    //下载按钮
    QPushButton *down_load = new QPushButton(childWidget1);
    down_load->setGeometry(572,4,50,50);
    down_load->setStyleSheet("QPushButton{background: rgb(255, 255, 255);background-image:url(:/Icon/logo_.png);border-radius: 16px;}"
                             "QPushButton:hover{background: rgb(240, 240, 240);background-image:url(:/Icon/logo_.png)}"
                             "QPushButton:pressed{background: rgb(230, 230, 230);background-image:url(:/Icon/logo_.png)}");
    connect(down_load, &QToolButton::clicked, this, [=]{
        QString url = search_bar -> line_edit ->text();
        QString path = QFileDialog::getExistingDirectory(this, "选择保存位置", ".");
        if (path.isEmpty()) {
            QMessageBox::warning(this, "提示", "请选择下载文件保存位置！");
            return ;
        }

        // do the downloading work

        CellElem *ele = new CellElem("test", downloadCell);
        QListWidgetItem *item = new QListWidgetItem(downloadCell, 0);
        item -> setSizeHint(QSize(752, 54));
        downloadCell -> setItemWidget(item, ele);
    });
//    QWidget *cell = new QWidget(childWidget1);
//    cell->setGeometry(0,100,802,426);
//    cell->setStyleSheet("background:rgb(255,255,255)");

//    CellElem *ele = new CellElem("test", cell);
//    ele->setGeometry(0,0,802,49);
}

void MainWidget::Init_DownloadCell()
{
    downloadCell = new QListWidget(this);
    downloadCell -> setGeometry(256, 180, 772, 426);
    downloadCell -> setStyleSheet("background:rgb(255,255,255)");
    downloadCell -> setFrameShape(QListWidget::NoFrame);
}

void MainWidget::Init_ChildWidget2()
{
    childWidget2 = new QWidget(this);
    childWidget2->setGeometry(256,88,802,506);
    childWidget2->setStyleSheet("background:rgb(230,230,230)");
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
