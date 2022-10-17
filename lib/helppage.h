#pragma once
#ifndef HELPPAGE_H
#define HELPPAGE_H

#include "constant.h"
#include <QWidget>

namespace Ui {
class HelpPage;
}

class HelpPage : public QWidget
{
    Q_OBJECT

public:
    explicit HelpPage(QWidget *parent = nullptr);
    ~HelpPage();
    void showText();

private slots:
    void on_spinBox_valueChanged(int arg1);

    void on_spinBox_2_valueChanged(int arg1);

private:
    Ui::HelpPage *ui;
};

#endif // HELPPAGE_H
