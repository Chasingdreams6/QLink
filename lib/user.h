#pragma once
#ifndef USER_H
#define USER_H

#include "map.h"

struct User {
    enum Map id;
    int lastx, lasty;
    int x, y, pts;
    User(enum Map idd) {
        id = idd;
        lastx = -1; lasty = -1;
        pts = 0;
        x = y = -1;
    }
};


#endif // USER_H
