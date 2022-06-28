#include "mainwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidget w;
    w.show();
    a.setWindowIcon(QIcon(":/Icon/logo.png"));
    return a.exec();
}
