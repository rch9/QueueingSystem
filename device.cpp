#include "device.h"
#include "randomhelper.h"
#include "layer.h"

Device::Device(float lambda, int number):
    Controller(number),
    _lambda(lambda) {    
}

void Device::putBid(Bid bid) {
    _bid = bid;
    StatisticsInfoManager::getInstance()->addedBidToDevice(bid);
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
