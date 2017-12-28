//
// Created by kairod on 28/12/17.
//

#ifndef DEV_SHOOTER_H
#define DEV_SHOOTER_H


#include "Enemy.h"

class Shooter : Enemy{
public:
    Shooter();
    Shooter(int life, int speed);
    Projectile *shoot(); //todo
    void update();

    ~Shooter() = default;
};


#endif //DEV_SHOOTER_H
