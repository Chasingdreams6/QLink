#ifndef ENDPAGE_H
#define ENDPAGE_H

#include <QWidget>

namespace Ui {
class EndPage;
}

class EndPage : public QWidget
{
    Q_OBJECT

public:
    explicit EndPage(QWidget *parent = nullptr);
    ~EndPage();
    void showScore(int score1, int score2);

private:
    Ui::EndPage *ui;
};

#endif // ENDPAGE_H
