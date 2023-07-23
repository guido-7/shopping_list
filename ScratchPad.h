//
// Created by Guido Rossi on 22/07/2023.
//

#ifndef SHOPPING_LIST_SCRATCHPAD_H
#define SHOPPING_LIST_SCRATCHPAD_H

#include <iostream>
#include <vector>
#include "List.h"

class ScratchPad {
public:
    ScratchPad();
    ~ScratchPad();

    void addList(const std::string& Name);
    void removeList(const std::string& Name);
    void removeList(int N);
    void showLists() const;
private:
    std::vector<List*> lists;
};


#endif //SHOPPING_LIST_SCRATCHPAD_H
