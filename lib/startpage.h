#pragma once
#ifndef STARTPAGE_H
#define STARTPAGE_H

#include <QWidget>
#include "helppage.h"

namespace Ui {
class StartPage;
}

class StartPage : public QWidget
{
    Q_OBJECT

public:
    explicit StartPage(QWidget *parent = nullptr);
    ~StartPage();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::StartPage *ui;
    HelpPage helpPage;

signals:
    void singleMode();
    void multiMode();
    void endGame();
    void load();
};

#endif // STARTPAGE_H
