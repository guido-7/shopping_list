//
// Created by Guido Rossi on 20/07/2023.
//

#include "Item.h"

Item::Item(const std::string& Name, int Quantity, bool Taken) : name(Name), quantity(Quantity), taken(Taken) {
    if (Quantity < 1){
        std::cout << "Quantity not valid. Changed to 1" << std::endl;
        Quantity = 1;
    }
}

Item::~Item() {}

Item::Item(const Item &original) {
    name = original.name;
    quantity = original.quantity;
    taken = original.taken;
}

Item &Item::operator=(const Item &right) {
    if(this != &right) {
        name = right.name;
        quantity = right.quantity;
        taken = right.taken;
    }
    return *this;
}

const std::string &Item::getName() const {
    return name;
}

int Item::getQuantity() const {
    return quantity;
}

bool Item::isTaken() const {
    return taken;
}

void Item::setName(const std::string& Name) {
    Item::name = Name;
}

void Item::setQuantity(int Quantity) {
    if(Quantity < 1){
        std::cout << "Quantity not valid" << std::endl;
    }
    else {
        Item::quantity = Quantity;
    }
}

void Item::setTaken(bool Taken) {
    if(Item::taken == Taken)
        return;
    else if(Taken){
        Item::taken = Taken;
        return;
    }
    else {
        Item::taken = Taken;
        return;
    }
}

std::string Item::toString() const {
    std::string s;
    if(taken)
        s = " X  | " + std::to_string(quantity) + " | " + name;
    else
        s = "    | " + std::to_string(quantity) + " | " + name;
    return s;
}
