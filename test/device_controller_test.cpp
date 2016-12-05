#include "gtest/gtest.h"
#include "src/controllers/devicescontroller.h"
#include "src/buffer.h"
#include "src/timeableClasses/director.h"
#include <iostream>

/**
 * @brief TEST
 * Затестить на нулях
 */


TEST(DeviceControllerTest, hz) {

    DevicesController deviceController;
    deviceController.init({1, 2});

    deviceController.putBidToDevice(Bid(3.f, 0));
    deviceController.putBidToDevice(Bid(0.f, 1));

    std::cout << std::endl << deviceController << std::endl;

    Director::getInstance().setTime(2.f);
    deviceController.freeReadyDevices();

    std::cout << std::endl << deviceController << std::endl;
}
