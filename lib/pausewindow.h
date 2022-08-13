#ifndef PAUSEWINDOW_H
#define PAUSEWINDOW_H

#include <QObject>
#include <QWidget>

class PauseWindow : public QWidget
{
    Q_OBJECT
public:
    PauseWindow();
protected:
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);
public slots:
    void showWindow();
    void closeWindow();
};

#endif // PAUSEWINDOW_H
