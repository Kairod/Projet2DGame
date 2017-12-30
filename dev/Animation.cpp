//
// Created by kairod on 28/12/17.
//

#include "Animation.h"

Animation::Animation(sf::Texture &texture, int x, int y, int width, int height, int count, float speedValue){
    frame = 0;
    this->speed=speedValue;
    for (int i = 0; i < count; ++i) {
        this->frames.push_back(sf::Rect<int>(x+i*width, y, width, height));
    }

    this->sprite.setTexture(texture);
    this->sprite.setOrigin(width/2, height/2);
    this->sprite.setTextureRect(frames[0]);
}

void Animation::update() {
    this->frame+=this->speed;
    int n = frames.size();
    if(frame >= n){
        frame -=n;
    }
    if(n > 0){
        this->sprite.setTextureRect(frames[int(frame)]);
    }
}

bool Animation::isEnd() {
    return this->frame+this->speed>=this->frames.size();
}

sf::Sprite Animation::getSprite(){
  return this->sprite;
};
