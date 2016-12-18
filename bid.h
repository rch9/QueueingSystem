#ifndef BID_H
#define BID_H

#include "timeable.h"

/**
 * @brief The Bid class
 */

class Bid : public Timeable {
public:
    Bid(float time, int source, int number);
    Bid();
    ~Bid();
    const int &getSource() const;
    const int &getNumber() const;

    float getInBufferStartTime() const;
    void setInBufferStartTime(const float &inBufferStartTime);

    float getInDeviceStartTime() const;
    void setInDeviceStartTime(const float &inDeviceStartTime);

    const float &getInSystemTime() const;
    void setInSystemTime(const float &inSystemTime);

    const int &getDevice() const;
    void setDevice(const int &device);

private:
    int _source;
    int _number;
    int _device;
    float _inBufferStartTime;
    float _inDeviceStartTime;
    float _inSystemTime;
};

#endif // BID_H
