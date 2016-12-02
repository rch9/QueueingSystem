#ifndef SOURCECONTROLLER_H
#define SOURCECONTROLLER_H

#include <list>
#include "source.h"


// Надо потом отнаследовать init

class SourcesController
{
public:
    SourcesController();

    void init(const int &amount);

    /**
     * @brief pullBid
     * @return
     *
     * Вытаскивает самый подходящий по времени поток
     */
    Source pullMinSource();
    float pullMinSourceTime();

private:
    std::list<Source> _sources;
};

#endif // SOURCECONTROLLER_H
