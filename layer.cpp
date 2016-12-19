#include "layer.h"
#include "director.h"
#include <iostream>

using namespace std;

Layer::Layer():
    _numberOfSources(0),
    _numberOfDevices(0),
    _bufferSize(0),
    _workTime(0) {
    //    init();
}

void Layer::setSMOAdgs(std::vector<std::pair<float, float> > soursesArgs, size_t bufferSize, std::vector<float> devisesArgs, float worktime) {
    _sourceController.init(soursesArgs);
    _buffer.init(bufferSize);
    _deviceController.init(devisesArgs);
    _workTime = worktime;

    cout << "init: " << endl;
    cout << _sourceController << endl;
    cout << _buffer << endl;
    cout << _deviceController << endl;
    cout << "\nDirector time: " << Director::getInstance()->getTime() << std::endl << std::endl;
}

bool Layer::run() {
    //    cout << _sourceController << endl;
    //    cout << _buffer << endl;
    //    cout << _deviceController << endl;
    //    cout << endl << "======================" << endl;

    StatisticsInfoManager::getInstance()->setStatistic(_sourceController, _buffer, _deviceController);

    return true;
}

void Layer::step() {
    float deviceTime = _deviceController.getMinDeviceTime();
    float sourceTime = _sourceController.getMinSourceTime();
    float deviceBusyTime = _deviceController.getMinBusyDeviceTime();

    //    cout << "dev in step " << deviceTime << endl;
    //    cout << "sou in step " << sourceTime << endl;
    /*
    if (deviceTime == 0) {
        Director::getInstance()->setTime(sourceTime);
        _deviceController.updateFreeDevices(Director::getInstance()->getTime());
    } else {

        if (deviceBusyTime < 0) {
            Director::getInstance()->setTime(sourceTime);

            if (_buffer.size()) {
                _deviceController.putBidToDevice(_buffer.popBid());
            } else {
                _buffer.putBid(_sourceController.pullMinSourceBid());
            }

        } else {
            if (sourceTime < deviceBusyTime) {
                Director::getInstance()->setTime(sourceTime);
                _buffer.putBid(_sourceController.pullMinSourceBid());

            } else {
                Director::getInstance()->setTime(deviceBusyTime);
                if (_buffer.size()) {
                    _deviceController.putBidToDevice(_buffer.popBid());
                }
            }
        }
    }

*/

    /*
    if (deviceTime == 0) {
        Director::getInstance()->setTime(sourceTime);
        _deviceController.updateFreeDevices(Director::getInstance()->getTime());
        _buffer.putBid(_sourceController.pullMinSourceBid());
    } else {

        if (deviceBusyTime < 0) {
            if (_buffer.size()) {
                _deviceController.putBidToDevice(_buffer.popBid());
            }
        } else {
            if (deviceBusyTime < sourceTime) {
                Director::getInstance()->setTime(deviceBusyTime);
                _deviceController.freeReadyDevices();
            } else {
                //                Director::getInstance()->setTime(sourceTime);
                if (deviceTime < sourceTime && _buffer.size()) {
//                    Director::getInstance()->setTime(deviceTime);
                    _deviceController.putBidToDevice(_buffer.popBid());
                } else {
                    Director::getInstance()->setTime(sourceTime);
                    _buffer.putBid(_sourceController.pullMinSourceBid());
                }
            }
        }
    }
    */

    if (deviceTime == 0) {
        Director::getInstance()->setTime(sourceTime);
        _deviceController.updateFreeDevices();
        _buffer.putBid(_sourceController.pullMinSourceBid());
    } else {

        if (_deviceController.hasFreeDevice() && _buffer.size()) {
            _deviceController.putBidToDevice(_buffer.popBid());
        } else {
            if ((deviceBusyTime < sourceTime) && (deviceBusyTime > 0)) {
                Director::getInstance()->setTime(deviceBusyTime);
                _deviceController.freeReadyDevices();
                _deviceController.updateFreeDevices();
            } else {
                Director::getInstance()->setTime(sourceTime);
                _buffer.putBid(_sourceController.pullMinSourceBid());
            }
        }
    }


    cout << _sourceController << endl;
    cout << _buffer << endl;
    cout << _deviceController << endl;
    cout << "Director time: " << Director::getInstance()->getTime() << std::endl;

    StatisticsInfoManager::getInstance()->setStatistic(_sourceController, _buffer, _deviceController);
}

StatisticsInfoManager *StatisticsInfoManager::getInstance() {
    static StatisticsInfoManager instance;

    return &instance;
}

void StatisticsInfoManager::setStatistic(const SourcesController &sourcesController, const Buffer &buffer, const DevicesController &devicesController) {
    _soursesInfo.clear();
    _bufferInfo.clear();
    _devicesInfo.clear();

    auto sourses = sourcesController.getSources();
    auto bufferBids = buffer.getBids();
    auto devices = devicesController.getDevices();

    for (auto s : sourses) {
        _soursesInfo.push_back({std::to_string(s.getTime()), std::to_string(s.getBidNumber())});
    }

    for (auto b : bufferBids) {
        _bufferInfo.push_back({std::to_string(b.getSource()), std::to_string(b.getNumber())});
    }

    for (auto d : devices) {
        _devicesInfo.push_back({std::to_string(d.getTime()), std::to_string(d.getBid().getSource()), std::to_string(d.getBid().getNumber())});
    }

}

const StatisticsInfoManager::vect_str &StatisticsInfoManager::getSourcesStatistic() const {
    return _soursesInfo;
}

const StatisticsInfoManager::vect_str &StatisticsInfoManager::getBufferStatistic() const {
    return _bufferInfo;
}

const StatisticsInfoManager::vect_str &StatisticsInfoManager::getDevicesStatistic() const {
    return _devicesInfo;
}

const StatisticsInfoManager::vect_str &StatisticsInfoManager::getFailureStatistic() const {
    return _failureInfo;
}


void StatisticsInfoManager::addedFailureBid(const Bid &bid) {
    //    (*bid).setInSystemTime(Director::getInstance()->getTime());
    _failure.push_back(bid);
    _failureInfo.push_back({ std::to_string((bid).getSource()), std::to_string((bid).getNumber()) });
    std::cout << "\nadded to failure: "  << Director::getInstance()->getTime() - bid.getTime() << std::endl << std::endl;
}

// не нужно
void StatisticsInfoManager::addedBidToBuffer(const Bid &bid) {
    //    (*bid).setInBufferStartTime(Director::getInstance()->getTime());
    //    std::cout << "\nthink zero: " << ((bid).getInBufferStartTime() - (bid).getTime()) << "\n\n";
}

void StatisticsInfoManager::addedBidToDevice(const Bid &bid) {
    //    (*bid).setInDeviceStartTime(Director::getInstance()->getTime());
    //    std::cout << "\ndev: " << (bid).getInDeviceStartTime();
    //    std::cout << "\nt: " << bid.getTime();
    //    std::cout << "\nsys: " << (bid).getInSystemTime();
    //    std::cout << "\ntime in buff: " << ((bid).getInDeviceStartTime() - (bid).getTime()) << "\n\n";
}

void StatisticsInfoManager::addedDoneBid(const Bid &bid, const int &deviceNumber) {
    //    std::cout << "\ndev: " << (*bid).getInDeviceStartTime();
    //    std::cout << "\nt: " << (*bid).getInDeviceStartTime();
    //    std::cout << "\nsys: " << (*bid).getInSystemTime();
    //    std::cout << "\ntime in dev: " << ((bid).getInSystemTime() - (bid).getInDeviceStartTime());
    //    std::cout << "\ntime in system: " << ((bid).getInSystemTime() - (bid).getTime()) << "\n\n";
}

StatisticsInfoManager::StatisticsInfoManager() {
}
