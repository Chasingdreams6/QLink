#include "mainwindow.h"
#include "map.h"
#include "QPainter"
#include "user.h"
#include "QDebug"

int moveX[] = {-1, 1, 0, 0}; // 上下左右 对应的数组下标变化
int moveY[] = {0, 0, -1, 1};

int map[LINE][COLUMN];
int selected[LINE][COLUMN];
int visited[LINE][COLUMN];
int cntPath, reachFlag;
Poi path[LINE * COLUMN];
int lastx = -1, lasty = -1;
User user1, user2;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(SCREEN_WIDTH, SCREEN_HEIGHT);
    setWindowIconText(QString("QLink"));
    generateMap(6);
    connect(this, SIGNAL(change()), this, SLOT(update()));
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
                user1.x = i;
                user1.y = j;
                break;
            }
            case ITEM1: {
                if (!selected[i][j])
                    painter.drawPixmap(X_SHIFT + SIZE * j, Y_SHIFT + SIZE * i, SIZE, SIZE, QPixmap(ITEM1_PATH));
                else
                    painter.drawPixmap(X_SHIFT + SIZE * j, Y_SHIFT + SIZE * i, SIZE, SIZE, QPixmap(ITEM1_SELECTED));
                break;
            }
            case ITEM2: {
                if (!selected[i][j])
                    painter.drawPixmap(X_SHIFT + SIZE * j, Y_SHIFT + SIZE * i, SIZE, SIZE, QPixmap(ITEM2_PATH));
                else
                    painter.drawPixmap(X_SHIFT + SIZE * j, Y_SHIFT + SIZE * i, SIZE, SIZE, QPixmap(ITEM2_SELECTED));
                break;
            }
            case ITEM3: {
                if (!selected[i][j])
                    painter.drawPixmap(X_SHIFT + SIZE * j, Y_SHIFT + SIZE * i, SIZE, SIZE, QPixmap(ITEM3_PATH));
                else
                    painter.drawPixmap(X_SHIFT + SIZE * j, Y_SHIFT + SIZE * i, SIZE, SIZE, QPixmap(ITEM3_SELECTED));
                break;
            }
            case ITEM4: {
                if (!selected[i][j])
                    painter.drawPixmap(X_SHIFT + SIZE * j, Y_SHIFT + SIZE * i, SIZE, SIZE, QPixmap(ITEM4_PATH));
                else
                    painter.drawPixmap(X_SHIFT + SIZE * j, Y_SHIFT + SIZE * i, SIZE, SIZE, QPixmap(ITEM4_SELECTED));
                break;
            }
            case ITEM5: {
                if (!selected[i][j])
                    painter.drawPixmap(X_SHIFT + SIZE * j, Y_SHIFT + SIZE * i, SIZE, SIZE, QPixmap(ITEM5_PATH));
                else
                    painter.drawPixmap(X_SHIFT + SIZE * j, Y_SHIFT + SIZE * i, SIZE, SIZE, QPixmap(ITEM5_SELECTED));
                break;
            }
            case ITEM6: {
                if (!selected[i][j])
                    painter.drawPixmap(X_SHIFT + SIZE * j, Y_SHIFT + SIZE * i, SIZE, SIZE, QPixmap(ITEM6_PATH));
                else
                    painter.drawPixmap(X_SHIFT + SIZE * j, Y_SHIFT + SIZE * i, SIZE, SIZE, QPixmap(ITEM6_SELECTED));
                break;
            }
            }
        }
    }

    qDebug() << "cntP" << cntPath << endl;
    painter.setPen(QPen(Qt::yellow, 5));
    for (int i = 1; i < cntPath; ++i) {
        qDebug() << X_SHIFT + SIZE * path[i].x + SIZE / 2 << endl;
        painter.drawLine(X_SHIFT + SIZE * path[i].y + SIZE / 2,
                         Y_SHIFT + SIZE * path[i].x + SIZE / 2,
                         X_SHIFT + SIZE * path[i + 1].y + SIZE / 2,
                         Y_SHIFT + SIZE * path[i + 1].x + SIZE / 2);
    }
    cntPath = 0;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Up)
        user1Move(UP);
    if (event->key() == Qt::Key_Left)
        user1Move(LEFT);
    if (event->key() == Qt::Key_Right)
        user1Move(RIGHT);
    if (event->key() == Qt::Key_Down)
        user1Move(DOWN);
}

void MainWindow::user1Move(enum Direction direction)
{
    int curx = user1.x, cury = user1.y;
    int nxtx = curx + moveX[direction]; // 数组的顺序对应实际绘画的顺序, curx, cury是数组下标不是具体坐标
    int nxty = cury + moveY[direction];
    //qDebug() << curx << cury << nxtx << nxty << endl;
    if (nxtx < 0) nxtx = LINE - 1;
    if (nxtx == LINE) nxtx = 0;
    if (nxty < 0) nxty = COLUMN - 1;
    if (nxty == COLUMN) nxty = 0;
    if (map[nxtx][nxty] == EMPTY) {
        map[nxtx][nxty] = USER1;
        map[curx][cury] = EMPTY;
    }
    if (map[nxtx][nxty] >= ITEM1 && map[nxtx][nxty] <= ITEM6) {
        if (lastx == -1) {
            selected[nxtx][nxty] = 1 - selected[nxtx][nxty];
            lastx = nxtx;
            lasty = nxty;
        }
        else tryMatch(nxtx, nxty);
    }
    emit change();
}

bool MainWindow::differ(int x1, int y1, int x2, int y2)
{
    return (x1 != x2 || y1 != y2);
}
// 尝试进行(curx, cury)方块与(lastx, lasty)方块的匹配
void MainWindow::tryMatch(int curx, int cury)
{
    reachFlag = 0;
    cntPath = 0;
    for (int i = 0; i < LINE; ++i)
        for (int j = 0; j < COLUMN; ++j)
            visited[i][j] = 0;

    if (differ(curx, cury, lastx, lasty) &&
        map[curx][cury] == map[lastx][lasty] &&
        dfs(curx, cury, 0, ALLTYPE)) { // 成功在两个转弯之内匹配
            map[curx][cury] = EMPTY;
            map[lastx][lasty] = EMPTY;
    }
    selected[lastx][lasty] = 0;
    lastx = lasty = -1;
}

bool MainWindow::dfs(int curx, int cury, int countTurns, enum LastMove lastMove)
{
    if (countTurns > 2 || reachFlag) return false;
    path[++cntPath].x = curx;
    path[cntPath].y = cury;
    visited[curx][cury] = 1;
    qDebug() << "(" << curx << "," << cury << ")" << "cntP" << cntPath << endl;
    if (curx == lastx && cury == lasty) { // reach
        reachFlag = 1;
        //drawLine();
        return true;
    }
    bool res = false;
    for (int i = 0; i < 4; ++i) {
        int nxtx = curx + moveX[i];
        int nxty = cury + moveY[i];
        if (nxtx >= LINE || nxtx < 0 || nxty >= COLUMN || nxty < 0) continue;
        if (visited[nxtx][nxty]) continue;
        if (map[nxtx][nxty] >= ITEM1 && map[nxtx][nxty] <= ITEM6 && (nxtx != lastx || nxty != lasty)) continue;
        if (nxtx != curx) { // movex
            if (lastMove == Y)
                res |= dfs(nxtx, nxty, countTurns + 1, X);
            else res |= dfs(nxtx, nxty, countTurns, X);
        }
        else { // movey
            if (lastMove == X)
                res |= dfs(nxtx, nxty, countTurns + 1, Y);
            else res |= dfs(nxtx, nxty, countTurns, Y);
        }
    }
    visited[curx][cury] = 0;
    if (!res) cntPath--;
    return res;
}

void MainWindow::drawLine()
{
    QPainter painter;
    for (int i = 1; i < cntPath; ++i) {
        painter.drawLine(X_SHIFT + SIZE * path[i].x + SIZE / 2,
                         Y_SHIFT + SIZE * path[i].y + SIZE / 2,
                         X_SHIFT + SIZE * path[i + 1].x + SIZE / 2,
                         Y_SHIFT + SIZE * path[i + 1].y + SIZE / 2);
    }
}
// level 表示最大出现的方块种类数
void MainWindow::generateMap(int level)
{
    srand(time(NULL));

    for (int i = 0; i < LINE; ++i) {
        for (int j = 0; j < COLUMN; ++j) {
            map[i][j] = EMPTY;
            selected[i][j] = 0;
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
