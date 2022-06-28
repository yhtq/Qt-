#ifndef CELLELEM_H
#define CELLELEM_H
#include <QWidget>
#include <QLabel>
#include <QFrame>
#include "progressbar.h"

class CellElem : public QWidget
{
    Q_OBJECT
public:
    explicit CellElem(const QString&, QWidget *parent = nullptr);
    QString m_taskName;

signals:

};

#endif // CELLELEM_H
