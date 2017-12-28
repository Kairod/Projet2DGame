//
// Created by kairod on 28/12/17.
//

#include "DestructibleDecor.h"

DestructibleDecor::DestructibleDecor() {
    this->isDestructible=true;
}

DestructibleDecor::DestructibleDecor(int lifePoint) {
    this->life=lifePoint;
    this;
}

void DestructibleDecor::takeDamage(int damage) {
    this->life-=damage;
}

bool DestructibleDecor::isDestructed() {
    return (this->life>0);
}

int DestructibleDecor::getLife() const {
    return life;
}

void DestructibleDecor::setLife(int life) {
    DestructibleDecor::life = life;
}
