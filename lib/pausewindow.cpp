#include "pausewindow.h"
#include "QPainter"
#include "constant.h"
#include "QDebug"

PauseWindow::PauseWindow()
{

}
void PauseWindow::showWindow()
{
    this->show();
}

void PauseWindow::closeWindow()
{
    QWidget::close();
}

void PauseWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::yellow, 15));
    int x = SCREEN_WIDTH / 2, y = SCREEN_HEIGHT / 2;
    const QRect rec = QRect(x, y, 60, 20);
    painter.drawText(rec, 0, QString("暂停"));
}

void PauseWindow::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "press key in pause page" << endl;
}
