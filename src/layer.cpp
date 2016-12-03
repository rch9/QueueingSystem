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


//    cout << _sourceController << endl;
    cout << _deviceController << endl;
    cout << _buffer << endl;

    while (director.getTime() < _workTime) {

        float deviceTime = _deviceController.getMinDeviceTime();
        float sourceTime = _sourceController.getMinSourceTime();


        _buffer.putBid(Bid());
        _deviceController.putBidToDevice(_buffer.popBid());


        //        if (!_buffer.size() || sourceTime < deviceTime) {
        //            // generate Bid To Buffer
        ////            cout << "aaaaaa";
        //            _buffer.putBid(_sourceController.pullMinSourceBid());
        //            director.setTime(sourceTime);
        //        } else {
        //            // take bid from buffer
        //            if (_buffer.size()) {
        //                _deviceController.putBidToDevice(_buffer.popBid());
        //            }
        //            director.setTime(deviceTime);
        //        }

//        cout << _sourceController << endl;
        cout << _deviceController << endl;
        cout << _buffer << endl;

        //        director.setTime(sourceTime < deviceTime ? sourceTime : deviceTime);
        //        break;
    }

    return true;
}
