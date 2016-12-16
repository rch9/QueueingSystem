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
    Controller();
//    void putBid(const Bid &bid);
//    void popBid();

//    const bool &isFree();

//    const Bid *getBid() const;
//    void freeController();
//    const bool &isFree() const;


protected:    
    void addServiceTime();
    virtual float distributionLaw() = 0;
protected:
//    Bid _bid;
//    bool _isFree;
//    float _maxTime;
//    Bid _bid;    
};

#endif // CONTROLLER_H
