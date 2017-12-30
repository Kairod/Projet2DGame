//
// Created by kairod on 24/12/17.
//

#ifndef DEV_ENTITY_H
#define DEV_ENTITY_H


#include "Element.h"
#include "Direction.h"
#include <cstdlib>

class Entity : Element{

    protected:
        float dx, dy;
        Direction direction;
        bool friendly;

    public:
        Entity() = default;
        void setSettings(Animation *a, int x, int y, Direction d);
        virtual void update() const = 0;
        virtual ~Entity() {}
};


#endif //DEV_ENTITY_H
