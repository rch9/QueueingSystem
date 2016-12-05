#include "sourcescontroller.h"
#include <iostream>

SourcesController::SourcesController()
{

}

void SourcesController::init(const int &amount) {
    for(int i = 0; i < amount; ++i) {
        _sources.push_back(Source(-0.5, 1, i));
        _sources.back().generateBid();
    }
}

void SourcesController::init(std::initializer_list<float> args) {
    for (int i = 0; i < args.size(); i += 2) {
        _sources.push_back(Source(*(args.begin()+i), *(args.begin()+i+1), i / 2));
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

float SourcesController::getMinSourceTime() {
    return pullMinSource().getTime();
}

Bid SourcesController::pullMinSourceBid() {
    return pullMinSource().generateBid();
}
