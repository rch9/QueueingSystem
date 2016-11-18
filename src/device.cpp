#include "device.h"
#include "randomhelper.h"

Device::Device(float lambda):
    Controller(),
    _lambda(lambda) {}

float Device::distributionLaw() {
    return RandomHelper::rand_exponential(_lambda);
}
