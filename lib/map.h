#pragma once
#ifndef MAP_H
#define MAP_H


enum Map {
    EMPTY,
    USER1,
    USER2,
    ITEM1,
    ITEM2,
    ITEM3,
    ITEM4,
    ITEM5,
    ITEM6,
    ADD1,
    SHUFFLE,
};

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT,
};


enum LastMove {
    X,
    Y,
    ALLTYPE,
};



struct Poi {
    int x, y;
    Poi(int xx, int yy) {
        x = xx;
        y = yy;
    }
    Poi(){}
};

#endif // MAP_H
