//
// Created by Guido Rossi on 12/08/2023.
//
#include "gtest/gtest.h"
#include "../List.h"

TEST(List, DefaultConstructor) {
    List c("List1");
    ASSERT_EQ("List1", c.getNameList());
    ASSERT_EQ(0, c.size());
}

TEST(List, TestSetNameList) {
    List c("List1");
    c.setNameList("List2");
    ASSERT_EQ("List2", c.getNameList());
}

TEST(List, TestAddItem) {
    List c("List1");
    c.add("Item1");
    ASSERT_EQ(1, c.size());
    c.add("Item2");
    ASSERT_EQ(2, c.size());
    c.add("Item2");
    ASSERT_EQ(2, c.size());
}

TEST(List, TestAddItem2) {
    List c("List1");
    bool v = c.add("Item1");
    ASSERT_EQ(false, v);
}

TEST(List, TestFailAddItem) {
    List c("List1");
    bool v = c.add("Item1", 0);
    ASSERT_EQ(true, v);
}

TEST(List, TestRemoveItem) {
    List c("List1");
    c.add("Item1");
    c.add("Item2");
    c.add("Item3");
    c.remove("Item2");
    ASSERT_EQ(2, c.size());
    c.remove("Item4");
    ASSERT_EQ(2, c.size());
}