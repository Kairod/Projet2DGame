//
// Created by kairod on 24/12/17.
//

#ifndef DEV_ENTITY_H
#define DEV_ENTITY_H


#include "Object.h"
#include "Direction.h"

class Entity : Object{

    protected:
        bool userControl;
        bool friendly;
        Direction direction;

    public:
        Entity();


};


#endif //DEV_ENTITY_H
