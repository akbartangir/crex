# crex
CRypto EXchange

A C++ project demonstrating crypto exchange functionality with CMake and Google Test.

## Project Structure

```
crex/
├── include/          # Header files
│   └── exchange.h
├── src/              # Source files
│   ├── exchange.cpp
│   └── main.cpp
├── tests/            # Unit tests
│   ├── CMakeLists.txt
│   └── exchange_test.cpp
└── CMakeLists.txt    # Main CMake configuration
```

## Building the Project

### Prerequisites

- CMake (version 3.14 or higher)
- C++ compiler with C++17 support (e.g., GCC, Clang, MSVC)
- Internet connection (for downloading Google Test)

### Build Instructions

```bash
# Create build directory
mkdir build
cd build

# Configure the project
cmake ..

# Build the project
cmake --build .

# Run tests
ctest --verbose

# Or run the test executable directly
./tests/crex_test

# Run the main application
./crex
```

## Testing

The project uses Google Test framework for unit testing. Tests are automatically downloaded and configured by CMake using FetchContent.

To run all tests:
```bash
cd build
ctest --verbose
```

## Features

- **Exchange Class**: Basic cryptocurrency exchange implementation
  - Get/Set balances for different currencies
  - Add to existing balances
  - Check if a currency exists
- **Comprehensive Unit Tests**: Full test coverage using Google Test
- **Modern C++17**: Uses modern C++ features and best practices
- **CMake Build System**: Cross-platform build configuration
