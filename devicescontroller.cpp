#include "devicescontroller.h"
#include "director.h"
#include <iostream>

DevicesController::DevicesController():
    _currentDevice(0) {
}

void DevicesController::init(std::vector<float> args) {
    _amountDevices = args.size();
    for (auto arg: args) {
        _devices.push_back(Device(arg, _devices.size()));
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

//    for (int i = 0; i < _amountDevices; ++i) {
//        if (_devices.at(i).getIsFree()) {
//            _devices.at(i).setTime()
//        }
//    }
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

    for (auto device : _devices) {
        if (device.getIsFree()) {
//            device.setTime(Director::getInstance()->getTime());
        } else {
            if (device.getTime() < Director::getInstance()->getTime()) {
                device.freeBid();
            }
        }
    }  
}

void DevicesController::updateFreeDevices(float time) {
    for(auto device : _devices) {
        if (device.getIsFree()) {            
            device.setTime(1111);
//            std::cout << device.getTime();
        }
    }
}

void DevicesController::moveDevicePointer() {
    if (++_currentDevice == _amountDevices) {
        _currentDevice = 0;
    }
}

const std::deque<Device> &DevicesController::getDevices() const {
    return _devices;
}
