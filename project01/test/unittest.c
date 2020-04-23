#include "file.h"
#include <test.h>

TEST_CASE(add_test)
{
    EXPECT_EQ(add(1,2),3);
    EXPECT_NEQ(add(1,2),4);
}

TEST_CASE(sub_test)
{
    EXPECT_EQ(sub(2,1),1);
    EXPECT_NEQ(sub(1,2),1);
}


UNIT_TEST
{
    TEST(add_test);
    TEST(sub_test);
}