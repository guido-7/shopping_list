//
// Created by Guido Rossi on 14/08/2023.
//
#include "gtest/gtest.h"
#include "../List.h"

TEST(Item, DefaultConstructor) {
    Item i("Item1");
    ASSERT_EQ("Item1", i.getName());
    ASSERT_EQ(1, i.getQuantity());
    ASSERT_FALSE(i.isTaken());
}

TEST(Item, TestCopyConstructor) {
    Item i("Item1", 2, true);
    Item j(i);
    ASSERT_EQ(i.getName(), j.getName());
    ASSERT_EQ(i.getQuantity(), j.getQuantity());
    ASSERT_EQ(i.isTaken(), j.isTaken());
}