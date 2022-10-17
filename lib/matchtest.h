#pragma once
#ifndef MATCHTEST_H
#define MATCHTEST_H
#include <QtTest/QtTest>

class MatchTest : public QObject
{
    Q_OBJECT
private slots:
    void testLegal();
    void testLegal_data();
};

#endif // MATCHTEST_H
