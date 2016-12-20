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

    StatisticsInfoManager::getInstance()->initSMOArgs(soursesArgs.size(), devisesArgs.size());    
}

bool Layer::run() {   
    StatisticsInfoManager::getInstance()->setStatistic(_sourceController, _buffer, _deviceController);

    return true;
}

void Layer::step() {
    float deviceTime = _deviceController.getMinDeviceTime();
    float sourceTime = _sourceController.getMinSourceTime();
    float deviceBusyTime = _deviceController.getMinBusyDeviceTime();

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
    _failureInfo.push_back({ std::to_string((bid).getSource()), std::to_string((bid).getNumber()) });
    ++_FBidsTable.at(bid.getSource());
    _TSysTable.at(bid.getSource()) += (Director::getInstance()->getTime() - bid.getTime());
    _TBufTable.at(bid.getSource()) += (Director::getInstance()->getTime() - bid.getTime());
}

void StatisticsInfoManager::addedBidToBuffer(const Bid &bid) {    
    ++_NBidsTable.at(bid.getSource());
}

void StatisticsInfoManager::addedBidToDevice(const Bid &bid) {    
    _TBufTable.at(bid.getSource()) += (bid.getInDeviceStartTime() - bid.getTime());
}

void StatisticsInfoManager::addedDoneBid(const Bid &bid) {
    _TDevTable.at(bid.getSource()) += ((bid).getInSystemTime() - (bid).getInDeviceStartTime());
    _TSysTable.at(bid.getSource()) += ((bid).getInSystemTime() - (bid).getTime());    
}

void StatisticsInfoManager::initSMOArgs(int sourcesCount, int devicesCount) {
    for (int i = 0; i < sourcesCount; ++i) {
        _NBidsTable.push_back(0); //кол-во заявок
        _FBidsTable.push_back(0); //кол-во заявок отказов
        _PFTable.push_back(0.f); //вероятность отказа - потом
        _TSysTable.push_back(0.f); //время в системе
        _TBufTable.push_back(0.f); //время в буфере
        _TDevTable.push_back(0.f); //кол-во заявок
    }

    for (int i = 0; i < devicesCount; ++i) {
        _KTable.push_back(0.f); //коэф. приборов - потом
    }
}

std::vector<int> StatisticsInfoManager::getNBidsTable() const
{
    return _NBidsTable;
}

std::vector<int> StatisticsInfoManager::getFBidsTable() const
{
    return _FBidsTable;
}

std::vector<float> StatisticsInfoManager::getPFTable() const
{
    return _PFTable;
}

std::vector<float> StatisticsInfoManager::getTSysTable() const
{
    return _TSysTable;
}

std::vector<float> StatisticsInfoManager::getTBufTable() const
{
    return _TBufTable;
}

std::vector<float> StatisticsInfoManager::getTDevTable() const
{
    return _TDevTable;
}

std::vector<float> StatisticsInfoManager::getKTable() const
{
    return _KTable;
}

void StatisticsInfoManager::addKTable(float value, int number)
{
    _KTable.at(number) = value;
}

float StatisticsInfoManager::getAllP() const
{
    float N = 0.f, F = 0.f;
    for(int i = 0; i < _NBidsTable.size(); ++i) {
        N += _NBidsTable.at(i);
        F += _FBidsTable.at(i);
    }

    return (F / N);
}

void StatisticsInfoManager::cleanAll() {

//    _soursesInfo.erase(_soursesInfo.begin(), _soursesInfo.end());
//    _bufferInfo.erase(_bufferInfo.begin(), _bufferInfo.end());
//    _devicesInfo.erase(_devicesInfo.begin(), _devicesInfo.end());
//    _failureInfo.erase(_failureInfo.begin(), _failureInfo.end());

//    _NBidsTable.erase(_NBidsTable.begin(), _NBidsTable.end()); //кол-во заявок
//    _FBidsTable.erase(_FBidsTable.begin(), _FBidsTable.end()); //кол-во заявок отказов
//    _PFTable.erase(_PFTable.begin(), _PFTable.end()); //вероятность отказа - потом
//    _TSysTable.erase(_TSysTable.begin(), _TSysTable.end()); //время в системе
//    _TBufTable.erase(_TBufTable.begin(), _TBufTable.end()); //время в буфере
//    _TDevTable.erase(_TDevTable.begin(), _TDevTable.end()); //кол-во заявок
//    _KTable.erase(_KTable.begin(), _KTable.end()); //коэф. приборов - потом

    _soursesInfo.clear();
    _bufferInfo.clear();
    _devicesInfo.clear();
    _failureInfo.clear();

    _NBidsTable.clear(); //кол-во заявок
    _FBidsTable.clear(); //кол-во заявок отказов
    _PFTable.clear(); //вероятность отказа - потом
    _TSysTable.clear(); //время в системе
    _TBufTable.clear(); //время в буфере
    _TDevTable.clear(); //кол-во заявок
    _KTable.clear(); //коэф. приборов - потом
}

StatisticsInfoManager::StatisticsInfoManager() {
}
