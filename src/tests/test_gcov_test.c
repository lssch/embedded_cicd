#include "platform.h"

#if PL_CONFIG_USE_UNIT_TESTS
#include "test_gcov_test.h"
#include "gcov_test.h"
#include "unity/unity.h"

void TestGcov_Calc() {
    // Tests for Calc function
    TEST_ASSERT_EQUAL_INT(Calc(0, 0), 1);
    TEST_ASSERT_EQUAL_INT(Calc(1, 5), 6);
}

void TestGcov_Value() {
    TEST_ASSERT_EQUAL_INT(Value(3), 5);
    TEST_ASSERT_EQUAL_INT(Value(2), 1);
}

void TestGcov_Test2() {
    int i = 0;
    Test2(&i);
    TEST_ASSERT_EQUAL_INT(i, 0);

    i = 3;
    Test2(&i);
    TEST_ASSERT_EQUAL_INT(i, 3);

    i = 5;
    Test2(&i);
    TEST_ASSERT_EQUAL_INT(i, 5);
}

#endif /* PL_CONFIG_USE_UNIT_TESTS */