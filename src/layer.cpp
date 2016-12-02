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


    cout << _sourceController << endl;
    cout << _deviceController << endl;
    cout << _buffer << endl;

    _sourceController.pullMinSourceBid();

    cout << _sourceController << endl;
    cout << _deviceController << endl;
    cout << _buffer << endl;

//    while (director.getGlobalTime() < _workTime) {

//        director.addGlobalTime(0.1);
//    }

    return true;
}
