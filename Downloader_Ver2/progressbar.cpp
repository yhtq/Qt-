#include "progressbar.h"
#include <QHBoxLayout>

ProgressBar::ProgressBar(const QString &fileName, QWidget *parent):
    QWidget(parent),
    progBar(this),
    progValue(this),
    progImage(fileName)
{

    progBar.setMaximum(100);
    progBar.setMinimum(0);
    progBar.setValue(0);
    progBar.setTextVisible(false);
    progBar.setFixedHeight(15);

    progValue.setText(QString("%1%").arg(progBar.value()));
//    progValue.setAlignment(Qt::AlignRight|Qt::AlignVCenter);
//    progValue.setMinimumWidth(25);

    QHBoxLayout* hlayout = new QHBoxLayout();
    hlayout -> addWidget(&progBar);
    hlayout -> addWidget(&progValue);
    setLayout(hlayout);

    connect(&progBar, &QProgressBar::valueChanged, this, &ProgressBar::onValueChanged);

    onValueChanged(progBar.value());
}

void ProgressBar::setValue(int value) {
    progBar.setValue(value);
}

void ProgressBar::onValueChanged(int value)
{
    QString qss = "QProgressBar{"
               "border: 1px solid rgb(16, 135, 209);"
               "background: rgba(248,248,255,180);"
               "border-radius: 6px; }"
               "QProgressBar::chunk:enabled {"
               "border-radius: 4px; "
               "background: qlineargradient(x1:0, y1:0, x2:1, y2:0" ;

    double v = progBar.maximum();
    double endColour = static_cast<double>(value) / v ;    //获取比例

    for (int i = 0; i < 100; i++)
    {
         double cur = endColour * i / 100.0;
         QRgb rgb = progImage.pixel((progImage.width()-1) * cur,progImage.height() / 2);
         QColor c(rgb);
         qss.append(QString(",stop:%1  rgb(%2,%3,%4)").arg(i/100.0).arg(c.red()).arg(c.green()).arg(c.blue()));
    }

    qss.append(");}");
    progBar.setStyleSheet(qss);
    progValue.setText(QString("%1%").arg(progBar.value()));
}
