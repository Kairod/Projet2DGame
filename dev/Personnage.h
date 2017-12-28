//
// Created by kairod on 24/12/17.
//

#ifndef DEV_PERSONAGE_H
#define DEV_PERSONAGE_H


#include "Entity.h"
#include "Stats.h"
#include <cstdlib>

class Personage : Entity{

    public:
        Personage(const Stats &stat);
        void takeDamage(int damage)(int damage);
        bool isAlive();
        void update();

    const Stats &getStat() const;

    void setStat(const Stats &stat);


    Projectile *shoot();

    private:
        Stats stat;

};


#endif //DEV_PERSONAGE_H
