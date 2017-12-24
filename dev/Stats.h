//
// Created by kairod on 24/12/17.
//

#ifndef DEV_STATS_H
#define DEV_STATS_H


class Stats {
public:
    Stats(int lifePoint, double moveSpeed): _lifePoint(lifePoint), _moveSpeed(moveSpeed){}

    int get_lifePoint() const;

    void set_lifePoint(int _lifePoint);

    double get_moveSpeed() const;

    void set_moveSpeed(double _moveSpeed);

private:
    int _lifePoint;
    double _moveSpeed;
};


#endif //DEV_STATS_H
