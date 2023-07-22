//
// Created by Guido Rossi on 21/07/2023.
//

#ifndef SHOPPING_LIST_LIST_H
#define SHOPPING_LIST_LIST_H

#include <iostream>
#include <list>
#include "Item.h"

class List {
public:
    List();
    ~List();

    void add(const std::string& name, int quantity = 1);
    void show();

private:
    std::list<Item> items;
};


#endif //SHOPPING_LIST_LIST_H
