#include "endpage.h"
#include "ui_endpage.h"
#include <iostream>

EndPage::EndPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EndPage)
{
    ui->setupUi(this);
}

EndPage::~EndPage()
{
    delete ui;
}

void EndPage::showScore(int score1, int score2) {
    ui->label_2->hide();
    ui->label_3->hide();
    if (score1 > 0) {
        ui->label_2->setText("玩家1得分:" + QString::number(score1));
        ui->label_2->show();
    }
    if (score2 > 0) {
        ui->label_3->setText("玩家2得分:" + QString::number(score2));
        ui->label_3->show();
    }
    this->show();
}
