cmake_minimum_required(VERSION 3.25)

add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTests.cpp ScratchPadTest.cpp ScratchPadFixture.cpp ListTest.cpp ListFixture.cpp ItemTest.cpp)
add_executable(runAllLibTests ${TEST_SOURCE_FILES})
target_link_libraries(runAllLibTests gtest gtest_main core)