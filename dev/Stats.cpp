//
// Created by kairod on 24/12/17.
//

#include "Stats.h"

int Stats::get_lifePoint() const {
    return _lifePoint;
}

void Stats::set_lifePoint(int _lifePoint) {
    Stats::_lifePoint = _lifePoint;
}

double Stats::get_moveSpeed() const {
    return _moveSpeed;
}

void Stats::set_moveSpeed(double _moveSpeed) {
    Stats::_moveSpeed = _moveSpeed;
}


