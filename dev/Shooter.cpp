//
// Created by kairod on 28/12/17.
//

#include "Shooter.h"

Shooter::Shooter() {}

Shooter::Shooter(int life, int speed) {
    this->state.setLifePoint(life);
    this->state.setMoveSpeed(speed);
}

void Shooter::update() {
    // todo

}
