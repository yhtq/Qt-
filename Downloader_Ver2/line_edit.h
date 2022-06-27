#ifndef LINE_EDIT_H
#define LINE_EDIT_H
#include "qlineedit.h"

class Line_Edit : public QLineEdit
{
public:
    Line_Edit(QWidget *parent = nullptr,int PX_=0,int PY_=0);

    void init();
    void setPos(int PX_,int PY_);
    void setSize(int W_,int H_);

private:
    QWidget *parent;
    int PX,PY,W,H;
};

#endif // LINE_EDIT_H
