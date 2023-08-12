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

TEST_F(ScratchPadSuite, TestFailRemoveList) {
    std::string expected{"List not find\n"};
    c.addList("List1");
    c.addList("List2");
    c.removeList("List3");
    std::string actual{buffer.str()};
    ASSERT_EQ(expected, actual);
}

TEST_F(ScratchPadSuite, TestAddItem) {
    std::string expected{"1)      | 1 | Item1\n"};
    c.addList("List1");
    c.setIndexListOpen(0);
    c.addItem("Item1");
    buffer.str("");
    buffer.clear();
    c.showItems();
    std::string actual{buffer.str()};
    c.closeListOpen();
    ASSERT_EQ(expected, actual);
}

TEST_F(ScratchPadSuite, TestRemoveItem) {
    std::string expected{"1)      | 1 | Item1\n"};
    c.addList("List1");
    c.setIndexListOpen(0);
    c.addItem("Item1");
    c.addItem("Item2");
    c.removeItem("Item2");
    buffer.str("");
    buffer.clear();
    c.showItems();
    std::string actual{buffer.str()};
    c.closeListOpen();
    ASSERT_EQ(expected, actual);
}

TEST_F(ScratchPadSuite, TestFailRemoveItem) {
    std::string expected{"Item not find\n"};
    c.addList("List1");
    c.setIndexListOpen(0);
    c.addItem("Item1");
    buffer.str("");
    buffer.clear();
    c.removeItem("Item2");
    std::string actual{buffer.str()};
    c.closeListOpen();
    ASSERT_EQ(expected, actual);
}

TEST_F(ScratchPadSuite, TestSelectItem) {
    std::string expected{"1)   X  | 1 | Item1\n"};
    std::stringstream input("1\n"); // simulate user input
    std::streambuf* originalCin = std::cin.rdbuf(input.rdbuf()); // redirect std::cin to input stringstream
    c.addList("List1");
    c.setIndexListOpen(0);
    c.addItem("Item1");
    c.selectItem();
    buffer.str(""); // clear buffer
    buffer.clear();
    c.showItems();
    std::string actual{buffer.str()}; // get buffer content
    c.closeListOpen();
    std::cin.rdbuf(originalCin);
    ASSERT_EQ(expected, actual);
}

TEST_F(ScratchPadSuite, TestFailSelectItem) {
    std::string expected{"Item not find\n"};
    std::stringstream input("3\n 1\n"); // simulate user input
    std::streambuf* originalCin = std::cin.rdbuf(input.rdbuf()); // redirect std::cin to input stringstream
    c.addList("List1");
    c.setIndexListOpen(0);
    c.addItem("Item1");
    buffer.str(""); // clear buffer
    buffer.clear();
    c.selectItem();
    c.closeListOpen();
    std::string actual{buffer.str()}; // get buffer content
    std::cin.rdbuf(originalCin); // restore std::cin
    ASSERT_EQ(expected, actual);
}