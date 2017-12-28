//
// Created by kairod on 28/12/17.
//

#include "MoveDestructDecor.h"

MoveDestructDecor::MoveDestructDecor(int lifePoint) {
    this->life = lifePoint;
}

int MoveDestructDecor::getLife() const {
    return life;
}

void MoveDestructDecor::setLife(int life) {
    MoveDestructDecor::life = life;
}

void MoveDestructDecor::update() {
    // todo
}
