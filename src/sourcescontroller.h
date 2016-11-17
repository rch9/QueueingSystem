#ifndef SOURCECONTROLLER_H
#define SOURCECONTROLLER_H

#include <vector>
#include "source.h"


class SourcesController
{
public:
    SourcesController();

private:
    std::vector<Source> _sources;
};

#endif // SOURCECONTROLLER_H
