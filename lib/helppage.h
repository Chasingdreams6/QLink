#ifndef HELPPAGE_H
#define HELPPAGE_H

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

private:
    Ui::HelpPage *ui;
};

#endif // HELPPAGE_H
