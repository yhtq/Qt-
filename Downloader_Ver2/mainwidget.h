#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "QMouseEvent"
#include "QFrame"
#include "QLabel"
#include "toolwidget.h"
#include "line_edit.h"
#include "QPushButton"
#include "QToolButton"
#include "closedialog.h"
#include "logindialog.h"
#include "helpdialog.h"
#include "QDebug"
#include "progressbar.h"
#include "cellelem.h"
#include <QFileDialog>
#include <QListWidget>
#include <QMessageBox>
#include <QMenu>
#include "downloader.h"
#include "get.h"
#include "QMap"
#include "downloaddialog1.h"
#include "downloaddialog2.h"
#include "QDir"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class QMouseEvent;
class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

    void Init_Widget();
    void Init_Top();
    void Init_SideBar();
    void Init_ChildWidget1();
    void Init_ChildWidget2();
    void Init_DownloadCell();

    QString default_path;

protected:
    //拖拽窗口
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    Ui::Widget *ui;

    bool m_bDrag;
    QPoint mouseStartPoint;
    QPoint windowTopLeftPoint;

    QWidget *childWidget1, *childWidget2;
    QWidget *top, *sideBar;
    QListWidget *downloadCell;
    QMenu *popMenu;
    QPushButton *menu;
    bool menu_state;

private slots:
    void onCustomContextMenuRequested(QPoint);
};
#endif //  MAINWIDGET_H
