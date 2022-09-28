#include "startpage.h"
#include "ui_startpage.h"
#include "constant.h"

StartPage::StartPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartPage)
{
    ui->setupUi(this);
    resize(SCREEN_WIDTH, SCREEN_HEIGHT);
    Qt::WindowFlags m_flags = windowFlags();
    setWindowFlags(m_flags | Qt::WindowStaysOnTopHint);
    //setAttribute(Qt::WA_TranslucentBackground);
}

StartPage::~StartPage()
{
    delete ui;
}

void StartPage::on_pushButton_clicked()
{
    this->close();
    emit singleMode();
}

void StartPage::on_pushButton_2_clicked()
{
    this->close();
    emit multiMode();
}

void StartPage::on_pushButton_3_clicked()
{
    this->close();
    emit endGame();
}

void StartPage::on_pushButton_4_clicked()
{
    this->close();
    emit load();
}
