//
// Created by Guido Rossi on 14/08/2023.
//
#include "gtest/gtest.h"
#include "../Item.h"

class ItemSuite : public ::testing::Test {
protected:
    ItemSuite() : i{"Item1"}, sbuf{nullptr} {}
    ~ItemSuite() override = default;

    virtual void SetUp() {
        sbuf = std::cout.rdbuf();
        std::cout.rdbuf(buffer.rdbuf());
    }

    void TearDown() override {
        std::cout.rdbuf(sbuf);
        sbuf = nullptr;
    }

    Item i;
    std::stringstream buffer{};
    std::streambuf *sbuf;
};

TEST_F(ItemSuite, TestShow){
    std::string expected{"    | 1 | Item1\n"};
    i.show();
    std::string actual{buffer.str()};
    ASSERT_EQ(expected, actual);
}