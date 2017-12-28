//
// Created by kairod on 28/12/17.
//

#include "Enemy.h"

void Enemy::takeDamage(int damage) {
    int life = this->state.getLifePoint();
    this->state.setLifePoint(life-damage);
}
