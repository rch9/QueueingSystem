#include "device.h"
#include "randomhelper.h"
#include "layer.h"
#include "director.h"
#include <iostream>

Device::Device(float lambda, int number):
    Controller(number),
    _lambda(lambda),
    _isFree(true),
    _workTime(0.f) {
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
    StatisticsInfoManager::getInstance()->addedDoneBid(_bid);
    _bid = bid;
    _time = Director::getInstance()->getTime();
    _isFree = true;
    _workTime += (_time - _bid.getInDeviceStartTime());
//    std::cout << "WORK " << _workTime << "\n";
    StatisticsInfoManager::getInstance()->addKTable((_time - _bid.getInDeviceStartTime()), _number);
}

const Bid &Device::getBid() const {
    return _bid;
}

float Device::distributionLaw() {
    return RandomHelper::rand_exponential(_lambda);
}

float Device::getWorkTime() const
{
    return _workTime;
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
