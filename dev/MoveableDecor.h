//
// Created by kairod on 28/12/17.
//

#ifndef DEV_MOVEABLEDECOR_H
#define DEV_MOVEABLEDECOR_H


#include "Entity.h"
#include "Decors.h"

class MoveableDecor : Entity, Decors{
public:
    MoveableDecor() = default;
    virtual ~MoveableDecor();
};


#endif //DEV_MOVEABLEDECOR_H
