//
// Created by kairod on 24/12/17.
//

#ifndef DEV_STATS_H
#define DEV_STATS_H

#include <cstdlib>


class Stats {
    public:
    int getLifePoint() const;
    void setLifePoint(int lifePoint);
    double getMoveSpeed() const;
    void setMoveSpeed(double moveSpeed);

private:
    int lifePoint;
    double moveSpeed;
};


#endif //DEV_STATS_H
