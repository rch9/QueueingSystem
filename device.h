#ifndef DEVICE_H
#define DEVICE_H

#include "controller.h"

class Device : public Controller {
public:
    Device(float lambda, int number);

    void putBid(Bid bid);
    void freeBid();

    const Bid &getBid() const;

    const bool &getIsFree() const;
//    void setIsFree(const bool &isFree);
    void setTime(const float &time);

protected:
    float distributionLaw();
private:
    float _lambda;
    Bid _bid;
    bool _isFree;
};

#endif // DEVICE_H
