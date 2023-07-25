//
// Created by Guido Rossi on 22/07/2023.
//

#include "ScratchPad.h"

ScratchPad::ScratchPad() {
    lists.clear();
    indexListOpen = 0;
}

ScratchPad::~ScratchPad() {
    lists.clear();
}

void ScratchPad::addList() {
    bool find = true;
    std::string Name;
    while(find){
        find = false;
        std::cout << "Insert name of the new list : ";
        std::getline(std::cin, Name);
        for(auto i : lists)
            if(Name == i->getNameList())
                find = true;
    }
    lists.push_back(new List(Name));
    indexListOpen = lists.size() + 1;
}

void ScratchPad::addList(const std::string &Name) {
    bool find = false;
    for(auto i : lists)
        if(Name == i->getNameList())
            find = true;
    while(find){
        std::string n;
        find = false;
        std::cout << "Name already taken. Insert name of the new list : ";
        std::getline(std::cin, n);
        for(auto i : lists)
            if(n == i->getNameList())
                find = true;
    }
    lists.push_back(new List(Name));
    indexListOpen = lists.size() + 1;
}

void ScratchPad::removeList() {
    int indexL = -1;
    while(indexL > lists.size() || indexL < 1) {
        std::cout << "Insert index of list to remove : ";
        std::cin >> indexL;
        std::cin.ignore(100, '\n');
    }
    indexL--;
    lists.erase(lists.begin() + indexL);
    std::cout << "List removed successfully" << std::endl;
    indexListOpen = lists.size() + 1;
}

void ScratchPad::removeList(const std::string &Name) {
    int j = 0;
    for(auto i : lists){
        if(Name == i->getNameList()){
            lists.erase(lists.begin() + j);
            std::cout << "List removed successfully" << std::endl;
            indexListOpen = lists.size() + 1;
            return;
        }
        else
            j++;
    }
    std::cout << "List not find" <<std::endl;
}

void ScratchPad::removeList(int Index) {
    Index--;
    if(Index > 0 && Index < lists.size()) {
        lists.erase(lists.begin() + Index);
        std::cout << "List removed successfully" << std::endl;
        indexListOpen = lists.size() + 1;
        return;
    }
    std::cout << "Invalid index" <<std::endl;
}

void ScratchPad::addItem() {
    bool find = true;
    std::string Name;
    int Quantity;
    bool Taken = false;
    while(find){
        find = false;
        std::cout << "Insert name of the new item : ";
        std::getline(std::cin, Name);
        for(int i = 0; i < lists[indexListOpen]->size(); i++)
            if(Name == lists[indexListOpen]->getNameItem(i))
                find = true;
    }
    do{
        std::cout << "Insert quantity of the new item : ";
        std::cin >> Quantity;
        std::cin.ignore(100, '\n');
    }while(Quantity < 1);
    do{
        std::cout << "Has it been caught yet ? 0 - no, 1 - yes : ";
        std::cin >> Taken;
        std::cin.ignore(100, '\n');
    }while(Taken!=0 && Taken!=1);
    lists[indexListOpen]->add(Name, Quantity, Taken);
}

void ScratchPad::addItem(const std::string &Name, int Quantity, bool Taken) {
    if(indexListOpen < lists.size()){
        lists[indexListOpen]->add(Name, Quantity, Taken);
        return;
    }
    std::cout << "List not selected" << std::endl;
}

void ScratchPad::removeItem() {
    int indexI = -1;
    while(indexI > lists[indexListOpen]->size() || indexI < 1) {
        std::cout << "Insert index of item to remove : ";
        std::cin >> indexI;
        std::cin.ignore(100, '\n');
    }
    indexI--;
    lists[indexListOpen]->remove(lists[indexListOpen]->getNameItem(indexI));
    std::cout << "Item removed successfully" << std::endl;
}

void ScratchPad::removeItem(const std::string &Name) {
    if(indexListOpen < lists.size()){
        lists[indexListOpen]->remove(Name);
        return;
    }
    std::cout << "List not selected" << std::endl;
}

void ScratchPad::selectItem() {
    int indexI = -1;
    while(indexI > lists[indexListOpen]->size() || indexI < 1) {
        std::cout << "Insert index of item to select : ";
        std::cin >> indexI;
        std::cin.ignore(100, '\n');
    }
    indexI--;
    lists[indexListOpen]->changeTakenItem(lists[indexListOpen]->getNameItem(indexI));
    std::cout << "Item removed successfully" << std::endl;
}

void ScratchPad::showLists() const {
    int j = 0;
    for(auto i : lists){
        j++;
        std::cout << j << ") " << i->getNameList() << std::endl;
    }
}

void ScratchPad::showItems() const {
    if(indexListOpen < lists.size()){
        lists[indexListOpen]->show();
        return;
    }
    std::cout << "List not selected" << std::endl;
}

int ScratchPad::getIndexListOpen() const {
    return indexListOpen;
}

void ScratchPad::setIndexListOpen(int IndexListOpen) {
    ScratchPad::indexListOpen = IndexListOpen;
}

int ScratchPad::size() {
    return lists.size();
}
