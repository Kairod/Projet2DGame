//
// Created by kairod on 28/12/17.
//

#ifndef DEV_MOVEDESTRUCTDECOR_H
#define DEV_MOVEDESTRUCTDECOR_H


#include "MoveableDecor.h"

class MoveDestructDecor : MoveableDecor{
private:
    int life;

public:
    MoveDestructDecor();
    MoveDestructDecor(int lifePoint);

    int getLife() const;

    void setLife(int life);
    void update();
};


#endif //DEV_MOVEDESTRUCTDECOR_H
