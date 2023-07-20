//
// Created by Guido Rossi on 20/07/2023.
//

#ifndef SHOPPING_LIST_ITEM_H
#define SHOPPING_LIST_ITEM_H

#include <iostream>

class Item {
public:
    Item(const std::string& n);
    ~Item();

    void show();
private:
    std::string name;
};


#endif //SHOPPING_LIST_ITEM_H
