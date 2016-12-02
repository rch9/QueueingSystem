#include "layer.h"
#include "timeableClasses/director.h"
#include <iostream>

using namespace std;

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

    while (director.getTime() < _workTime) {

        float deviceTime = _deviceController.getMinDeviceTime();
        float sourceTime = _sourceController.getMinSourceTime();

        cout << _sourceController << endl;
        cout << _deviceController << endl;
        cout << _buffer << endl;

        if (!_buffer.size() || sourceTime < deviceTime) {
            // generate Bid To Buffer
//            cout << "aaaaaa";
            _buffer.putBid(_sourceController.pullMinSourceBid());
        } else {
            // take bid from buffer
            _deviceController.putBidToDevice(_buffer.popBid());
        }                

        cout << _sourceController << endl;
        cout << _deviceController << endl;
        cout << _buffer << endl;

        director.setTime(sourceTime < deviceTime ? sourceTime : deviceTime);
        break;
    }

    return true;
}
