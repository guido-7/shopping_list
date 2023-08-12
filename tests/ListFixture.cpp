//
// Created by Guido Rossi on 12/08/2023.
//
#include "gtest/gtest.h"
#include "../List.h"

class ListSuite : public ::testing::Test {
protected:
    ListSuite() : c{"List1"}, sbuf{nullptr} {}
    ~ListSuite() override = default;

    virtual void SetUp() {
        sbuf = std::cout.rdbuf();
        std::cout.rdbuf(buffer.rdbuf());
    }
    void TearDown() override {
        std::cout.rdbuf(sbuf);
        sbuf = nullptr;
    }

    List c;
    std::stringstream buffer{};
    std::streambuf *sbuf;
};

TEST_F(ListSuite, TestFailAddItem) {
    std::string expected{"Quantity not valid\n"};
    c.add("Item1");
    buffer.str(""); // clear buffer
    buffer.clear();
    c.add("Item2",0);
    std::string actual{buffer.str()};
    ASSERT_EQ(expected, actual);

    buffer.str(""); // clear buffer
    buffer.clear();
    expected = "Name already used\n";
    c.add("Item1");
    actual = buffer.str();
    ASSERT_EQ(expected, actual);
}

TEST_F(ListSuite, TestFailRemoveItem) {
    std::string expected{"Item not find\n"};
    c.add("Item1");
    buffer.str(""); // clear buffer
    buffer.clear();
    c.remove("Item2");
    std::string actual{buffer.str()};
    ASSERT_EQ(expected, actual);
}

TEST_F(ListSuite, TestChangeQuantity) {
    std::string expected{"1)      | 2 | Item1\n"};
    c.add("Item1");
    c.changeQuantityItem("Item1",2);
    buffer.str(""); // clear buffer
    buffer.clear();
    c.show();
    std::string actual{buffer.str()};
    ASSERT_EQ(expected, actual);
}