#include "sourcescontroller.h"

SourcesController::SourcesController()
{

}

void SourcesController::init(const int &amount) {
    for(int i = 0; i < amount; ++i) {
        _sources.push_back(Source(1, 2));
    }
}
