#ifndef SOURCECONTROLLER_H
#define SOURCECONTROLLER_H

#include "../timeableClasses/source.h"
#include "ostream"
#include <list>

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

    friend std::ostream& operator<< (std::ostream& os, const SourcesController& arg) {
        os << "Sourses:\n";
        for(auto it = arg._sources.begin(); it != arg._sources.end(); ++it) {
            os << (*it).getTime() << "\n";
        }

        return os;
    }

private:
    std::list<Source> _sources;
};



#endif // SOURCECONTROLLER_H
