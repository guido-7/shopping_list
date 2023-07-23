//
// Created by Guido Rossi on 22/07/2023.
//

#include "ScratchPad.h"

ScratchPad::ScratchPad() {
    lists.clear();
}

ScratchPad::~ScratchPad() {
    lists.clear();
}

void ScratchPad::addList(const std::string& Name) {
    lists.push_back(new List(Name));
}

void ScratchPad::removeList(const std::string &Name) {
    int j = 0;
    for(auto i : lists){
        if(Name == i->getNameList()){
            lists.erase(lists.begin() + j);
            std::cout << "List removed successfully" << std::endl;
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
        return;
    }
    std::cout << "Invalid index" <<std::endl;
}

void ScratchPad::showLists() const {
    int j = 0;
    for(auto i : lists){
        j++;
        std::cout << j << ") " << i->getNameList() << std::endl;
    }
}
