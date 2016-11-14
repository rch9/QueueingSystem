#include "controller.h"

Controller::Controller()
{

}

void Controller::addServiceTime() {
    _time += distributionLaw();
}
