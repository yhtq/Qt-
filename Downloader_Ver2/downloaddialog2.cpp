#include "downloaddialog2.h"
#include "qpushbutton.h"
#include "qstyle.h"
#include <QCoreApplication>
#include <QLabel>
#include <QVBoxLayout>
#include <QDir>
#include <QComboBox>
#include <QFileDialog>

DownloadDialog2::DownloadDialog2(QMap<QString, QString> qualities, QString default_path, QWidget *parent) :
    QDialog(parent)
{
    this->setWindowTitle("下载");
    this->setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);
    this->setWindowIcon(QIcon(":/Icon/logo.png"));

    QLabel * titleLabel = new QLabel("下载");
    titleLabel->setWordWrap(true);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setTextInteractionFlags(Qt::TextSelectableByMouse);
    auto titleFont = titleLabel->font();
    titleFont.setPointSize(titleFont.pointSize() + 3);
    titleLabel->setFont(titleFont);
    titleLabel->setMinimumWidth(QFontMetrics(titleFont).horizontalAdvance("++魔卡少女樱 Clear Card篇++"));

    auto mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(titleLabel);
    auto qnLayout = new QHBoxLayout;
    qnLayout->addWidget(new QLabel("画质："));

    qnComboBox = new QComboBox;
    qnComboBox->setFocusPolicy(Qt::NoFocus);
    qnComboBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);

    QList<QString> allValues = qualities.values();

    for(int i=0; i<allValues.size(); i++)
        qnComboBox->addItem(allValues[i]);

    auto qnTipLabel = new QLabel;
    auto infoIcon = style()->standardIcon(QStyle::SP_MessageBoxInformation);
    qnTipLabel->setPixmap(infoIcon.pixmap(16, 16));

    auto qnComboBoxToolTip =
        "点击 \"获取当前项画质\" 按钮来获取单个视频的画质.\n"
        "非 * 开头的为该视频可用的画质\n"
        "* 开头的画质不属于该视频, 但其他视频可能有\n"
        "注: 未登录/无会员 可能导致较高画质不可用";

    qnTipLabel->setToolTip(qnComboBoxToolTip);
    qnLayout->addWidget(qnComboBox);
    qnLayout->addWidget(qnTipLabel);
    qnLayout->addStretch(1);

    QPushButton *getQnListBtn = new QPushButton("获取当前项画质");
    getQnListBtn->setToolTip("");
    getQnListBtn->setFlat(true);
    getQnListBtn->setCursor(Qt::PointingHandCursor);
    qnLayout->addSpacing(15);
    qnLayout->addWidget(getQnListBtn);
    connect(getQnListBtn, &QPushButton::clicked, this, &DownloadDialog2::startGetCurrentItemQnList);

    mainLayout->addLayout(qnLayout);

    auto pathLayoutFrame = new QFrame;
    pathLayoutFrame->setContentsMargins(1, 1, 1, 1);
    pathLayoutFrame->setFrameStyle(QFrame::StyledPanel | QFrame::Plain);
    pathLayoutFrame->setLineWidth(1);
    pathLayoutFrame->setMidLineWidth(0);
    auto pathLayout = new QHBoxLayout(pathLayoutFrame);
    pathLayout->addWidget(new QLabel("下载到: "));
    pathLayout->setContentsMargins(2, 0, 1, 0);

    pathLabel = new QLabel(this);
    auto appDir = QDir{QCoreApplication::applicationDirPath()};
    pathLabel->setText(default_path);
    QPushButton *selPathButton = new QPushButton(this);
    selPathButton->setToolTip("选择文件夹");
    selPathButton->setIconSize(QSize(20, 20));
    selPathButton->setIcon(QIcon(":/Icon/folder.svg"));
    selPathButton->setFlat(true);
    selPathButton->setCursor(Qt::PointingHandCursor);
    selPathButton->setStyleSheet("QPushButton:pressed{border:none;}");
    pathLayout->addWidget(pathLabel, 1);
    pathLayout->addWidget(selPathButton);
    mainLayout->addWidget(pathLayoutFrame);

    auto bottomLayout = new QHBoxLayout;
    bottomLayout->addStretch(1);
    QPushButton *okButton = new QPushButton("下载");
    auto cancelButton = new QPushButton("取消");
    bottomLayout->addWidget(okButton);
    bottomLayout->addWidget(cancelButton);
    mainLayout->addLayout(bottomLayout);

    connect(okButton, &QPushButton::clicked, this, &DownloadDialog2::accept);
    connect(cancelButton, &QPushButton::clicked, this, &DownloadDialog2::reject);
    connect(selPathButton, &QAbstractButton::clicked, this, &DownloadDialog2::selectPath);

    QFont font = this->font();
    font.setPointSize(12);
    font.setFamily("微软雅黑");
    auto listWidget = findChildren<QWidget*>();
    for (auto& widget : listWidget)
    {
        widget->setFont(font);
    }
}

void DownloadDialog2::selectPath()
{
    auto path = QFileDialog::getExistingDirectory(this, QString(), pathLabel->text());
    if (!path.isNull()) {
        pathLabel->setText(QDir::toNativeSeparators(path));
    }
}

void DownloadDialog2::startGetCurrentItemQnList() {

}

QString DownloadDialog2::Get_Choose_Quality()
{
    return qnComboBox->currentText();
}

QString DownloadDialog2::Get_Choose_Path()
{
    return pathLabel->text();
}
