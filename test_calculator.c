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
void test_add_positive_numbers(void) {
  TEST_ASSERT_EQUAL(5, add(2, 3)); // We expect 2 + 3 = 5
}

void test_add_positive_and_negative_numbers(void) {
  TEST_ASSERT_EQUAL(1, add(5, -4)); // Expect 5 + (-4) = 1
}

void test_add_negative_numbers(void) {
  TEST_ASSERT_EQUAL(-7, add(-3, -4)); // We expect (-3) + (-4) = -7
}

void test_add_zero(void) {
  TEST_ASSERT_EQUAL(10, add(10, 0)); // We expect 10 + 0 = 0
  TEST_ASSERT_EQUAL(0, add(0, 0));   // We expect 0 + 0 = 0
}

void test_add_overflow(void) {
  int result =
      add(INT_MAX, 1); // Should wrap around or cause undefined behavior
  TEST_ASSERT_TRUE(result < 0); // Checks if overflow occurred
}

void test_add_underflow(void) {
  int result = add(INT_MIN, -1);
  TEST_ASSERT_TRUE(result > 0); // Checks if underflow occurred
}
// subtraction tests
void test_add_subtract(void) {
  TEST_ASSERT_EQUAL(3, subtract(6, 3)); // We expect 6 - 3 = 2
}

int main(void) {
  UNITY_BEGIN();

  // +
  RUN_TEST(test_add_positive_numbers);
  RUN_TEST(test_add_positive_and_negative_numbers);
  RUN_TEST(test_add_negative_numbers);
  RUN_TEST(test_add_zero);
  RUN_TEST(test_add_overflow);
  RUN_TEST(test_add_underflow);

  // -
  RUN_TEST(test_add_subtract);
  return UNITY_END();
}
