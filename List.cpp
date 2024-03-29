//
// Created by Guido Rossi on 21/07/2023.
//

#include "List.h"

List::List(const std::string& name) : nameList(name) {
    items.clear();
    itemToBuy = 0;
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
    static std::string s;
    if(Index > items.size() || Index < 0) {
        std::cout << "No items to this index.";
        std::cout << s;
        return s;
    }
    int j = 0;
    for (auto& ptr : items) {
        if(j == Index)
            return ptr->getName();
        j++;
    }
    return s;
}

const int List::getItemToBuy() const {
    return itemToBuy;
}

bool List::add(const std::string& name, int quantity, bool taken) {
    if(quantity < 1){
        std::cout << "Quantity not valid" <<std::endl;
        return false;
    }
    for (auto& ptr : items) {
        if(name == ptr->getName()) {
            std::cout << "Name already used" << std::endl;
            return false;
        }
    }
    items.push_back(std::make_unique<Item>(name, quantity, taken));
    if(!taken)
        itemToBuy++;
    std::cout << "Item added successfully" <<std::endl;
    notify();
    return true;
}

bool List::remove(const std::string &name) {
    for (auto& ptr : items) {
        if(name == ptr->getName()) {
            if (!ptr->isTaken())
                itemToBuy--;
            items.remove(ptr);
            std::cout << "Item removed successfully" << std::endl;
            notify();
            return true;
        }
    }
    std::cout << "Item not find" <<std::endl;
    return false;
}

bool List::changeQuantityItem(const std::string& name, int quantity) {
    if(quantity < 1){
        std::cout << "Quantity not updated. Quantity not valid" <<std::endl;
        notify();
        return false;
    }
    for (auto& ptr : items) {
        if (name == ptr->getName()) {
            ptr->setQuantity(quantity);
            std::cout << "Quantity updated" << std::endl;
            notify();
            return true;
        }
    }
    std::cout << "Quantity not updated. Item not find" <<std::endl;
    notify();
    return false;
}

bool List::changeNameItem(const std::string& oldName, const std::string& newName) {
    for (auto& ptr : items) {
        if(oldName == ptr->getName() && oldName == newName){
            std::cout << "Name updated" <<std::endl;
            notify();
            return true;
        }
        else if(oldName == ptr->getName()){
            for (auto& ptr_newName : items) {
                if(newName == ptr_newName->getName()){
                    std::cout << "Name not updated. Name already used" <<std::endl;
                    notify();
                    return false;
                }
            }
            ptr->setName(newName);
            std::cout << "Name updated" <<std::endl;
            notify();
            return true;
        }
    }
    std::cout << "Name not updated. Item not find" <<std::endl;
    notify();
    return false;
}

bool List::changeTakenItem(const std::string &name) {
    for (auto& ptr : items) {
        if(name == ptr->getName()){
            if(ptr->isTaken()){
                ptr->setTaken(false);
                itemToBuy++;
            }
            else{
                ptr->setTaken(true);
                itemToBuy--;
            }
            std::cout << "Taken updated" <<std::endl;
            notify();
            return true;
        }
    }
    std::cout << "Taken not updated. Item not find" <<std::endl;
    notify();
    return false;
}

void List::show() const {
    int j = 1;
    for (auto& ptr : items) {
        std::cout << j << ")  ";
        std::cout << ptr->toString() << "\n";
        j++;
    }
    if(j == 1)
        std::cout << "No items in the list" <<std::endl;
}

int List::size() const {
    return items.size();
}

void List::subscribe(Observer* o){
    observers.push_back(o);
}

void List::unsubscribe(Observer* o) {
    observers.remove(o);
}
void List::notify() {
    for(auto itr : observers)
        (*itr).update(nameList);
}