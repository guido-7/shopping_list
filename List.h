//
// Created by Guido Rossi on 21/07/2023.
//

#ifndef SHOPPING_LIST_LIST_H
#define SHOPPING_LIST_LIST_H

#include <iostream>
#include <memory>
#include <list>
#include "Item.h"
#include "Subject.h"

class List : public Subject{
public:
    List(const std::string& name);
    virtual ~List();

    const std::string &getNameList() const;
    void setNameList(const std::string& NameList);
    const std::string &getNameItem(int Index) const;
    const int getItemToBuy() const;

    bool add(const std::string& name, int quantity = 1, bool taken = false);
    bool remove(const std::string& name);
    bool changeQuantityItem(const std::string& name, int quantity);
    bool changeNameItem(const std::string& oldName, const std::string& newName);
    bool changeTakenItem(const std::string& name);
    void show() const;
    int size() const;

    //Subject
    virtual void subscribe(Observer* o) override;
    virtual void unsubscribe(Observer* o) override;
    virtual void notify() override;
private:
    std::list<std::unique_ptr<Item>> items;
    std::string nameList;
    int itemToBuy;
    std::list<Observer*> observers;
};


#endif //SHOPPING_LIST_LIST_H
