#include "calculator.h"
#include "unity.h"
#include "unity_internals.h"

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
  TEST_ASSERT_EQUAL(10, add(10, 0)); // We expect (-3) + (-4) = -7
  TEST_ASSERT_EQUAL(0, add(0, 0));   // We expect (-3) + (-4) = -7
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_add_positive_numbers);
  RUN_TEST(test_add_positive_and_negative_numbers);
  RUN_TEST(test_add_negative_numbers);
  RUN_TEST(test_add_zero);
  return UNITY_END();
}
