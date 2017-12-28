//
// Created by kairod on 28/12/17.
//

#ifndef DEV_ENEMY_H
#define DEV_ENEMY_H


#include "Entity.h"
#include "Stats.h"

class Enemy : Entity{
protected:
    Stats state;


public:
    Enemy() = default;

    const Stats &getState() const {
        return state;
    }

    void setState(const Stats &state) {
        Enemy::state = state;
    }

    void takeDamage(int damage);

    virtual ~Enemy(){};
};


#endif //DEV_ENEMY_H
