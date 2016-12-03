#include "devicescontroller.h"
#include "../timeableClasses/director.h"
#include <iostream>
//#include <deque>

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
    while (Director::getInstance().getTime() < _devices.at(_currentDevice).getTime()) {
        // тут циклится
        moveDevicePointer();
    }
    _devices.at(_currentDevice).putBid(bid);
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

void DevicesController::moveDevicePointer() {
    if (++_currentDevice == _amountDevices) {
        _currentDevice = 0;
    }
}
