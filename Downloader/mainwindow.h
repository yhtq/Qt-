#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "pathselect.h"
#include <QMainWindow>
#include "QPushButton"
#include "QToolButton"
#include "QLineEdit"
#include "QToolBar"
#include "QAction"
#include "downloadbar.h"
#include "QProgressBar"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void SetMainWindow();

    QToolButton* user_login;
    QLineEdit* line_edit;
    QToolButton* download;
    QFrame *line;
    QToolButton* left_download;

    void SetLogin();
    void SetLineEdit();
    void SetDownLoad();
    void SetLine();
    void SetOtherButtons();

    PathSelect* path_select;

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
