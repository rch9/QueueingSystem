#include "layer.h"

Layer::Layer(int numberOfSources, int numberOfDevices, int bufferSize, float workTime):
    _numberOfSources(numberOfSources),
    _numberOfDevices(numberOfDevices),
    _bufferSize(bufferSize),
    _workTime(workTime) {
//    init();
}

void Layer::init() {
//    _buffer = Buffer(_bufferSize);
}

bool Layer::run() {


    while (1) {

    }

    return true;
}
