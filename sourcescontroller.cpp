#include "sourcescontroller.h"
#include <iostream>

SourcesController::SourcesController() {
}

void SourcesController::init(std::vector<std::pair<float, float> > args) {
    for (auto arg : args) {
        _sources.push_back(Source(arg.first, arg.second, _sources.size()));
//        _sources.back().generateBid();
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

void SourcesController::initSources() {
    for (auto s : _sources) {
        s.generateBid();
    }
}

const std::list<Source> &SourcesController::getSources() const {
    return _sources;
}
