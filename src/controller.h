#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "timeable.h"

/**
 * @brief The Controller class
 * От этого класса наследуются объекты, у которых
 * есть время обслуживания с законом распределения
 * need rename!
 */

class Controller : public Timeable
{
public:
    Controller();
protected:
    void addServiceTime();
    virtual float distributionLaw() = 0;
    float _maxTime;
};

#endif // CONTROLLER_H
