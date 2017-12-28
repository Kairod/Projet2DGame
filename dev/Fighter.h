//
// Created by kairod on 28/12/17.
//

#ifndef DEV_FIGHTER_H
#define DEV_FIGHTER_H


#include "Enemy.h"

class Fighter : Enemy{
public:
    Fighter() {}
    Fighter(int life, int speed, int attackDamage);
    void takeDamage(int damage);
    bool isAlive();

    int getAttacValue() const;

    void setAttacValue(int attacValue);

private:
    int attacValue;
};


#endif //DEV_FIGHTER_H
