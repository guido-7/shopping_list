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
    expected = "Name already used\n";
    buffer.str(""); // clear buffer
    buffer.clear();
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

TEST_F(ListSuite, TestFailChangeQuantity) {
    std::string expected{"Quantity not updated. Item not find\n"};
    c.add("Item1");
    buffer.str(""); // clear buffer
    buffer.clear();
    c.changeQuantityItem("Item2",2);
    std::string actual{buffer.str()};
    ASSERT_EQ(expected, actual);
    expected= "Quantity not updated. Quantity not valid\n";
    buffer.str(""); // clear buffer
    buffer.clear();
    c.changeQuantityItem("Item1",0);
    actual = buffer.str();
    ASSERT_EQ(expected, actual);
}

TEST_F(ListSuite, TestChangeNameItem) {
    std::string expected{"1)      | 1 | Item2\n"};
    c.add("Item1");
    c.changeNameItem("Item1","Item2");
    buffer.str(""); // clear buffer
    buffer.clear();
    c.show();
    std::string actual{buffer.str()};
    ASSERT_EQ(expected, actual);
}

TEST_F(ListSuite, TestFailChangeNameItem) {
    std::string expected{"Name not updated. Item not find\n"};
    c.add("Item1");
    c.add("Item2");
    buffer.str(""); // clear buffer
    buffer.clear();
    c.changeNameItem("Item3","Item4");
    std::string actual{buffer.str()};
    ASSERT_EQ(expected, actual);
    expected= "Name not updated. Name already used\n";
    buffer.str(""); // clear buffer
    buffer.clear();
    c.changeNameItem("Item1","Item2");
    actual = buffer.str();
    ASSERT_EQ(expected, actual);
}

TEST_F(ListSuite, TestChangeTaken) {
    std::string expected{"1)   X  | 1 | Item1\n"};
    c.add("Item1");
    c.changeTakenItem("Item1");
    buffer.str(""); // clear buffer
    buffer.clear();
    c.show();
    std::string actual{buffer.str()};
    ASSERT_EQ(expected, actual);
    expected = "1)      | 1 | Item1\n";
    c.changeTakenItem("Item1");
    buffer.str(""); // clear buffer
    buffer.clear();
    c.show();
    actual = buffer.str();
    ASSERT_EQ(expected, actual);
    expected = "1)      | 1 | Item1\n2)   X  | 1 | Item2\n";
    c.add("Item2",1,true);
    buffer.str(""); // clear buffer
    buffer.clear();
    c.show();
    actual = buffer.str();
    ASSERT_EQ(expected, actual);
}

TEST_F(ListSuite, TestFailChangeTaken) {
    std::string expected{"Taken not updated. Item not find\n"};
    c.add("Item1");
    buffer.str(""); // clear buffer
    buffer.clear();
    c.changeTakenItem("Item2");
    std::string actual{buffer.str()};
    ASSERT_EQ(expected, actual);
}