#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "timeable.h"

class Director : public Timeable
{
public:
    static Director *getInstance();

    void setTime(const float &time);
    void cleanAll();
private:    
    Director();
private:    
};

#endif // DIRECTOR_H
