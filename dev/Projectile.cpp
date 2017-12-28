//
// Created by kairod on 28/12/17.
//

#include "Projectile.h"

void Projectile::update() {
    //todo
}

Projectile::Projectile(int degatValue) {
    this->degat=degatValue;
}

int Projectile::getDegat() const {
    return degat;
}

void Projectile::setDegat(int degat) {
    Projectile::degat = degat;
}
