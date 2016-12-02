#ifndef LAYER_H
#define LAYER_H

#include "controllers/devicescontroller.h"
#include "controllers/sourcescontroller.h"
#include "buffer.h"
#include <vector>

class Layer {
public:
    Layer(int numberOfSources, int numberOfDevices, int bufferSize, float workTime);

    void init();

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
