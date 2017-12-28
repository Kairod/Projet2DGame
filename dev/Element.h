//
// Created by kairod on 24/12/17.
//

#ifndef DEV_OBJECT_H
#define DEV_OBJECT_H

#include <cstdlib>
#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Animation.h"


class Element {

protected:
        float x, y;
        Animation anim;
        //todo boxCollision

    public:
        void draw(sf::RenderWindow window);
        virtual void takeDamage(int damage)const = 0;
        Element();

    virtual ~Element() = default;
};


#endif //DEV_OBJECT_H
