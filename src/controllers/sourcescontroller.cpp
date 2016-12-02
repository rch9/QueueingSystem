#include "sourcescontroller.h"
#include <iostream>

SourcesController::SourcesController()
{

}

void SourcesController::init(const int &amount) {
    for(int i = 0; i < amount; ++i) {
        _sources.push_back(Source(-10, 200));
        _sources.back().generateBid();
    }
}

Source &SourcesController::pullMinSource() {
    auto minIt = _sources.begin();
    for(auto it = _sources.begin(); it != _sources.end(); ++it) {
        if ((*it).getTime() < (*minIt).getTime()) {
            minIt = it;
        }
    }

    return *minIt;
}

float SourcesController::pullMinSourceTime() {
    return pullMinSource().getTime();
}

Bid SourcesController::pullMinSourceBid() {
    return pullMinSource().generateBid();
}
