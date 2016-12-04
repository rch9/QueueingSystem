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
            if (_buffer.size()) {
                if (deviceTime != 0.f) {
                    Director::getInstance().setTime(deviceTime);
                }
                _deviceController.putBidToDevice(_buffer.popBid());
            }
            cout << "\nfree smth\n";
        }

        cout << _sourceController << endl;
        cout << _buffer << endl;
        cout << _deviceController << endl;
        cout << endl << "======================" << endl;
    }

    return true;
}
