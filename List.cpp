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
    for(auto i : items){
        if(name == i.getName())
            return;
    }
    Item item(name, quantity);
    items.push_back(item);
    std::cout << "Item added successfully" <<std::endl;
}

void List::show() {
    for(auto i : items)
        i.show();
}
