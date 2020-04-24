#include "calc.h"
#include <test.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MIN_BUF 10
#define MAX_BUF 100

int buf[MAX_BUF];
int len, add, mult;

int rand_int(int min, int max);

static void fill_buf();

TEST_CASE(test_avg)
{
    EXPECT_EQ(avg(buf,len), add / len);

    EXPECT_EQ(avg(NULL,len),0);

    EXPECT_EQ(avg(buf,0),0);
}

TEST_CASE(test_sum)
{
    EXPECT_EQ(sum(buf,len), add);

    EXPECT_EQ(sum(NULL,len),0);

    EXPECT_EQ(sum(buf,0),0);
}

TEST_CASE(test_prod)
{
    EXPECT_EQ(prod(buf,len), mult);

    EXPECT_EQ(prod(NULL,len),0);

    EXPECT_EQ(prod(buf,0),0);
}

UNIT_TEST
{
    srand((unsigned int)time(NULL));
    fill_buf();
    TEST(test_avg);
    TEST(test_sum);
    TEST(test_prod);
}

int rand_int(int min, int max)
{
    return min + rand() % (1 + max - min);
}

static void fill_buf()
{
    int pos;

    len = rand_int(MIN_BUF,MAX_BUF);
    
    add = 0;
    
    mult = 1;

    for(pos = 0; pos < len;pos++)
    {
        buf[pos] = rand_int(1,10000);
        buf[pos] *= (rand_int(0,1) % 2)?1:-1;
        add += buf[pos];
        mult *= buf[pos];
    }
}