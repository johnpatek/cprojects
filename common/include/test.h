#include <stdio.h>
#include <iocolors.h>

void eprint_result(int result);
void eprint_score(int passing, int total);

#define TEST_CASE(NAME)                                              \
static void NAME ## _function(int * const result);                   \
static int NAME ## _value()                                          \
{                                                                    \
    eprintf("%s: ",#NAME);                                           \
    int result = 1;                                                  \
    NAME ## _function(&result);                                      \
    eprint_result(result);                                           \
    return result;                                                   \
}                                                                    \
static void NAME ## _function(int * const result)                    \

#define EXPECT_RESULT(R)                                             \
*result = (*result) && (R)

#define EXPECT_EQ(A,B)                           EXPECT_RESULT(A == B)                    
#define EXPECT_NEQ(A,B)                          EXPECT_RESULT(A != B)                   
#define EXPECT_GT(A,B)                            EXPECT_RESULT(A > B)                    
#define EXPECT_GTE(A,B)                          EXPECT_RESULT(A >= B)                   
#define EXPECT_LT(A,B)                            EXPECT_RESULT(A > B)                    
#define EXPECT_LTE(A,B)                          EXPECT_RESULT(A >= B)                   

#define TEST(NAME)                                                   \
*passing += NAME##_value();                                          \
(*total)++

#define UNIT_TEST                                                    \
static void unit_test(                                               \
    int * const passing,                                             \
    int * const total);                                              \
int main()                                                           \
{                                                                    \
    int passing = 0, total = 0;                                      \
    unit_test(&passing,&total);                                      \
    eprint_score(passing,total);                                     \
    return 0;                                                        \
}                                                                    \
static void unit_test(                                               \
    int * const passing,                                             \
    int * const total)                                               \
    


