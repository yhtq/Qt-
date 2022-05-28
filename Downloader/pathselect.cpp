#include "pathselect.h"
#include "ui_pathselect.h"
#include <QFileDialog>

PathSelect::PathSelect(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PathSelect)
{
    ui->setupUi(this);
}

PathSelect::~PathSelect()
{
    delete ui;
}

// 设置按下选择路径按钮的行为
void PathSelect::on_setPath_clicked()
{
    QString path = QFileDialog::getExistingDirectory(this, "选择保存位置", ".");
    if(!path.isEmpty()) {
        ui->savePath->setText(path);
    }
}

// 设置确定按钮的行为
void PathSelect::on_buttonBox_accepted()
{
    this->close();
}

// 设置取消按钮的行为
void PathSelect::on_buttonBox_rejected()
{
    this->close();
}

