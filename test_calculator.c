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

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_add_positive_numbers);
  return UNITY_END();
}
