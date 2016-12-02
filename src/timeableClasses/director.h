#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "timeable.h"

class Director : public Timeable
{
public:
    static Director &getInstance();

//    const float &getGlobalTime() const;
//    void addGlobalTime(const float &dt);
    void setTime(const float &time);

private:
    Director();
private:
//    float _globalTime;
};

#endif // DIRECTOR_H
