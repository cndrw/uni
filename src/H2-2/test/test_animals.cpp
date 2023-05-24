#include "animals.hpp"
#include "gtest/gtest.h"

class AnimalTestFixture : public ::testing ::Test
{
   protected:
    Spider spider_ = Spider(1);
    Mammal mammal_ = Mammal(4, 2);
    void SetUp() override
    {
        // init the student
    }
};

TEST(AnimalTest, initSpider)
{
    Spider s(2.2);
    EXPECT_EQ(8, s.get_feet_amount());
}

TEST(AnimalTest, initMammal)
{
    Mammal m(2, 4.0);
    EXPECT_EQ(2, m.get_feet_amount());
}

TEST_F(AnimalTestFixture, moveTest)
{
    mammal_.move(4);
    EXPECT_EQ(8, mammal_.xpos_);
    EXPECT_EQ(8, mammal_.ypos_);

    spider_.move(2);
    EXPECT_EQ(2, spider_.xpos_);
    EXPECT_EQ(2, spider_.ypos_);
}
