cmake_minimum_required(VERSION 3.10)
project(RobotDraw LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable CTest
enable_testing()

# Main executable
add_executable(robot
    src/main.cpp
    src/Grid.cpp
    src/Robot.cpp
    src/CommandFactory.cpp
    src/Commands.cpp
)
target_include_directories(robot PRIVATE src)

# GoogleTest
add_subdirectory(external/googletest-main)

# Tests
add_executable(tests
    tests/GridTest.cpp
    tests/RobotTest.cpp
    tests/CommandFactoryTest.cpp
    tests/CommandsTest.cpp
    src/Grid.cpp
    src/Robot.cpp
    src/CommandFactory.cpp
    src/Commands.cpp
)

target_include_directories(tests PRIVATE src)
target_link_libraries(tests PRIVATE gtest gtest_main)

# Auto-discover tests
include(GoogleTest)
gtest_discover_tests(tests)