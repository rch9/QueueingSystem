#include "devicescontroller.h"
#include "../timeableClasses/director.h"
#include <iostream>
#include "src/timeableClasses/director.h"

DevicesController::DevicesController():
    _currentDevice(0) {
}

//void DevicesController::init(int amount) {
//    auto ilist = std::initializer_list<int>{amount...};
//    _amountDevices = ilist.size();

//    for (auto&& p : list) {
//        std::cout << p << "   ";
//        _devices.push_back(Device(p));
//    }
//}

void DevicesController::init(int amount) {
    _amountDevices = amount;
    for(int i = 0; i < amount; ++i) {
        _devices.push_back(Device(1));
    }
}

void DevicesController::putBidToDevice(const Bid &bid) {
    for(int i = 0; i < _amountDevices; ++i) {
        if (_devices.at(_currentDevice).getTime() == getMinDeviceTime()) {
            _devices.at(_currentDevice).putBid(bid);
            break;
        }
        moveDevicePointer();
    }
}

float DevicesController::getMinDeviceTime() const {
    auto minIt = _devices.begin();
    for(auto it = _devices.begin(); it != _devices.end(); ++it) {
        if ((*it).getTime() < (*minIt).getTime()) {
            minIt = it;
        }
    }

    return (*minIt).getTime();
}

void DevicesController::freeReadyDevices() {
    for(auto it = _devices.begin(); it != _devices.end(); ++it) {
        if ((*it).getTime() < Director::getInstance().getTime()) {
            (*it).free();
        }
    }
}

void DevicesController::moveDevicePointer() {
    if (++_currentDevice == _amountDevices) {
        _currentDevice = 0;
    }
}
