//
// Created by kairod on 28/12/17.
//

#include "Fighter.h"

Fighter::Fighter(int life, int speed, int attackDamage) {
    this->state.setLifePoint(life);
    this->state.setMoveSpeed(speed);
    this->attacValue = attackDamage;
}

void Fighter::takeDamage(int damage) {
    int life = this->state.getLifePoint();
    this->state.setLifePoint(life-damage);
}

bool Fighter::isAlive() {
    return this->state.getLifePoint()>0;
}

int Fighter::getAttacValue() const {
    return attacValue;
}

void Fighter::setAttacValue(int attacValue) {
    Fighter::attacValue = attacValue;
}
