#include "pausewidget.h"
#include "ui_pausewidget.h"
#include "constant.h"

PauseWidget::PauseWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PauseWidget)
{

    ui->setupUi(this);
}

PauseWidget::~PauseWidget()
{
    delete ui;
}

void PauseWidget::showWindow()
{
    resize(SCREEN_WIDTH, SCREEN_HEIGHT);
    this->show();
}

void PauseWidget::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_P) {
        this->close();
        emit unPause();
    }
}

void PauseWidget::on_pushButton_clicked()
{
    emit save();
}

void PauseWidget::on_pushButton_2_clicked()
{
    emit load();
//    this->close();
//    emit unPause();
}
