//
// Created by kairod on 24/12/17.
//

#ifndef DEV_PERSONAGE_H
#define DEV_PERSONAGE_H


#include "Entity.h"
#include "Stats.h"

class Personage : Entity{

    public:
        Personage(const Stats &stat);

    private:
        Personage();
        Stats stat;

};


#endif //DEV_PERSONAGE_H
