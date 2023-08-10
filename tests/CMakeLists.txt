cmake_minimum_required(VERSION 3.25)

add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTests.cpp ScratchPadTest.cpp ScratchPadFixture.cpp)
add_executable(runScratchPadTests ${TEST_SOURCE_FILES})
target_link_libraries(runScratchPadTests gtest gtest_main core)