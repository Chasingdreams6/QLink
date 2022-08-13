#ifndef PAUSEWIDGET_H
#define PAUSEWIDGET_H

#include <QWidget>
#include "QMouseEvent"

namespace Ui {
class PauseWidget;
}

class PauseWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PauseWidget(QWidget *parent = nullptr);
    ~PauseWidget();

private:
    Ui::PauseWidget *ui;
protected:
    void keyPressEvent(QKeyEvent *event);
signals:
    void unPause();
    void save();
    void load();
public slots:
    void showWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // PAUSEWIDGET_H
