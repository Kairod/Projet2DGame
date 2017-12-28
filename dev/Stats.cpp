//
// Created by kairod on 24/12/17.
//

#include "Stats.h"

int Stats::getLifePoint() const {
    return lifePoint;
}

void Stats::setLifePoint(int lifePoint) {
    Stats::lifePoint = lifePoint;
}

double Stats::getMoveSpeed() const {
    return moveSpeed;
}

void Stats::setMoveSpeed(double moveSpeed) {
    Stats::moveSpeed = moveSpeed;
}
