#ifndef TOOLWIDGET_H
#define TOOLWIDGET_H

#include <QWidget>

class QMouseEvent;
class ToolWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ToolWidget(QWidget *parent = nullptr);

signals:
    void Widget_clicked();
    void hoverEnter();
    void hoverLeave();
    void Widget_mousePressed();
    void Widget_mouseReleased();

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    bool eventFilter(QObject *object, QEvent *event);

    bool m_bDrag;

    QPoint mouseStartPoint;
};

#endif // TOOLWIDGET_H
