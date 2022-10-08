#include "helppage.h"
#include "ui_helppage.h"

HelpPage::HelpPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HelpPage)
{
    ui->setupUi(this);
    Qt::WindowFlags m_flags = windowFlags();
    setWindowFlags(m_flags | Qt::WindowStaysOnTopHint);
}

HelpPage::~HelpPage()
{
    delete ui;
}

void HelpPage::showText()
{
    this->show();
}
