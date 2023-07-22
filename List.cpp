//
// Created by Guido Rossi on 21/07/2023.
//

#include "List.h"

List::List() {
    items.clear();
}

List::~List() {
    items.clear();
}

void List::add(const std::string& name, int quantity) {
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
    items.push_back(new Item(name, quantity));
    std::cout << "Item added successfully" <<std::endl;
}

void List::remove(const std::string &name) {
    for(auto i : items){
        if(name == i->getName()) {
            items.remove(i);
            std::cout << "Items removed successfully" << std::endl;
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
    if(oldName == newName){
        std::cout << "Name updated" <<std::endl;
        return;
    }
    for(auto i : items){
        if(oldName == i->getName()){
            i->setName(newName);
            std::cout << "Name updated" <<std::endl;
            return;
        }
    }
    std::cout << "Name not updated. Item not find" <<std::endl;
}

void List::show() {
    for(auto i : items)
        i->show();
}
