cmake_minimum_required(VERSION 3.14)
project(offgrass_tests)

set(CMAKE_CXX_STANDARD 14)

enable_testing()

add_executable(
    tile_test
    tile_test.cc
    ../src/tile.cpp
)
target_include_directories(tile_test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../src)
target_link_libraries(
    tile_test
    GTest::gtest_main
)

add_executable(
    grid_test
    grid_test.cc
    ../src/position.cpp
    ../src/tile.cpp
    ../src/grid.cpp
    ../src/gridinfo.cpp
)
target_include_directories(grid_test PUBLIC ../src)
target_link_libraries(
    grid_test
    GTest::gtest_main
)

include(cmake/googletest)
include(GoogleTest)

gtest_discover_tests(tile_test)
gtest_discover_tests(grid_test)
