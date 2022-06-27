#include "toolwidget.h"
#include "QMouseEvent"
#include "QDebug"

ToolWidget::ToolWidget(QWidget *parent) : QWidget(parent)
{
    setAttribute(Qt::WA_StyledBackground,true);

    this->setAttribute(Qt::WA_Hover, true);//开启悬停事件
    this->installEventFilter(this);       //安装事件过滤器
}

void ToolWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        m_bDrag = true;
        mouseStartPoint = event->globalPos();
        emit Widget_mousePressed();
    }
}

void ToolWidget::mouseMoveEvent(QMouseEvent *event)
{
    //qDebug() << 1;
}

void ToolWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        m_bDrag = false;
        if(mouseStartPoint == event->globalPos()) emit Widget_clicked();
        emit Widget_mouseReleased();
    }
}

bool ToolWidget::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::HoverEnter)
    {
        emit hoverEnter();
        return true;
    }
    else if (event->type() == QEvent::HoverLeave)
    {
        emit hoverLeave();
        return true;
    }

    return QWidget::eventFilter(obj, event);
}
