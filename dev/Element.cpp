//
// Created by kairod on 24/12/17.
//

#include "Element.h"

void Element::draw(sf::RenderWindow window) {
    // todo
}

sf::FloatRect Element::getCollisionBox() const{
  return this->boxCollision;
}
