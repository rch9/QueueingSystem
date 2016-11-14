#include "gtest/gtest.h"
#include "src/buffer.h"

/**
 * @brief TEST
 * Затестить на нулях
 */


TEST(BufferTest, putBid) {
    Buffer buffer(4);
    buffer.putBid(Bid(0, 0));
    buffer.putBid(Bid(0, 1));
    buffer.putBid(Bid(0, 2));
    buffer.putBid(Bid(0, 3));
    buffer.putBid(Bid(0, 4));
    buffer.putBid(Bid(0, 4));
    buffer.putBid(Bid(0, 41));
    EXPECT_EQ(buffer.size(), 4);

    EXPECT_EQ(buffer.popBid().getSource(), 0);
    EXPECT_EQ(buffer.size(), 3);
    EXPECT_EQ(buffer.popBid().getSource(), 1);
    EXPECT_EQ(buffer.size(), 2);
    EXPECT_EQ(buffer.popBid().getSource(), 2);
    EXPECT_EQ(buffer.size(), 1);
    EXPECT_EQ(buffer.popBid().getSource(), 41);
    EXPECT_EQ(buffer.size(), 0);
}

//TEST(BufferTest1, Negative) {
////    EXPECT_EQ(1, 1);
//}

//TEST(BufferTest2, Negative) {
////    EXPECT_EQ(1, 1);
//}



