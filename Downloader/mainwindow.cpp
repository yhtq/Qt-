#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pathselect.h"
#include "QPushButton"
#include "QToolButton"
#include "QLineEdit"
#include "QToolBar"
#include "QAction"
#include "downloadbar.h"
#include "QProgressBar"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    SetMainWindow();
    SetLogin();
    SetLineEdit();
    SetDownLoad();
    SetLine();
    SetOtherButtons();

//    DownloadBar* download_bar = new DownloadBar();
//    download_bar->setParent(this);
//    download_bar->show();

    // Just for Test
    QToolButton* dbar = new QToolButton(this);
    dbar->setGeometry(95,70,690,70);
    dbar->setStyleSheet("QToolButton{background-color:rgba(191,213,217,50);border-style:inset}");

    QToolButton* btn2 = new QToolButton(dbar);
    btn2->setGeometry(10,10,300,50);
    btn2->setStyleSheet("QToolButton{background-color:rgba(191,213,217,0)}");
    btn2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    btn2->setIcon(QIcon(":/Icons/21021411.jpg"));
    btn2->setIconSize(QSize(40,40));

    QFont* btn2_font = new QFont;
    btn2_font->setPointSize(10);
    btn2_font->setFamily(("黑体"));
    btn2->setFont(*btn2_font);
    btn2->setText("    爱你，就多判你一年");

    QProgressBar* progress_bar = new QProgressBar(dbar);
    progress_bar->setGeometry(480,20,200,30);
    progress_bar->setMinimum(0);
    progress_bar->setMaximum(100);
    progress_bar->setValue(47);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetMainWindow()
{
    //窗口设置
    this->setWindowIcon(QIcon(":/Icons/21021411.jpg"));
    this->setWindowTitle("Bilibili Downloader!");
    this->setFixedSize(800,495);

    //窗口背景颜色
    this->setPalette(QPalette(Qt::white));
}

void MainWindow::SetLogin()
{
    //登录按钮
    user_login = new QToolButton(this);
    user_login->setGeometry(15, 10, 60, 50);
    user_login->setText("登录");

    QFont* user_login_font = new QFont;
    user_login_font->setPointSize(16);
    user_login_font->setFamily(("宋体"));
    user_login->setFont(*user_login_font);

    user_login->setStyleSheet("QToolButton{color:rgba(0,154,170,255);background-color:rgba(255,255,255,0)}"
                              "QToolButton::hover{background-color:rgba(0,0,0,0)}"
                              "QToolButton::pressed{background-color:rgba(0,0,0,0)}");
}

void MainWindow::SetLineEdit()
{
    //输入框
    line_edit = new QLineEdit(this);
    line_edit->setGeometry(290, 10, 450, 45);

    //设置背景提示字
    line_edit->setPlaceholderText("TestTest.");

    //设置输入框字体属性
    QFont* line_edit_font = new QFont;
    line_edit_font->setPointSize(10);
    line_edit_font->setFamily(("宋体"));
    line_edit->setFont(*line_edit_font);
}

void MainWindow::SetDownLoad()
{
    //下载按钮
    download = new QToolButton(this);
    download->setGeometry(740, 10, 45, 45);
    download->setIcon(QIcon(":/Icons/download.svg"));
    download->setIconSize(QSize(30,30));

    download->setStyleSheet("QToolButton{background-color:rgba(255,255,255,0)}"
                            "QToolButton::hover{background-color:rgba(0,0,0,30)}"
                            "QToolButton::pressed{background-color:rgba(0,0,0,50)}");

    path_select = new PathSelect;

    connect(download,&QToolButton::clicked , path_select, [=](){
        path_select->show();
    });
}

void MainWindow::SetLine()
{
    //分割线
    line = new QFrame(this);
    line->setGeometry(QRect(80, 70, 10, 408));
    line->setFrameShape(QFrame::VLine);
    line->setFrameShadow(QFrame::Sunken);
    line->raise();
}

void MainWindow::SetOtherButtons()
{
    //额外的一些按钮
    left_download = new QToolButton(this);
    left_download->setGeometry(15, 70, 65, 65);
    left_download->setIcon(QIcon(":/Icons/download.svg"));
    left_download->setIconSize(QSize(40,40));

    left_download->setStyleSheet("QToolButton{background-color:rgba(255,255,255,0)}"
                                 "QToolButton::hover{background-color:rgba(0,0,0,50)}"
                                 "QToolButton::pressed{background-color:rgba(0,0,0,50)}");
}
