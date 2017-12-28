//
// Created by kairod on 28/12/17.
//

#ifndef DEV_DECORS_H
#define DEV_DECORS_H


#include "Element.h"

class Decors : Element{

protected:
    bool isDestructible;

public:
    Decors() = default;
    virtual void takeDamage(int damage){};

    bool isIsDestructible() const {
        return isDestructible;
    }

    void setIsDestructible(bool isDestructible) {
        Decors::isDestructible = isDestructible;
    }

    virtual ~Decors(){};
};


#endif //DEV_DECORS_H
