#include "mainwidget.h"

#include <QApplication>
QFutureSynchronizer<void> sync;
int main(int argc, char *argv[])
{
    qputenv("QT_SCALE_FACTOR", "0.8");
    QApplication a(argc, argv);
    MainWidget w;
    w.show();
    a.setWindowIcon(QIcon(":/Icon/logo.png"));
    //sync.addFuture(QtConcurrent::run([&a]{a.exec();}));
    //sync.waitForFinished();
    return a.exec();
}
