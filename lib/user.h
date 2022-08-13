#ifndef USER_H
#define USER_H

struct User {
    int x, y, pts;
    User() {
        pts = 0;
        x = y = -1;
    }
};


#endif // USER_H
