#ifndef LAYER_H
#define LAYER_H

#include "devicescontroller.h"
#include "sourcescontroller.h"
#include "buffer.h"
#include <vector>
#include <utility>
#include <tuple>

class StatisticsInfoManager {
public:
    StatisticsInfoManager *getInstance();

    void setInfo(const SourcesController &sourcesController, const Buffer &buffer, const DevicesController &devicesController);

    const std::vector<std::tuple<float, int>> &getSourcesInfo() const;
    const std::vector<std::tuple<int, int>> &getBufferInfo() const;
    const std::vector<std::tuple<float, int, int>> &getDevicesInfo() const;

private:
    std::vector<std::tuple<float, int>> _soursesInfo;
    std::vector<std::tuple<int, int>> _bufferInfo;
    std::vector<std::tuple<float, int, int>> _devicesInfo;

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
