#include "toolwidget.h"
#include "QMouseEvent"

ToolWidget::ToolWidget(QWidget *parent) : QWidget(parent)
{
    setAttribute(Qt::WA_StyledBackground,true);
}

void ToolWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        m_bDrag = true;
        mouseStartPoint = event->globalPos();
    }
}

void ToolWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        m_bDrag = false;
        if(mouseStartPoint == event->globalPos()) emit Widget_clicked();
    }
}
