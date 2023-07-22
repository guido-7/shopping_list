//
// Created by Guido Rossi on 22/07/2023.
//

#ifndef SHOPPING_LIST_SCRATCHPAD_H
#define SHOPPING_LIST_SCRATCHPAD_H

#include <vector>
#include "List.h"

class scratchPad {
public:
    scratchPad();
    ~scratchPad();
private:
    std::vector<List*> lists;
};


#endif //SHOPPING_LIST_SCRATCHPAD_H
