#include "helppage.h"
#include "ui_helppage.h"
#include "vars.h"

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

void HelpPage::on_spinBox_valueChanged(int arg1)
{
    level = arg1;
}

void HelpPage::on_spinBox_2_valueChanged(int arg1)
{
    lastT = arg1;
}
