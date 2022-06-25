#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class QMouseEvent;
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void Init_Widget();
    void Init_Top();
    void Init_SideBar();
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
#endif // WIDGET_H
