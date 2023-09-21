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
    //detach();
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

const int List::getItemToBuy() const {
    return itemToBuy;
}

void List::add() {
    bool find = false;
    std::string name;
    int quantity;
    bool taken = false;
    int j = 0;
    do{
        find = false;
        if(j > 0)
            std::cout << "Name already used. ";
        std::cout << "Insert name of the new item : ";
        std::getline(std::cin, name);
        int i = 0;
        while(i < items.size() && !find){
            if(name == getNameItem(i))
                find = true;
            i++;
        }
        j=1;
    }while(find);
    j = 0;
    do{
        if(j > 0)
            std::cout << "Quantity not valid. ";
        std::cout << "Insert quantity of the new item : ";
        std::cin >> quantity;
        std::cin.ignore(100, '\n');
        j=1;
    }while(quantity < 1);
    do{
        std::cout << "Has it been caught yet ? 0 - no, 1 - yes : ";
        std::cin >> taken;
        std::cin.ignore(100, '\n');
    }while(taken!=0 && taken!=1);
    items.push_back(new Item(this, name, quantity, taken));
    std::cout << "Item added successfully" <<std::endl;
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
    items.push_back(new Item(this, name, quantity, taken));
    std::cout << "Item added successfully" <<std::endl;
}

void List::remove() {
    int indexItem = -1;
    while(indexItem > items.size() || indexItem < 1) {
        std::cout << "Insert index of item to remove : ";
        std::cin >> indexItem;
        std::cin.ignore(100, '\n');
    }
    indexItem--;
    std::string name = getNameItem(indexItem);
    for(auto i : items){
        if(name == i->getName()) {
            i->~Item();
            items.remove(i);
            std::cout << "Item removed successfully" << std::endl;
            return;
        }
    }
    std::cout << "Item not removed" << std::endl;
}

void List::remove(const std::string &name) {
    for(auto i : items){
        if(name == i->getName()) {
            i->~Item();
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
            if(i->isTaken()){
                i->setTaken(false);
            }
            else{
                i->setTaken(true);
            }
            std::cout << "Taken updated" <<std::endl;
            return;
        }
    }
    std::cout << "Taken not updated. Item not find" <<std::endl;
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

void List::update(int x) {
    itemToBuy += x;
}