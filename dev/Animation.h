//
// Created by kairod on 28/12/17.
//

#ifndef DEV_ANIMATION_H
#define DEV_ANIMATION_H


#include <SFML/Graphics/Sprite.hpp>

class Animation {
    private:
        float frame;
        float speed;
        sf::Sprite sprite;
        std::vector<sf::Rect<int>> frames;

    public:
        Animation(sf::Texture &texture, int x, int y, int width, int height, int count, float speedValue);
        void update();
        bool isEnd();
};


#endif //DEV_ANIMATION_H
