//
// Created by Guido Rossi on 22/07/2023.
//

#ifndef SHOPPING_LIST_SCRATCHPAD_H
#define SHOPPING_LIST_SCRATCHPAD_H

#include <iostream>
#include <vector>
#include <string>
#include "List.h"

class ScratchPad {
public:
    ScratchPad();
    ~ScratchPad();

    void addList();
    void addList(const std::string& Name);
    void removeList(const std::string& Name);
    void removeList(int N);
    void addItem();
    void addItem(const std::string& Name, int Quantity = 1, bool Taken = false);
    void removeItem(const std::string& Name);
    void showLists() const;
    void showItems() const;

    int getIndexListOpen() const;
    void setIndexListOpen(int indexListOpen);
    int size();

private:
    std::vector<List*> lists;
    int indexListOpen;
};


#endif //SHOPPING_LIST_SCRATCHPAD_H
