//
// Created by Guido Rossi on 21/07/2023.
//

#ifndef SHOPPING_LIST_LIST_H
#define SHOPPING_LIST_LIST_H

#include <iostream>
#include <list>
#include "Item.h"

class List : public Observer {
public:
    List(const std::string& name);
    virtual ~List();

    const std::string &getNameList() const;
    void setNameList(const std::string& NameList);
    const std::string &getNameItem(int Index) const;
    const int getItemToBuy() const;

    void add();
    void add(const std::string& name, int quantity = 1, bool taken = false);
    void remove();
    void remove(const std::string& name);
    void changeQuantityItem(const std::string& name, int quantity);
    void changeNameItem(const std::string& oldName, const std::string& newName);
    void changeTakenItem(const std::string& name);
    void show();
    int size();

    //observer
    virtual void update(int x) override;
private:
    std::list<Item*> items;
    std::string nameList;
    int itemToBuy;
};


#endif //SHOPPING_LIST_LIST_H
