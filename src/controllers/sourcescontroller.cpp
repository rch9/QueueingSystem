#include "sourcescontroller.h"
#include <iostream>

SourcesController::SourcesController()
{

}

void SourcesController::init(const int &amount) {
    for(int i = 0; i < amount; ++i) {
        _sources.push_back(Source(1, 2));
        _sources.back().generateBid();
//        std::cout << _sources.back().getTime() << "\n";
    }
}


// FIXME: return Bid;
Source SourcesController::pullMinSource() {
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

//friend std::ostream &SourcesController::operator<<(std::ostream &os, const SourcesController &arg) {

//    os << "Sourses:\n";
//    for(auto it = arg._sources.begin(); it != arg._sources.end(); ++it) {
//        os << (*it).getTime() << "\n";
//    }
//    os << "\n";

//    return os;

//}

//std::ostream &SourcesController::operator<<(std::ostream &os) {
//    os << "Sourses:\n";
//    for(auto it = _sources.begin(); it != _sources.end(); ++it) {
//        os << (*it).getTime() << "\n";
//    }
//    os << "\n";
//}
