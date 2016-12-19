#include "device.h"
#include "randomhelper.h"
#include "layer.h"
#include "director.h"

Device::Device(float lambda, int number):
    Controller(number),
    _lambda(lambda),
    _isFree(true) {
}

void Device::putBid(Bid bid) {
    _bid = bid;    
    _bid.setInDeviceStartTime(Director::getInstance()->getTime());
    StatisticsInfoManager::getInstance()->addedBidToDevice(_bid);
    addServiceTime();
    _isFree = false;
}

void Device::freeBid() {
    Bid bid;
    _bid.setInSystemTime(_time);
    StatisticsInfoManager::getInstance()->addedDoneBid(_bid, _number);
    _bid = bid;
    _time = Director::getInstance()->getTime();
    _isFree = true;
}

const Bid &Device::getBid() const {
    return _bid;
}

float Device::distributionLaw() {
    return RandomHelper::rand_exponential(_lambda);
}

const bool &Device::getIsFree() const {
    return _isFree;
}

//void Device::setIsFree(const bool &isFree) {
//    _isFree = isFree;
//}

void Device::setTime(const float &time) {
    _time = time;
}
