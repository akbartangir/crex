enable_testing()

# Test executable
add_executable(
  crex_test
  exchange_test.cpp
)

# Link against gtest, gtest_main, and the library
target_link_libraries(
  crex_test
  GTest::gtest_main
  crex_lib
)

# Discover tests
include(GoogleTest)
gtest_discover_tests(crex_test)
