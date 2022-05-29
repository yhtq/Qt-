#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pathselect.h"
#include "QPushButton"
#include "QToolButton"
#include "QLineEdit"
#include "QToolBar"
#include "QAction"

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
    user_login->setGeometry(10, 10, 60, 50);
    user_login->setText("登录");

    QFont* user_login_font = new QFont;
    user_login_font->setPointSize(14);
    user_login_font->setFamily(("宋体"));
    user_login->setFont(*user_login_font);

    //    user_login->setStyleSheet("background-color:#FFFFFF");
    //    user_login->setPopupMode(QToolButton::DelayedPopup);
    //    user_login->setAutoRaise(user_login);
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
    download = new QPushButton(this);
    download->setGeometry(740, 10, 45, 45);
    download->setIcon(QIcon(":/Icons/download.svg"));

    download->setStyleSheet("background-color:#FFFFFF");
//    download->setPopupMode(QToolButton::DelayedPopup);
//    download->setAutoRaise(download);

    path_select = new PathSelect;

    connect(download,&QPushButton::clicked , path_select, [=](){
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
}
