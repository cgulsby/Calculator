#include "calculator.h"
#include "unity.h"
#include "unity_internals.h"
#include <limits.h>

// Optional, but needs to be defined (runs BEFORE each test)
void setUp(void) {
  // Initialize any resources you might need for tests here
  // Reset a global value, dynamically allocate memory, etc.
  // For this particular codebase, we don't need anything
}

// Optional, but needs to be defined (runs AFTER each test)
void tearDown(void) {
  // Clean up resources after each test
  // For example, free dynamically allocated memory, reset global values, etc.
  // For this particular codebase, we don't need anything
}

// addition tests
void test_add(void) {

  // positive numbers
  TEST_ASSERT_EQUAL(5, add(2, 3)); // We expect 2 + 3 = 5

  // positive and negative numbers
  TEST_ASSERT_EQUAL(1, add(5, -4)); // Expect 5 + (-4) = 1

  // negative numbers
  TEST_ASSERT_EQUAL(-7, add(-3, -4)); // We expect (-3) + (-4) = -7

  // adding zeros
  TEST_ASSERT_EQUAL(10, add(10, 0)); // We expect 10 + 0 = 0
  TEST_ASSERT_EQUAL(0, add(0, 0));   // We expect 0 + 0 = 0

  // overflow
  int result =
      add(INT_MAX, 1); // Should wrap around or cause undefined behavior
  TEST_ASSERT_TRUE(result < 0); // Checks if overflow occurred

  // underflow
  int result2 = add(INT_MIN, -1);
  TEST_ASSERT_TRUE(result2 > 0); // Checks if underflow occurred
}

// subtraction tests
void test_subtract(void) {

  // positive numbers
  TEST_ASSERT_EQUAL(3, subtract(6, 3)); // We expect 6 - 3 = 2

  // positive and negative numbers
  TEST_ASSERT_EQUAL(9, subtract(5, -4)); // Expect 5 - (-4) = 9

  // negative numbers
  TEST_ASSERT_EQUAL(1, subtract(-3, -4)); // We expect (-3) - (-4) = 1

  // subtract zeros
  TEST_ASSERT_EQUAL(10, subtract(10, 0)); // We expect 10 - 0 = 10
  TEST_ASSERT_EQUAL(0, subtract(0, 0));   // We expect 0 - 0 = 0

  // overflow
  int result =
      subtract(INT_MAX, -1); // Should wrap around or cause undefined behavior
  TEST_ASSERT_TRUE(result < 0); // Checks if overflow occurred

  // underflow
  int result2 = subtract(INT_MIN, 1);
  TEST_ASSERT_TRUE(result2 > 0); // Checks if underflow occurred
}

void test_multiply(void) {
  // positive numbers
  TEST_ASSERT_EQUAL(25, multiply(5, 5)); // 5 * 5 = 25
  TEST_ASSERT_EQUAL(15, multiply(5, 3)); // 5 * 3 = 15

  // negative numbers
  TEST_ASSERT_EQUAL(-5, multiply(5, -1)); // 5 * -1 = -5
  TEST_ASSERT_EQUAL(-1, multiply(1, -1)); // 1 * -1 = -1

  // by one
  TEST_ASSERT_EQUAL(5, multiply(5, 1)); // 5 * 1 = 5
  TEST_ASSERT_EQUAL(1, multiply(1, 1)); // 1 * 1 = 5

  // by zero
  TEST_ASSERT_EQUAL(0, multiply(5, 0)); // 5 * 0 = 0
  TEST_ASSERT_EQUAL(0, multiply(0, 0)); // 0 * 0 = 0
  TEST_ASSERT_EQUAL(0, multiply(1, 0)); // 1 * 0 = 0

  // overflow
  int result =
      multiply(INT_MAX, 2); // Should wrap around or cause undefined behavior
  TEST_ASSERT_TRUE(result < 0); // Checks if overflow occurred

  // underflow
  int result2 = multiply(INT_MIN, 2);
  TEST_ASSERT_TRUE(result2 == 0); // Checks if underflow occurred
}

void test_divide(void) {
  // positive numbers
  TEST_ASSERT_EQUAL(2, divide(4, 2));  // 4 / 2 = 2
  TEST_ASSERT_EQUAL(3, divide(18, 6)); // 18 / 6 = 3

  // positive and negative numbers
  TEST_ASSERT_EQUAL(-2, divide(-4, 2));  // -4 / 2 = -2
  TEST_ASSERT_EQUAL(-3, divide(18, -6)); // 18 / 6 = -3

  // negative numbers
  TEST_ASSERT_EQUAL(5, divide(-5, -1));  // -5 / -1 = 5
  TEST_ASSERT_EQUAL(3, divide(-18, -6)); // -18 / -6 = 3

  // by numbers' selves
  TEST_ASSERT_EQUAL(1, divide(2, 2)); // 2 / 2 = 1
  TEST_ASSERT_EQUAL(1, divide(1, 1)); // 1 / 1 = 1

  // zero as the dividend
  TEST_ASSERT_EQUAL(0, divide(0, 2));   // 0 / 2 = 0
  TEST_ASSERT_EQUAL(0, divide(0, 100)); // 0 / 100 = 0

  // zero as the divisor
  int result = divide(4, 0);
  TEST_ASSERT_TRUE(result == -1);
}

int main(void) {
  UNITY_BEGIN();

  // +
  RUN_TEST(test_add);

  // -
  RUN_TEST(test_subtract);

  // *
  RUN_TEST(test_multiply);

  // /
  RUN_TEST(test_divide);
  return UNITY_END();
}
