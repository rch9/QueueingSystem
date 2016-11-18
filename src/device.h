#ifndef DEVICE_H
#define DEVICE_H

#include "controller.h"



class Device : public Controller {
public:
    Device(float lambda);
protected:
    float distributionLaw();
private:
    float _lambda;
};

#endif // DEVICE_H
