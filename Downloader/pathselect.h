#ifndef PATHSELECT_H
#define PATHSELECT_H

#include <QWidget>

namespace Ui {
class PathSelect;
}

class PathSelect : public QWidget
{
    Q_OBJECT

public:
    explicit PathSelect(QWidget *parent = nullptr);
    ~PathSelect();

private slots:
    void on_setPath_clicked();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::PathSelect *ui;
};

#endif // PATHSELECT_H
