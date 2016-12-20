#ifndef LAYER_H
#define LAYER_H

#include "devicescontroller.h"
#include "sourcescontroller.h"
#include "buffer.h"
#include <vector>
#include <utility>
#include <tuple>
#include <string>

class StatisticsInfoManager {
    typedef std::vector<std::vector<std::string>> vect_str;

public:
    static StatisticsInfoManager *getInstance();

    void setStatistic(const SourcesController &sourcesController, const Buffer &buffer, const DevicesController &devicesController);
//    void setInfo();

    const vect_str &getSourcesStatistic() const;
    const vect_str &getBufferStatistic() const;
    const vect_str &getDevicesStatistic() const;
    const vect_str &getFailureStatistic() const;

// собирают статистику
    void addedFailureBid(const Bid &bid);
    void addedBidToBuffer(const Bid &bid);
    void addedBidToDevice(const Bid &bid);
    void addedDoneBid(const Bid &bid);
    void initSMOArgs(int sourcesCount, int devicesCount);   

    std::vector<int> getNBidsTable() const;
    std::vector<int> getFBidsTable() const;
    std::vector<float> getPFTable() const;
    std::vector<float> getTSysTable() const;
    std::vector<float> getTBufTable() const;
    std::vector<float> getTDevTable() const;
    std::vector<float> getKTable() const;

    void addKTable(float value, int number);

    void setAllTime(float allTime);
    float getAllTime() const;

    void cleanAll();

private:
    vect_str _soursesInfo;
    vect_str _bufferInfo;
    vect_str _devicesInfo;
    vect_str _failureInfo;    

    std::vector<int> _NBidsTable; //кол-во заявок
    std::vector<int> _FBidsTable; //кол-во заявок отказов
    std::vector<float> _PFTable; //вероятность отказа - потом
    std::vector<float> _TSysTable; //время в системе
    std::vector<float> _TBufTable; //время в буфере
    std::vector<float> _TDevTable; //кол-во заявок
    std::vector<float> _KTable; //коэф. приборов - потом    
private:
    StatisticsInfoManager();        
};

class Layer {
public:
    Layer();


    void setSMOAdgs(std::vector<std::pair<float, float>> soursesArgs,
                    size_t bufferSize, std::vector<float> devisesArgs, float worktime);

    bool run(/*args*/);
    void step();

private:
    int _numberOfSources;
    int _numberOfDevices;
    int _bufferSize;
    float _workTime;
private:
    SourcesController _sourceController;
    DevicesController _deviceController;
    Buffer _buffer;
};

#endif // LAYER_H
