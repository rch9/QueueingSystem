#include "device.h"
#include "randomhelper.h"
#include "layer.h"
#include "director.h"

Device::Device(float lambda, int number):
    Controller(number),
    _lambda(lambda) {    
}

void Device::putBid(Bid bid) {
    _bid = bid;    
    _bid.setInDeviceStartTime(Director::getInstance()->getTime());
    StatisticsInfoManager::getInstance()->addedBidToDevice(_bid);
    addServiceTime();
}

void Device::freeBid() {
    Bid bid;
    _bid.setInSystemTime(_time);
    StatisticsInfoManager::getInstance()->addedDoneBid(_bid, _number);
    _bid = bid;
}

const Bid &Device::getBid() const {
    return _bid;
}

float Device::distributionLaw() {
    return RandomHelper::rand_exponential(_lambda);
}
