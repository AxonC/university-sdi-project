#ifndef TREKSTAR_TESTCASE_H
#define TREKSTAR_TESTCASE_H

#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace TrekStarTests
{
    namespace Tests
    {
        class TestCase : public ::testing::Test
        {
        public:
            TestCase() : Test() {}

            // surpresses console output by redirecting the std::cout stream
            virtual void SetUp() override {
                storedStreambuf_ = std::cout.rdbuf();
                std::cout.rdbuf(nullptr);
            }

            virtual void TearDown() override {
                std::cout.rdbuf(storedStreambuf_);
            }

            std::streambuf* storedStreambuf_;
        };
    }
}

#endif //TREKSTAR_TESTCASE_H
