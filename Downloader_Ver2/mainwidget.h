#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

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
    void Init_SearchBar();
    void Init_Cell();

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

    QWidget *top, *sideBar, *cell;
};
#endif //  MAINWIDGET_H
