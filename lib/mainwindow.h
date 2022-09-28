#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QKeyEvent"
#include "map.h"
#include "pausewidget.h"
#include "constant.h"
#include "user.h"
#include "startpage.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    bool tryMatch(int curx, int cury, int lastx, int lasty, int opt, User&);
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    PauseWidget *pauseWidget;
    StartPage *startPage;
    void generateMap(int level);
    void generatePeople(enum Map);
    void generateBlocks(int level);
    void generateProp(enum Map);
    void generateOutSpace(enum Map);
    void move(enum Direction, enum Map);
    bool dfs(int curx, int cury, int lastx, int lasty, int countTurns, enum LastMove, int opt);
    void drawLine();
    bool differ(int x1, int y1, int x2, int y2);
    bool isSurrounded(int x1, int y1);
    bool isOutside(int x1, int y1);
    bool isObjects(const int &x1, const int &y1);
    bool haveSolution(int opt);
    void shuffle();
    bool isHinted(int x1, int y1);
    bool isLegalObject(int x1, int y1);

protected:
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);
signals:
    void change();
    void pause();
public slots:
    void updateTime();
    void unPause();
    void writeFile();
    void readFile();
    void singleMode();
    void multiMode();
    void endGame(); // quit
};
#endif // MAINWINDOW_H
