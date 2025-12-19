cmake_minimum_required(VERSION 3.14)
project(crex VERSION 0.1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Source files
set(SOURCES
    src/exchange.cpp
)

# Create library
add_library(crex_lib ${SOURCES})
target_include_directories(crex_lib PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Create executable
add_executable(crex src/main.cpp)
target_link_libraries(crex crex_lib)

# Enable testing
enable_testing()

# Add Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.14.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Add tests subdirectory
add_subdirectory(tests)
