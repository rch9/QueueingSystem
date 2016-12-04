#include "device.h"
#include "../utils/randomhelper.h"

Device::Device(float lambda):
    Controller(),
    _lambda(lambda) {
    // наверн стоит убрать
//    addServiceTime();
}

void Device::putBid(Bid bid) {
    _bid = bid;
    addServiceTime();
}

void Device::free() {
    _time = 0.f;
}

float Device::distributionLaw() {
    return RandomHelper::rand_exponential(_lambda);
}
