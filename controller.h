#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "timeable.h"
#include "bid.h"

/**
 * @brief The Controller class
 * От этого класса наследуются объекты, у которых
 * есть время обслуживания с законом распределения
 * need rename!
 */

class Controller : public Timeable
{
public:
    Controller(int number);

    const int &getNumber() const;

protected:
    void addServiceTime();
    virtual float distributionLaw() = 0;
protected:
    int _number;
};

#endif // CONTROLLER_H
