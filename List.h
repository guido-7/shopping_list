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
    List(const std::string& name);
    ~List();

    const std::string &getNameList() const;
    void setNameList(const std::string& NameList);
    const std::string &getNameItem(int Index) const;

    void add(const std::string& name, int quantity = 1, bool taken = false);
    void remove(const std::string& name);
    void changeQuantityItem(const std::string& name, int quantity);
    void changeNameItem(const std::string& oldName, const std::string& newName);
    void changeTakenItem(const std::string& name);
    void show();
    int size();

private:
    std::list<Item*> items;
    std::string nameList;
};


#endif //SHOPPING_LIST_LIST_H
