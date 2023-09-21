//
// Created by Guido Rossi on 14/08/2023.
//
#include "gtest/gtest.h"
#include "../List.h"

TEST(Item, DefaultConstructor) {
    auto *L = new List("List1");
    Item i(L, "Item1");
    ASSERT_EQ("Item1", i.getName());
    ASSERT_EQ(1, i.getQuantity());
    ASSERT_FALSE(i.isTaken());
}

TEST(Item, TestCopyConstructor) {
    auto *L = new List("List1");
    Item i(L, "Item1", 2, true);
    Item j(i);
    ASSERT_EQ(i.getName(), j.getName());
    ASSERT_EQ(i.getQuantity(), j.getQuantity());
    ASSERT_EQ(i.isTaken(), j.isTaken());
}

TEST(Item, TestAssignmentOperator) {
    auto *L = new List("List1");
    Item i(L, "Item1", 2, true);
    Item j(L, "Item2");
    j = i;
    ASSERT_EQ(i.getName(), j.getName());
    ASSERT_EQ(i.getQuantity(), j.getQuantity());
    ASSERT_EQ(i.isTaken(), j.isTaken());
}

TEST(Item, TestSetName) {
    auto *L = new List("List1");
    Item i(L, "Item1");
    i.setName("Item2");
    ASSERT_EQ("Item2", i.getName());
}

TEST(Item, TestSetQuantity) {
    auto *L = new List("List1");
    Item i(L, "Item1");
    i.setQuantity(2);
    ASSERT_EQ(2, i.getQuantity());
}

TEST(Item, TestSetTaken) {
    auto *L = new List("List1");
    Item i(L, "Item1");
    i.setTaken(true);
    ASSERT_TRUE(i.isTaken());
}