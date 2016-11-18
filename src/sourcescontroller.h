#ifndef SOURCECONTROLLER_H
#define SOURCECONTROLLER_H

#include <list>
#include "source.h"


class SourcesController
{
public:
    SourcesController();

private:
    std::list<Source> _sources;
};

#endif // SOURCECONTROLLER_H
