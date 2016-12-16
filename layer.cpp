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
    cout << _sourceController << endl;
    cout << _buffer << endl;
    cout << _deviceController << endl;
    cout << endl << "======================" << endl;

    while (Director::getInstance().getTime() < _workTime) {
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

        cout << _sourceController << endl;
        cout << _buffer << endl;
        cout << _deviceController << endl;
        cout << endl << "======================" << endl;
    }

    return true;
}

void Layer::step() {

}

StatisticsInfoManager *StatisticsInfoManager::getInstance() {
    static StatisticsInfoManager instance;

    return &instance;
}

void StatisticsInfoManager::setInfo(const SourcesController &sourcesController, const Buffer &bufferInfo, const DevicesController &devicesController) {

}

StatisticsInfoManager::StatisticsInfoManager() {
}
