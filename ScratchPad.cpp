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
        for (auto& ptr : lists) {
            if(Name == ptr->getNameList())
                find = true;
        }
    }
    lists.push_back(std::make_shared<List>(Name));
    ScratchPad::attach(lists.size());
    closeListOpen();
}

void ScratchPad::addList(const std::string &Name) {
    bool find = false;
    for (auto& ptr : lists) {
        if(Name == ptr->getNameList())
            find = true;
    }
    std::string n = Name;
    while(find){
        find = false;
        std::cout << "Name already taken. Insert name of the new list : ";
        std::getline(std::cin, n);
        for (auto& ptr : lists) {
            if(Name == ptr->getNameList())
                find = true;
        }
    }
    lists.push_back(std::make_shared<List>(n));
    ScratchPad::attach(lists.size());
    closeListOpen();
}

void ScratchPad::removeList() {
    if(lists.empty()){
        std::cout << "Not list to remove" << std::endl;
        return;
    }
    int indexL = -1;
    while(indexL > lists.size() || indexL < 1) {
        std::cout << "Insert index of list to remove : ";
        std::cin >> indexL;
        std::cin.ignore(100, '\n');
    }
    indexL--;
    ScratchPad::detach(indexL);
    lists.erase(lists.begin() + indexL);
    std::cout << "List removed successfully" << std::endl;
    closeListOpen();
}

void ScratchPad::removeList(const std::string &Name) {
    if(lists.empty()){
        std::cout << "Not list to remove" << std::endl;
        return;
    }
    int j = 0;
    for (auto& ptr : lists) {
        if(Name == ptr->getNameList()){
            ScratchPad::detach(j);
            lists.erase(lists.begin() + j);
            std::cout << "List removed successfully" << std::endl;
            closeListOpen();
            return;
        }
        else
            j++;
    }
    std::cout << "List not find" <<std::endl;
}

void ScratchPad::removeList(int Index) {
    if(lists.empty()){
        std::cout << "Not list to remove" << std::endl;
        return;
    }
    Index--;
    if(Index > 0 && Index < lists.size()) {
        ScratchPad::detach(Index);
        lists.erase(lists.begin() + Index);
        std::cout << "List removed successfully" << std::endl;
        closeListOpen();
        return;
    }
    std::cout << "Invalid index" <<std::endl;
}

void ScratchPad::addItem() {
    bool find = false;
    std::string Name;
    int Quantity;
    bool Taken = false;
    int j = 0;
    do{
        find = false;
        if(j > 0)
            std::cout << "Name already used. ";
        std::cout << "Insert name of the new item : ";
        std::getline(std::cin, Name);
        int i = 0;
        while(i < lists[indexListOpen]->size() && !find){
            if(Name == lists[indexListOpen]->getNameItem(i))
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
        std::cin >> Quantity;
        std::cin.ignore(100, '\n');
        j=1;
    }while(Quantity < 1);
    do{
        std::cout << "Has it been caught yet ? 0 - no, 1 - yes : ";
        std::cin >> Taken;
        std::cin.ignore(100, '\n');
    }while(Taken!=0 && Taken!=1);
    lists[indexListOpen]->add(Name, Quantity, Taken);
    std::cout << "Item added successfully" <<std::endl;
}

void ScratchPad::addItem(const std::string &Name, int Quantity, bool Taken) {
    bool s = 1;
    if(indexListOpen < lists.size())
        s = lists[indexListOpen]->add(Name, Quantity, Taken);
    else{
        std::cout << "List not selected" << std::endl;
        return;
    }
    if(s != 0)
        std::cout << "Something was wrong" << std::endl;
}

void ScratchPad::removeItem() {
    if(lists[indexListOpen]->size() == 0){
        std::cout << "Not item to remove" << std::endl;
        return;
    }
    int indexItem = -1;
    while(indexItem > lists[indexListOpen]->size() || indexItem < 1) {
        std::cout << "Insert index of item to remove : ";
        std::cin >> indexItem;
        std::cin.ignore(100, '\n');
    }
    indexItem--;
    std::string name = lists[indexListOpen]->getNameItem(indexItem);
    bool s = lists[indexListOpen]->remove(name);
    if (s != 0)
        std::cout << "Something was wrong" << std::endl;
}

void ScratchPad::removeItem(const std::string &Name) {
    bool s = 1;
    if(indexListOpen < lists.size())
        s = lists[indexListOpen]->remove(Name);
    else
        std::cout << "List not selected" << std::endl;
    if (s != 0)
        std::cout << "Something was wrong" << std::endl;
}

void ScratchPad::selectItem() {
    if(lists[indexListOpen]->size() == 0){
        std::cout << "Not item to select" << std::endl;
        return;
    }
    int indexI = -1;
    while(indexI > lists[indexListOpen]->size() || indexI < 1) {
        std::cout << "Insert index of item to select : ";
        std::cin >> indexI;
        std::cin.ignore(100, '\n');
    }
    indexI--;
    lists[indexListOpen]->changeTakenItem(lists[indexListOpen]->getNameItem(indexI));
    std::cout << "Item selected successfully" << std::endl;
}

void ScratchPad::showLists() const {
    int j = 0;
    for (auto& ptr : lists) {
        j++;
        std::cout << j << ") " << ptr->getNameList() << std::endl;
    }
}

void ScratchPad::showItems() const {
    std::cout << "------" << lists[indexListOpen]->getNameList() << " ( " << lists[indexListOpen]->getItemToBuy() << " ) " << "------" << std::endl;
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

void ScratchPad::closeListOpen() {
    ScratchPad::indexListOpen = lists.size() + 1;
}

int ScratchPad::size() {
    return lists.size();
}

void ScratchPad::update(const std::string& name) {
   int i = 0;
    for (auto& ptr : lists) {
        if(ptr->getNameList() == name && i == indexListOpen)
            showItems();
        i++;
    }
}

void ScratchPad::attach(int i) {
    if(i >= 0 && i < lists.size())
        lists[i]->subscribe( this );
}

void ScratchPad::detach(int i) {
    if(i >= 0 && i < lists.size())
        lists[i]->unsubscribe( this );
}
