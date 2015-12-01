//
// Created by pfarre on 26/11/15.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <memory>

#include <io.hpp>

// RAII
class cout_redirect {
public:
    cout_redirect(std::streambuf* new_buffer)
            : old(std::cout.rdbuf(new_buffer)) {
    }

    ~cout_redirect() {
        std::cout.rdbuf(old);
    }

private:
    std::streambuf* old;
};

TEST(cacti, multiple_runs_same_output_cache) {
    string infile_name("config/cache.cfg");

    std::string a;
    {
        std::stringstream buffer;
        cout_redirect redirect(buffer.rdbuf());

        cacti_interface(infile_name);

        a = buffer.str();
    }

    std::string b;
    {
        std::stringstream buffer;
        cout_redirect redirect(buffer.rdbuf());

        cacti_interface(infile_name);

        b = buffer.str();
    }

    EXPECT_TRUE(a == b) << "First run:\n" << a << "Second run:\n" << b;
}

TEST(cacti, multiple_runs_same_output_dram) {
    string infile_name("config/dram.cfg");

    std::string a;
    {
        std::stringstream buffer;
        cout_redirect redirect(buffer.rdbuf());

        cacti_interface(infile_name);

        a = buffer.str();
    }

    std::string b;
    {
        std::stringstream buffer;
        cout_redirect redirect(buffer.rdbuf());

        cacti_interface(infile_name);

        b = buffer.str();
    }

    EXPECT_TRUE(a == b) << "First run:\n" << a << "Second run:\n" << b;
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleMock(&argc, argv);
    int ret = RUN_ALL_TESTS();
    return ret;
}