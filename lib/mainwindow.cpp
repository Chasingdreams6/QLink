#include "mainwindow.h"
#include "map.h"
#include "QPainter"


int map[LINE][COLUMN];


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(SCREEN_WIDTH, SCREEN_HEIGHT);
    setWindowIconText(QString("QLink"));
    generateMap(6);
}

MainWindow::~MainWindow()
{

}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, QPixmap(BACKGROUND_PATH));

    for (int i = 0; i < LINE; ++i) {
        for (int j = 0; j < COLUMN; ++j) {
            switch (map[i][j]) {
            case USER1: {
                painter.drawPixmap(X_SHIFT + SIZE * j, Y_SHIFT + SIZE * i, SIZE, SIZE, QPixmap(USER1_PATH));
                break;
            }
            case ITEM1: {
                painter.drawPixmap(X_SHIFT + SIZE * j, Y_SHIFT + SIZE * i, SIZE, SIZE, QPixmap(ITEM1_PATH));
                break;
            }
            case ITEM2: {
                painter.drawPixmap(X_SHIFT + SIZE * j, Y_SHIFT + SIZE * i, SIZE, SIZE, QPixmap(ITEM2_PATH));
                break;
            }
            case ITEM3: {
                painter.drawPixmap(X_SHIFT + SIZE * j, Y_SHIFT + SIZE * i, SIZE, SIZE, QPixmap(ITEM3_PATH));
                break;
            }
            case ITEM4: {
                painter.drawPixmap(X_SHIFT + SIZE * j, Y_SHIFT + SIZE * i, SIZE, SIZE, QPixmap(ITEM4_PATH));
                break;
            }
            case ITEM5: {
                painter.drawPixmap(X_SHIFT + SIZE * j, Y_SHIFT + SIZE * i, SIZE, SIZE, QPixmap(ITEM5_PATH));
                break;
            }
            case ITEM6: {
                painter.drawPixmap(X_SHIFT + SIZE * j, Y_SHIFT + SIZE * i, SIZE, SIZE, QPixmap(ITEM6_PATH));
                break;
            }
            }
        }
    }
}


// level 表示最大出现的方块种类数
void MainWindow::generateMap(int level)
{
    srand(time(NULL));

    for (int i = 0; i < LINE; ++i) {
        for (int j = 0; j < COLUMN; ++j) {
            map[i][j] = EMPTY;
        }
    }

    generateBlocks(level);
    generatePeople();
}

void MainWindow::generateBlocks(int level)
{
    int half = (LINE - 4) * (COLUMN - 4) / 2;
    int used[half];
    for (int i = 0; i < half; ++i) {
        used[i] = ITEM1 + rand() % level;
    }
    int tmp = 0;
    for (int i = 2; i < LINE - 2; ++i) {
        for (int j = 2; j < COLUMN - 2; j += 2) {
            map[i][j] = used[tmp];
            map[i][j + 1] = used[tmp];
            tmp++;
        }
    }
    for (int i = 0; i < SHUFFLE_RATIO; ++i) {
        int x1 = rand() % (LINE - 4), y1 = rand() % (COLUMN - 4);
        int x2 = rand() % (LINE - 4), y2 = rand() % (COLUMN - 4);
        std::swap(map[x1 + 2][y1 + 2], map[x2 + 2][y2 + 2]);
    }
}

void MainWindow::generatePeople()
{
    int xpos[] = {0, 1, COLUMN - 2, COLUMN - 1};
    int ypos[] = {0, 1, LINE - 2, LINE - 1};
    int x1 = xpos[rand() % 4], y1 = ypos[rand() % 4];
    while (map[y1][x1] != EMPTY) {
        x1 = xpos[rand() % 4];
        y1 = ypos[rand() % 4];
    }
    map[y1][x1] = USER1;
}
