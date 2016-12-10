#include "devicescontroller.h"
#include "../timeableClasses/director.h"
#include <iostream>
#include "src/timeableClasses/director.h"

DevicesController::DevicesController():
    _currentDevice(0) {
}

void DevicesController::init(std::initializer_list<float> args) {
    _amountDevices = args.size();
    for (auto arg: args) {
        _devices.push_back(Device(arg));
    }
}

void DevicesController::putBidToDevice(const Bid &bid) {
    for (int i = 0; i < _amountDevices; ++i) {
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
        if ((*it).getTime() < Director::getInstance()->getTime()) {
            if ((*it).getBid().getSource() != -1) {
                std::cout << "free dev T: " << (*it).getTime() << " bid S: " << (*it).getBid().getSource() << " Dir T: "  << Director::getInstance()->getTime() << std::endl;
                (*it).freeBid();
            }
        }
    }
}

void DevicesController::moveDevicePointer() {
    if (++_currentDevice == _amountDevices) {
        _currentDevice = 0;
    }
}
