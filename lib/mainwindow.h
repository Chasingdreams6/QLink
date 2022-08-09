#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QKeyEvent"
#include "map.h"

#define SCREEN_WIDTH 960 // 屏幕宽度
#define SCREEN_HEIGHT 880 // 屏幕高度
#define LINE 13 // 地图行数
#define COLUMN 16 // 地图列数
#define SIZE 60 // 每一个方块的像素大小
#define X_SHIFT 0 // 左右偏移
#define Y_SHIFT 112 // 上下偏移
#define INIT_TIME 180   // 初始游戏时间
#define ADD_TIME 10 // +1s道具的增加时长
#define ADD_RATIO 0.1 // 每一秒的出现概率
#define SHUFFLE_RATIO 0.1
#define SHUFFLE_CNT 50 //  交换次数
#define RANDOM_LIM 10

#define BACKGROUND_PATH ":/images/blackground.bmp"
#define ITEM1_PATH ":/images/item1.jpeg"
#define ITEM2_PATH ":/images/item2.jpeg"
#define ITEM3_PATH ":/images/item3.jpeg"
#define ITEM4_PATH ":/images/item4.jpeg"
#define ITEM5_PATH ":/images/item5.jpeg"
#define ITEM6_PATH ":/images/item6.jpeg"
#define USER1_PATH ":/images/user1.jpeg"
#define ADD1_PATH ":/images/add1.png"
#define SHUFFLE_PATH ":/images/shuffle.png"
#define ITEM1_SELECTED ":/images/item1_selected.jpeg"
#define ITEM2_SELECTED ":/images/item2_selected.jpeg"
#define ITEM3_SELECTED ":/images/item3_selected.jpeg"
#define ITEM4_SELECTED ":/images/item4_selected.jpeg"
#define ITEM5_SELECTED ":/images/item5_selected.jpeg"
#define ITEM6_SELECTED ":/images/item6_selected.jpeg"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void updateTime();
private:
    void generateMap(int level);
    void generatePeople();
    void generateBlocks(int level);
    void generateProp(enum Map);
    void generateOutSpace(enum Map);
    void user1Move(enum Direction);
    void tryMatch(int curx, int cury);
    bool dfs(int curx, int cury, int countTurns, enum LastMove);
    void drawLine();
    bool differ(int x1, int y1, int x2, int y2);
    bool isSurrounded(int x1, int y1);
    bool isObjects(int x1, int y1);
    bool haveSolution();
    void shuffle();

protected:
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);
signals:
    void change(); 
};
#endif // MAINWINDOW_H
