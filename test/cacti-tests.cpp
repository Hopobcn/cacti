//
// Created by pfarre on 26/11/15.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <io.hpp>

TEST(cacti, main) {
    string infile_name("config/cache.cfg");

    cacti_interface(infile_name);

    //TODO compare result with a 'reference-result'
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleMock(&argc, argv);
    int ret = RUN_ALL_TESTS();
    return ret;
}