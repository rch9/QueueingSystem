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
}

bool Layer::run() {
//    cout << _sourceController << endl;
//    cout << _buffer << endl;
//    cout << _deviceController << endl;
//    cout << endl << "======================" << endl;

//    while (Director::getInstance().getTime() < _workTime) {
//        float deviceTime = _deviceController.getMinDeviceTime();
//        float sourceTime = _sourceController.getMinSourceTime();

//        if (!_buffer.size() || sourceTime < deviceTime) {
//            Director::getInstance().setTime(sourceTime);
//            _buffer.putBid(_sourceController.pullMinSourceBid());

//        } else {

//            if (deviceTime != 0.f) {
//                Director::getInstance().setTime(deviceTime);
//            }
//            _deviceController.putBidToDevice(_buffer.popBid());
//        }

//        _deviceController.freeReadyDevices();

//        cout << _sourceController << endl;
//        cout << _buffer << endl;
//        cout << _deviceController << endl;
//        cout << endl << "======================" << endl;
//    }

    StatisticsInfoManager::getInstance()->setStatistic(_sourceController, _buffer, _deviceController);

    return true;
}

void Layer::step() {
    float deviceTime = _deviceController.getMinDeviceTime();
    float sourceTime = _sourceController.getMinSourceTime();

    if (!_buffer.size() || sourceTime < deviceTime) {
        Director::getInstance().setTime(sourceTime);
        _buffer.putBid(_sourceController.pullMinSourceBid());

    } else {

        if (deviceTime != 0.f) {
            Director::getInstance().setTime(deviceTime);
        }
        _deviceController.putBidToDevice(_buffer.popBid());
    }

    _deviceController.freeReadyDevices();

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

void StatisticsInfoManager::addFailure(const Bid &bid) {
    _failure.push_back(bid);
    _failureInfo.push_back({ std::to_string(bid.getSource()), std::to_string(bid.getNumber()) });
}

StatisticsInfoManager::StatisticsInfoManager() {
}
