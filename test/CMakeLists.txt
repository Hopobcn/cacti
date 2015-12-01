
include_directories(${GTEST_INCLUDE_DIR} ${GMOCK_INCLUDE_DIR})
add_executable(cacti-tests cacti-tests.cpp)
target_link_libraries(cacti-tests libcacti ${CMAKE_THREAD_LIBS_INIT} ${GTEST_LIBRARY} ${GMOCK_LIBRARY})
add_test(NAME cacti-tests
         COMMAND cacti-tests)