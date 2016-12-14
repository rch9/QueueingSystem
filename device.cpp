#include "device.h"
#include "randomhelper.h"

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

void Device::freeBid() {
    Bid bid;
    _bid = bid;
}

const Bid &Device::getBid() const {
    return _bid;
}

float Device::distributionLaw() {
    return RandomHelper::rand_exponential(_lambda);
}