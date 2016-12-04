#include "gtest/gtest.h"
#include "src/controllers/devicescontroller.h"
#include "src/buffer.h"

#include <iostream>

/**
 * @brief TEST
 * Затестить на нулях
 */


TEST(DeviceControllerTest, hz) {
    Buffer buffer;
    buffer.init(3);

    DevicesController deviceController;
    deviceController.init(3);

    std::cout << std::endl << buffer << std::endl;
    std::cout << std::endl << deviceController << std::endl;

    buffer.putBid(Bid());
    buffer.putBid(Bid());
    buffer.putBid(Bid());

    std::cout << std::endl << buffer << std::endl;

    deviceController.putBidToDevice(buffer.popBid());
    deviceController.putBidToDevice(buffer.popBid());
    deviceController.putBidToDevice(buffer.popBid());

    std::cout << std::endl << deviceController << std::endl;
}
