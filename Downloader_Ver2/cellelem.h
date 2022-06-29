#ifndef CELLELEM_H
#define CELLELEM_H
#include <QWidget>
#include <QLabel>
#include <QFrame>
#include <QListWidgetItem>
#include "progressbar.h"
#include "downloader.h"
#include "get.h"

class CellElem : public QWidget
{
    Q_OBJECT
public:
    explicit CellElem(const QString &, const QString &, const QString &, QListWidgetItem *item, QWidget *parent = nullptr);
    QString m_taskName;

signals:

};

#endif // CELLELEM_H
