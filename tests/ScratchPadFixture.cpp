//
// Created by Guido Rossi on 10/08/2023.
//
#include "gtest/gtest.h"
#include "../ScratchPad.h"

class ScratchPadSuite : public ::testing::Test {

protected:
    ScratchPadSuite() : sbuf{nullptr} {}
    ~ScratchPadSuite() override = default;

    virtual void SetUp() {
        sbuf = std::cout.rdbuf();
        std::cout.rdbuf(buffer.rdbuf());
    }
    void TearDown() override {
        std::cout.rdbuf(sbuf);
        sbuf = nullptr;
    }

    ScratchPad c;
    std::stringstream buffer{};
    std::streambuf *sbuf;
};