//
// Created by Guido Rossi on 10/08/2023.
//
#include "gtest/gtest.h"
#include "../ScratchPad.h"


TEST(ScratchPad, DefaultConstructor) {
    ScratchPad c;
    ASSERT_EQ(0, c.size());
    ASSERT_EQ(0, c.getIndexListOpen());
}

TEST(ScratchPad, TestAddList) {
    ScratchPad c;
    c.addList("List1");
    ASSERT_EQ(1, c.size());
    ASSERT_EQ(2, c.getIndexListOpen());
    c.addList("List2");
    ASSERT_EQ(2, c.size());
    ASSERT_EQ(3, c.getIndexListOpen());
}