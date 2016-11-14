#ifndef SOURCE_H
#define SOURCE_H

#include "controller.h"


class Source : public Controller {
public:
    Source();
private:
    float distributionLaw();
};

#endif // SOURCE_H
