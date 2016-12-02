#include "layer.h"
#include "timeableClasses/director.h"

Layer::Layer(int numberOfSources, int numberOfDevices, int bufferSize, float workTime):
    _numberOfSources(numberOfSources),
    _numberOfDevices(numberOfDevices),
    _bufferSize(bufferSize),
    _workTime(workTime) {
    init();
}

void Layer::init() {
    _buffer.init(_bufferSize);
    _sourceController.init(_numberOfSources);
    _deviceController.init(_numberOfDevices);
}

bool Layer::run() {
    auto director = Director::getInstance();

    while (director.getGlobalTime() < _workTime) {

        director.addGlobalTime(0.1);
    }

    return true;
}
