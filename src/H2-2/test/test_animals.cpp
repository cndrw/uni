#include "gtest/gtest.h"
#include "animals.hpp"

TEST(AnimalTest, initSpider)
{
    Spider s;
    EXPECT_EQ(8, s.get_feet_amount());
}

TEST(AnimalTest, initMammal)
{
    for(int i = 0; i < 10; i++)
    {
        Mammal m(i);
        EXPECT_EQ(i, m.get_feet_amount());
    }
}
