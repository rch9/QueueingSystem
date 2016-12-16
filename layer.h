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

    void setInfo(const SourcesController &sourcesController, const Buffer &buffer, const DevicesController &devicesController);

    const vect_str &getSourcesInfo() const;
    const vect_str &getBufferInfo() const;
    const vect_str &getDevicesInfo() const;

private:
    vect_str _soursesInfo;
    vect_str _bufferInfo;
    vect_str _devicesInfo;

private:
    StatisticsInfoManager();
};

class Layer {
public:
    Layer();


    void setSMOAdgs(std::vector<std::pair<float, float>> soursesArgs,
                    size_t bufferSize, std::vector<float> devisesArgs, float worktime);

    /**
     * @brief init and run program
     * @return
     */
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
