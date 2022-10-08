#include "matchtest.h"
#include "mainwindow.h"
#include "user.h"

void MatchTest::testLegal_data()
{


}
void MatchTest::testLegal()
{
    QVERIFY(1 == 1);
    MainWindow w;
    int tmp[LINE][COLUMN] = {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,4,4,7,8,4,4,3,7,7,4,6,0,0,0},
        {0,0,4,7,4,8,5,7,3,3,3,3,6,6,0,0},
        {0,0,5,4,7,7,3,3,4,8,5,6,8,3,0,0},
        {0,0,8,3,6,7,4,5,7,8,4,3,0,0,0,0},
        {0,0,4,7,7,7,7,7,4,4,7,6,3,4,0,0},
        {0,0,3,5,4,6,7,4,6,6,4,8,5,5,0,0},
        {0,0,6,7,8,4,4,7,4,3,5,6,7,6,0,0},
        {0,0,8,5,7,3,4,3,3,3,4,4,7,7,0,0},
        {0,0,3,3,5,5,3,3,6,7,6,7,3,5,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
    };
    extern int map[LINE][COLUMN];
    for (int i = 0; i < LINE; ++i) {
        for (int j = 0; j < COLUMN; ++j) {
            map[i][j] = tmp[i][j];
        }
    }
    User usr;
    QVERIFY(w.tryMatch(2, 2, 2, 3, 0, usr) == true);
    QVERIFY(w.tryMatch(2, 2, 2, 4, 0, usr) == false);
    QVERIFY(w.tryMatch(0, 2, 2, 4, 0, usr) == false);
    QVERIFY(w.tryMatch(0, 46436, 2, 4, 0, usr) == false);
    QVERIFY(w.tryMatch(0, 2, 2, -4, 0, usr) == false);
    QVERIFY(w.tryMatch(2, 12, 3, 13, 0, usr) == true);
    QVERIFY(w.tryMatch(5, 11, 4, 13, 0, usr) == true);
}

//QTEST_MAIN(MatchTest);
