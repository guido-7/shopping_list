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

void ScratchPad::addList(const std::string& Name) {
    lists.push_back(new List(Name));
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

void ScratchPad::addItem(const std::string &Name, int Quantity, bool Taken) {
    if(indexListOpen < lists.size()){
        lists[indexListOpen]->add(Name, Quantity, Taken);
        return;
    }
    std::cout << "List not selected" << std::endl;
}

void ScratchPad::removeItem(const std::string &Name) {
    if(indexListOpen < lists.size()){
        lists[indexListOpen]->remove(Name);
        return;
    }
    std::cout << "List not selected" << std::endl;
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

void ScratchPad::setIndexListOpen(int indexListOpen) {
    ScratchPad::indexListOpen = indexListOpen;
}

int ScratchPad::size() {
    return lists.size();
}
