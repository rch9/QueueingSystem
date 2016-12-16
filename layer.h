#ifndef LAYER_H
#define LAYER_H

#include "devicescontroller.h"
#include "sourcescontroller.h"
#include "buffer.h"
#include <vector>
#include <utility>

class StatisticsInfoManager {
public:
    StatisticsInfoManager *getInstance();

    void setInfo(const SourcesController &sourcesController, const Buffer &bufferInfo, const DevicesController &devicesController);

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
