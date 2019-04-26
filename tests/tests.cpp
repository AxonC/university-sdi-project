#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "pch.h"

#include <lib/spdlog/sinks/null_sink.h>

int main(int argc, char** argv) {
    // sets logger to null so that no files are created.
    auto logger = spdlog::null_logger_mt("logger");

    // The following line must be executed to initialize Google Mock
    // (and Google Test) before running the tests.
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}