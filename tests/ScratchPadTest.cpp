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