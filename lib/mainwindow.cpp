#include "mainwindow.h"
#include "map.h"
#include "QPainter"
#include "user.h"
#include "QDebug"
#include "QTimer"
#include <vector>
#include <queue>
#include "QHBoxLayout"
#include "QVBoxLayout"
#include "QMouseEvent"
#include "QPushButton"
#include "QLabel"
#include "QFileDialog"
#include "QFile"
#include "QTime"

int moveX[] = {-1, 1, 0, 0}; // 上下左右 对应的数组下标变化
int moveY[] = {0, 0, -1, 1};
const int points[] = {100, 90, 80, 70, 60, 50};


int map[LINE][COLUMN];
int selected[LINE][COLUMN];
int visited[LINE][COLUMN];
int cntPath, reachFlag;
Poi path[LINE * COLUMN];
int lastx = -1, lasty = -1;
int lastT = INIT_TIME;
Poi hint1 = Poi(-1, -1), hint2 = Poi(-1, -1);
int hintTime = 0;
bool isActivated = true;
User user1, user2;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QTimer *timer = new QTimer(this);
    resize(SCREEN_WIDTH, SCREEN_HEIGHT);
    setWindowIconText(QString("QLink"));
    generateMap(6);
    connect(this, SIGNAL(change()), this, SLOT(update()));
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
    timer->start(1000);

    pauseWidget = new PauseWidget;
    connect(this, SIGNAL(pause()), pauseWidget, SLOT(showWindow()));
    connect(pauseWidget, SIGNAL(unPause()), this, SLOT(unPause()));
    connect(pauseWidget, SIGNAL(save()), this, SLOT(writeFile()));
    connect(pauseWidget, SIGNAL(load()), this, SLOT(readFile()));
}

MainWindow::~MainWindow()
{

}

void MainWindow::generateProp(enum Map item)
{
    int x = rand() % LINE, y = rand() % COLUMN;
    int curCnt = 0;
    while (map[x][y] != EMPTY) {
        x = rand() % LINE;
        y = rand() % COLUMN;
        curCnt++;
        if (curCnt > RANDOM_LIM) return;
    }
    map[x][y] = item;
}
void MainWindow::generateOutSpace(enum Map item)
{
    int xPool[] = {0, 1, LINE - 2, LINE - 1};
    int yPool[] = {0, 1, COLUMN - 2, COLUMN - 1};
    int x = rand() % 4, y = rand() % 4;
    int curCnt = 0;
    while (map[xPool[x]][yPool[y]] != EMPTY) {
        x = rand() % 4;
        y = rand() % 4;
        curCnt++;
        if (curCnt > RANDOM_LIM) return ;
    }
    map[xPool[x]][yPool[y]] = item;
}
void MainWindow::updateTime()
{
   if (!isActivated) {
       emit change(); // 绘制暂停
       return ;
   }

   lastT--;
   if (hintTime > 0) { // 生成两个提示方块
        hintTime--;
        if (!isLegalObject(hint1.x, hint1.y)
                || !isLegalObject(hint2.x, hint2.y)
                || !tryMatch(hint1.x, hint1.y, hint2.x, hint2.y, 0))  {
            hint1 = Poi(-1, -1);
            hint2 = Poi(-1, -1);
            haveSolution(1);
        }
   }
   else {
       hint1 = Poi(-1, -1);
       hint2 = Poi(-1, -1);
   }
   qDebug() << "t:" << lastT << " hint: " << hint1.x << " " << hint1.y << " " << hint2.x << " " <<hint2.y << endl;
   // 依照概率生成一些方块
   const int MO = 1000;
   int rand1 = rand() % MO;
   if  (rand1 < ADD_RATIO * MO) generateProp(ADD1);

   rand1 = rand() % MO;
   if (rand1 < SHUFFLE_RATIO * MO) generateOutSpace(SHUFFLE);

   rand1 = rand() % MO;
   if (rand1 < HINT_RATIO * MO) generateProp(HINT);
   emit change();
}
bool MainWindow::isHinted(int x1, int y1) // 判断一个方块是不是高亮方块
{
    if (!isLegalObject(x1, y1)) return false;
    if (hint1.x == x1 && hint1.y == y1) return true;
    if (hint2.x == x1 && hint2.y == y1) return true;
    return false;
}
void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, QPixmap(BACKGROUND_PATH));

    for (int i = 0; i < LINE; ++i) {
        for (int j = 0; j < COLUMN; ++j) {
            QPixmap graph;
            switch (map[i][j]) {
            case USER1: {
                graph = QPixmap(USER1_PATH);
                user1.x = i;
                user1.y = j;
                break;
            }
            case ITEM1: {
                if (!selected[i][j]) {
                    if (isHinted(i, j)) graph = QPixmap(ITEM1_HINTED);
                    else graph = QPixmap(ITEM1_PATH);
                }
                else graph = QPixmap(ITEM1_SELECTED);
                break;
            }
            case ITEM2: {
                if (!selected[i][j]) {
                    if (isHinted(i, j)) graph = QPixmap(ITEM2_HINTED);
                    else graph = QPixmap(ITEM2_PATH);
                }
                else graph = QPixmap(ITEM2_SELECTED);
                break;
            }
            case ITEM3: {
                if (!selected[i][j]) {
                    if (isHinted(i, j)) graph = QPixmap(ITEM3_HINTED);
                    else graph = QPixmap(ITEM3_PATH);
                }
                else graph = QPixmap(ITEM3_SELECTED);
                break;
            }
            case ITEM4: {
                if (!selected[i][j]) {
                    if (isHinted(i, j)) graph = QPixmap(ITEM4_HINTED);
                    else graph = QPixmap(ITEM4_PATH);
                }
                else graph = QPixmap(ITEM4_SELECTED);
                break;
            }
            case ITEM5: {
                if (!selected[i][j]) {
                    if (isHinted(i, j)) graph = QPixmap(ITEM5_HINTED);
                    else graph = QPixmap(ITEM5_PATH);
                }
                else graph = QPixmap(ITEM5_SELECTED);
                break;
            }
            case ITEM6: {
                if (!selected[i][j]) {
                    if (isHinted(i, j)) graph = QPixmap(ITEM6_HINTED);
                    else graph = QPixmap(ITEM6_PATH);
                }
                else graph = QPixmap(ITEM6_SELECTED);
                break;
            }
            case ADD1: {
                graph = QPixmap(ADD1_PATH);
                break;
            }
            case SHUFFLE: {
                graph = QPixmap(SHUFFLE_PATH);
                break;
            }
            case HINT: {
                graph = QPixmap(HINT_PATH);
                break;
            }
            }
            painter.drawPixmap(X_SHIFT + SIZE * j, Y_SHIFT + SIZE * i, SIZE, SIZE, graph);
        }
    }

    //qDebug() << "cntP" << cntPath << endl;
    // 绘制消除线
    painter.save();
    painter.setPen(QPen(Qt::yellow, 5));
    for (int i = 1; i < cntPath; ++i) {
        //qDebug() << X_SHIFT + SIZE * path[i].x + SIZE / 2 << endl;
        painter.drawLine(X_SHIFT + SIZE * path[i].y + SIZE / 2,
                         Y_SHIFT + SIZE * path[i].x + SIZE / 2,
                         X_SHIFT + SIZE * path[i + 1].y + SIZE / 2,
                         Y_SHIFT + SIZE * path[i + 1].x + SIZE / 2);
    }
    cntPath = 0;
    painter.restore();

    // 绘制倒计时和得分
    QFont font = painter.font();
    font.setPixelSize(20);
    painter.setFont(font);
    painter.setPen(QPen(Qt::yellow));
    const QRect rec = QRect(0, 0, 200, 20);
    painter.drawText(rec, 0, QString("剩余时间") + QString::number(lastT) + "秒");
    const QRect rec2 = QRect(400, 0, 600, 20);
    painter.drawText(rec2, 0, QString("玩家一得分：") + QString::number(user1.pts));
    const QRect rec3 = QRect(800, 0, 1000, 20);
    painter.drawText(rec3, 0, QString("玩家二得分：") + QString::number(user2.pts));

//    // 绘制暂停页面
//    if (!isActivated) {
//        qDebug() << "show pause page" << endl;
//        QVBoxLayout *vbox = new QVBoxLayout(this);
//        QPushButton *saveButton = new QPushButton("保存", this);
//        QPushButton *loadButton = new QPushButton("载入", this);
//        QLabel *header = new QLabel("暂停", this);
//        vbox->addWidget(header);
//        vbox->addWidget(saveButton);
//        vbox->addWidget(loadButton);
//        QRect rec = QRect(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 60, 200);
//        vbox->setGeometry(rec);
//        //this->setLayout(vbox);
//    }
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
    if (event->key() == Qt::Key_P) {
        if (isActivated) {
            this->close();
            emit pause();
        }
        isActivated = !isActivated;
    }
}
void MainWindow::unPause()
{
    isActivated = !isActivated;
    this->show();
}
bool MainWindow::isObjects(const int &x1, const int &y1)
{
    return (map[x1][y1] >= ITEM1 && map[x1][y1] <= ITEM6);
}

bool MainWindow::isSurrounded(int x1, int y1)
{
    bool res = true;
    if (x1 + 1 < COLUMN) res &= isObjects(x1 + 1, y1);
    if (y1 + 1 < LINE) res &= isObjects(x1, y1 + 1);
    if (x1 > 0) res &= isObjects(x1 - 1, y1);
    if (y1 > 0) res &= isObjects(x1, y1 - 1);
    return res;
}

// 判断一个方块是否可达
bool MainWindow::isOutside(int x1, int y1)
{
    int vis[LINE][COLUMN];
    for (int i = 0; i < LINE; ++i)
        for (int j = 0; j < LINE; ++j)
            vis[i][j] = 0;
    std::queue<Poi> que;
    que.push(Poi(x1, y1));
    while (!que.empty()) {
        int curx = que.front().x, cury = que.front().y;
        que.pop();
        vis[curx][cury] = 1;
        if (curx < 2 || curx > LINE - 2 || cury < 2 || cury > COLUMN - 2) {
            return true;
        }
        for (int i = 0; i < 4; ++i) {
            int nxtx = curx + moveX[i], nxty = cury + moveY[i];
            if (nxtx >= LINE || nxtx < 0 || nxty >= COLUMN || nxty < 0) continue;
            if (isObjects(nxtx, nxty)) continue;
            if (vis[nxtx][nxty]) continue;
            que.push(Poi(nxtx, nxty));
        }
    }
    return false;
}
// opt = 0, 只判断有没有解
// opt = 1， hint道具调用，需要高亮出解
bool MainWindow::haveSolution(int opt)
{
    std::vector<Poi> pool[6];
    for (int i = 0; i < LINE; ++i) {
        for (int j = 0; j < COLUMN; ++j) {
            if (isObjects(i, j) && isOutside(i, j)) {
                pool[map[i][j] - ITEM1].push_back(Poi(i, j));
            }
        }
    }
    int cc = 0;
    for (int i = 0; i < 6; ++i) {
        int size = pool[i].size();
        for (int j = 0; j < size; ++j) {
            for (int k = j + 1; k < size; ++k) {
                cc++;
                //qDebug() << "try" << pool[i][j].x << " "
                        // << pool[i][j].y << " " << pool[i][k].x << " " << pool[i][k].y << endl;
                if (tryMatch(pool[i][j].x, pool[i][j].y, pool[i][k].x, pool[i][k].y, 0)) {

                    qDebug() << "cntok:" << cc << endl;
                    if (opt == 1) {
                       hint1 = Poi(pool[i][j].x, pool[i][j].y);
                       hint2 = Poi(pool[i][k].x, pool[i][k].y);
                       //qDebug() << "find" << endl;
                    }
                    return true;
                }
            }
        }
    }
    qDebug() << "cntnotok:" << cc << endl;
    return false;
}
void MainWindow::user1Move(enum Direction direction)
{
    if (!isActivated) return ; // 如果暂停状态，没有反应
    int curx = user1.x, cury = user1.y;
    int nxtx = curx + moveX[direction]; // 数组的顺序对应实际绘画的顺序, curx, cury是数组下标不是具体坐标
    int nxty = cury + moveY[direction];
    //qDebug() << curx << cury << nxtx << nxty << endl;
    if (nxtx < 0) nxtx = LINE - 1;
    if (nxtx == LINE) nxtx = 0;
    if (nxty < 0) nxty = COLUMN - 1;
    if (nxty == COLUMN) nxty = 0;
    if (map[nxtx][nxty] == EMPTY) { // 移动
        map[nxtx][nxty] = USER1;
        map[curx][cury] = EMPTY;
    }
    if (map[nxtx][nxty] >= ITEM1 && map[nxtx][nxty] <= ITEM6) { // 选中方块
        if (lastx == -1) {
            selected[nxtx][nxty] = 1;
            lastx = nxtx;
            lasty = nxty;
        }
        else {
            tryMatch(nxtx, nxty, lastx, lasty, 1);
            selected[lastx][lasty] = 0;
            lastx = lasty = -1;
        }
    }
    if (map[nxtx][nxty] == ADD1) { // 触发+1s道具
        lastT += ADD_TIME;
        map[nxtx][nxty] = USER1;
        map[curx][cury] = EMPTY;
    }
    if (map[nxtx][nxty] == SHUFFLE) { // 触发重排道具
        map[nxtx][nxty] = USER1;
        map[curx][cury] = EMPTY;
        shuffle();
    }
    if (map[nxtx][nxty] == HINT) { // 触发提示道具
        map[nxtx][nxty] = USER1;
        map[curx][cury] = EMPTY;
        hintTime += HINT_TIME;
    }
    emit change();
}

void MainWindow::shuffle() // 重排
{
    if (lastx != -1) {
        selected[lastx][lasty] = 1 - selected[lastx][lasty];
        lastx = lasty = -1;
    }
    for (int i = 0; i < SHUFFLE_CNT; ++i) {
        int x1 = rand() % (LINE - 4) + 2, y1 = rand() % (COLUMN - 4) + 2;
        int x2 = rand() % (LINE - 4) + 2, y2 = rand() % (COLUMN - 4) + 2;
        std::swap(map[x1][y1], map[x2][y2]);
    }
}
bool MainWindow::differ(int x1, int y1, int x2, int y2)
{
    return (x1 != x2 || y1 != y2);
}
// 判断(x1, y1)是不是合法的方块
bool MainWindow::isLegalObject(int x1, int y1)
{
    if (x1 < 2 || x1 > LINE - 2)return false;
    if (y1 < 2 || y1 > COLUMN - 2) return false;
    if (map[x1][y1] < ITEM1 || map[x1][y1] > ITEM6) return false;
    return true;
}
// 尝试进行(curx, cury)方块与(lastx, lasty)方块的匹配
// opt = 0, 不消除; opt = 1，消除
bool MainWindow::tryMatch(int curx, int cury, int lastx, int lasty, int opt)
{
    bool res = false;
    reachFlag = 0;
    cntPath = 0;
    for (int i = 0; i < LINE; ++i)
        for (int j = 0; j < COLUMN; ++j)
            visited[i][j] = 0;

    if (differ(curx, cury, lastx, lasty) &&
        map[curx][cury] == map[lastx][lasty] &&
        dfs(curx, cury, lastx, lasty, 0, ALLTYPE, opt)) { // 成功在两个转弯之内匹配
            if (opt == 1) {
                user1.pts += points[map[curx][cury] - ITEM1];
                map[curx][cury] = EMPTY;
                map[lastx][lasty] = EMPTY;
            }
            res = true;
    }
    return res;
}
// 判断(curx, cury)能否在两个转弯之内到(lastx, lasty)
// opt = 0, 不记录路径； opt = 1，记录路径
bool MainWindow::dfs(int curx, int cury, int lastx, int lasty, int countTurns, enum LastMove lastMove, int opt)
{
    if (countTurns > 2 || reachFlag) return false;
    if (opt) {
        path[++cntPath].x = curx;
        path[cntPath].y = cury;
    }
    visited[curx][cury] = 1;
    //qDebug() << "(" << curx << "," << cury << ")" << "cntP" << cntPath << endl;
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
                res |= dfs(nxtx, nxty, lastx, lasty, countTurns + 1, X, opt);
            else res |= dfs(nxtx, nxty, lastx, lasty, countTurns, X, opt);
        }
        else { // movey
            if (lastMove == X)
                res |= dfs(nxtx, nxty, lastx, lasty, countTurns + 1, Y, opt);
            else res |= dfs(nxtx, nxty, lastx, lasty, countTurns, Y, opt);
        }
    }
    visited[curx][cury] = 0;
    if (!res && opt) cntPath--;
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
    for (int i = 0; i < SHUFFLE_CNT; ++i) {
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

// 存档
void MainWindow::writeFile()
{
    uint time = QDateTime::currentDateTime().toTime_t();
    QString path = QFileDialog::getSaveFileName(this, "保存",
                                                "C:\\Users\\19026\\Desktop\\" + QString::number(time) + ".txt",
                                                "TXT(*.txt)");
    QFile file(path);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);

    for (int i = 0; i < LINE; ++i) {
        for (int j = 0; j < COLUMN; ++j) {
            out << map[i][j] << " ";
        }
        out << endl;
    }
    out << lastT << " " << hintTime << endl;
    out << user1.x << " " << user1.y << " " << user1.pts << endl;
    out << user2.x << " " << user2.y << " " << user2.pts << endl;
    file.close();
}
void MainWindow::readFile()
{
    QString path = QFileDialog::getOpenFileName(this, "载入", "C:\\Users\\19026\\Desktop\\");
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return ;
    while (!file.atEnd()) {
        for (int i = 0; i < LINE; ++i) {
            QByteArray array = file.readLine();
            QString str = QString(array);
            QStringList list = str.split(" ");
            for (int j = 0; j < COLUMN; ++j) {
                bool ok = false;
                map[i][j] = list[j].toInt(&ok, 10);
            }
        }
        QByteArray array = file.readLine();
        QString str = QString(array);
        QStringList list = str.split(" ");
        bool ok = false;
        lastT = list[0].toInt(&ok, 10);
        hintTime = list[1].toInt(&ok, 10);

        array = file.readLine();
        str = QString(array);
        list = str.split(" ");
        ok = false;
        user1.x = list[0].toInt(&ok, 10);
        user1.y = list[1].toInt(&ok, 10);
        user1.pts = list[2].toInt(&ok, 10);

        array = file.readLine();
        str = QString(array);
        list = str.split(" ");
        ok = false;
        user2.x = list[0].toInt(&ok, 10);
        user2.y = list[1].toInt(&ok, 10);
        user2.pts = list[2].toInt(&ok, 10);
    }

}
