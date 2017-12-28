//
// Created by kairod on 28/12/17.
//

#ifndef DEV_DESTRUCTIBLEDECOR_H
#define DEV_DESTRUCTIBLEDECOR_H


#include "Decors.h"

class DestructibleDecor : Decors{
    public:
        DestructibleDecor();
        DestructibleDecor(int lifePoint);

    int getLife() const;

    void setLife(int life);

    void takeDamage(int damage);
        bool isDestructed();

    private:
        int life;
};


#endif //DEV_DESTRUCTIBLEDECOR_H
