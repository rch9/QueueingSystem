#include "device.h"
#include "../utils/randomhelper.h"

Device::Device(float lambda):
    Controller(),
    _lambda(lambda) {
    addServiceTime();
}

void Device::putBid(Bid bid) {
    _bid = bid;
    addServiceTime();
}

float Device::distributionLaw() {
    return RandomHelper::rand_exponential(_lambda);
}
