#ifndef DEVICE_H
#define DEVICE_H

#include "controller.h"



class Device : public Controller {
public:
    Device(float lambda);

    void putBid(Bid bid);

protected:
    float distributionLaw();
private:
    float _lambda;
    Bid _bid;
};

#endif // DEVICE_H
