//
// Created by Guido Rossi on 21/07/2023.
//

#include "List.h"

List::List(const std::string& name) : nameList(name) {
    items.clear();
}

List::~List() {
    items.clear();
}

const std::string &List::getNameList() const {
    return nameList;
}

void List::setNameList(const std::string& NameList) {
    List::nameList = NameList;
}

const std::string &List::getNameItem(int Index) const {
    while(Index > items.size() || Index < 0){
        std::cout << "No items to this index. Insert valid index : ";
        std::cin >> Index;
        std::cin.ignore(100, '\n');
    }
    int j = 0;
    for (auto i : items){
        if(j == Index)
            return i->getName();
        j++;
    }
}

void List::add(const std::string& name, int quantity, bool taken) {
    if(quantity < 1){
        std::cout << "Quantity not valid" <<std::endl;
        return;
    }
    for(auto i : items){
        if(name == i->getName()) {
            std::cout << "Name already used" << std::endl;
            return;
        }
    }
    items.push_back(new Item(name, quantity, taken));
    std::cout << "Item added successfully" <<std::endl;
}

void List::remove(const std::string &name) {
    for(auto i : items){
        if(name == i->getName()) {
            items.remove(i);
            std::cout << "Item removed successfully" << std::endl;
            return;
        }
    }
    std::cout << "Item not find" <<std::endl;
}

void List::changeQuantityItem(const std::string& name, int quantity) {
    if(quantity < 1){
        std::cout << "Quantity not updated. Quantity not valid" <<std::endl;
        return;
    }
    for(auto i : items){
        if(name == i->getName()){
            i->setQuantity(quantity);
            std::cout << "Quantity updated" <<std::endl;
            return;
        }
    }
    std::cout << "Quantity not updated. Item not find" <<std::endl;
}

void List::changeNameItem(const std::string& oldName, const std::string& newName) {
    for(auto i : items){
        if(oldName == i->getName() && oldName == newName){
            std::cout << "Name updated" <<std::endl;
            return;
        }
        else if(oldName == i->getName()){
            for(auto j : items){
                if(newName == j->getName()){
                    std::cout << "Name not updated. Name already used" <<std::endl;
                    return;
                }
            }
            i->setName(newName);
            std::cout << "Name updated" <<std::endl;
            return;
        }
    }
    std::cout << "Name not updated. Item not find" <<std::endl;
}

void List::changeTakenItem(const std::string &name) {
    for(auto i : items){
        if(name == i->getName()){
            if(i->isTaken())
                i->setTaken(false);
            else
                i->setTaken(true);
            std::cout << "Taken updated" <<std::endl;
            return;
        }
    }
    std::cout << "Item not find" <<std::endl;
}

void List::show() {
    int j = 1;
    for(auto i : items){
        std::cout << j << ")  ";
        i->show();
        j++;
    }
    if(j == 1)
        std::cout << "No items in the list" <<std::endl;
}

int List::size() {
    return items.size();
}
