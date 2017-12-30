//
// Created by kairod on 24/12/17.
//

#include "Entity.h"

void Entity::setSettings(Animation *a, int x, int y, Direction d) {
    this->anim=*a;
    this->boxCollision=this->anim.getSprite().getGlobalBounds();
    this->dx=x;
    this->dy=y;
    this->direction=d;
}
