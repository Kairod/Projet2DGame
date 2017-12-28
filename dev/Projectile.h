//
// Created by kairod on 28/12/17.
//

#ifndef DEV_PROJECTILE_H
#define DEV_PROJECTILE_H


class Projectile {
private:
    int degat;

public:
    Projectile();
    Projectile(int degatValue);
    void update();

    int getDegat() const;

    void setDegat(int degat);
};


#endif //DEV_PROJECTILE_H
