//
// Created by kairod on 24/12/17.
//

#include "Personnage.h"

Personage::Personage(const Stats &stat) : stat(stat) {}

void Personage::takeDamage(int damage) {
    int lifePoint = this->stat.getLifePoint();
    this->stat.setLifePoint(lifePoint-damage);
}

bool Personage::isAlive() {
    return (this->stat.getLifePoint()>0);
}

Projectile *Personage::shoot() {
    // todo
    return nullptr;
}

void Personage::update() {
    int maxSpeed = 10;
    // todo
}

const Stats &Personage::getStat() const {
    return stat;
}

void Personage::setStat(const Stats &stat) {
    Personage::stat = stat;
}


