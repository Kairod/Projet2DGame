//
// Created by kairod on 24/12/17.
//

#include "Element.h"

void Element::draw(sf::RenderWindow window) {
  this->anim.getSprite().setPosition(this->x,this->y);
  window.draw(this->anim.getSprite());
}

sf::FloatRect Element::getCollisionBox() const{
  return this->boxCollision;
}
