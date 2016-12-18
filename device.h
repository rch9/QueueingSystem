#ifndef DEVICE_H
#define DEVICE_H

#include "controller.h"



class Device : public Controller {
public:
    Device(float lambda, int number);

    void putBid(Bid bid);
    void freeBid();

    const Bid &getBid() const;

protected:
    float distributionLaw();
private:
    float _lambda;
    Bid _bid;
};

#endif // DEVICE_H
