#include "gtest/gtest.h"

extern "C"
{
    #include "student.h"
}

class StudentTestFixture : public ::testing ::Test
{
   protected:
    student stdnt_{};
    void SetUp() override
    {
        // init the student
        student_init(&stdnt_, "Max Mustermann");
    }
};

TEST_F(StudentTestFixture, initValid)
{
    ASSERT_STREQ("Max Mustermann", stdnt_.name);
}

TEST(StudentTest, initInValid)
{
    student_init(nullptr, "Maria");
}

TEST_F(StudentTestFixture, giveGrades)
{
    student_add_grade(&stdnt_, 5);
    student_add_grade(&stdnt_, 7);
    EXPECT_EQ(5, stdnt_.grades[0]);
    EXPECT_EQ(7, stdnt_.grades[1]);
}

TEST_F(StudentTestFixture, tooMuchGrades)
{
    for(int i = 0; i < 6; i++)
    {
        student_add_grade(&stdnt_, i);
    }
}

