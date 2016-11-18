#ifndef SOURCE_H
#define SOURCE_H

#include "controller.h"


class Source : public Controller {
public:
    Source(float first, float second);
private:
    float distributionLaw();
private:
    float _first;
    float _second;
};

#endif // SOURCE_H
