//
// Created by Guido Rossi on 20/07/2023.
//

#include "Item.h"

Item::Item(const std::string& Name, int Quantity, bool Taken) : name(Name), quantity(Quantity), taken(Taken) {}

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
    Item::quantity = Quantity;
}

void Item::setTaken(bool Taken) {
    Item::taken = Taken;
}

void Item::show() {
    if(taken)
        std::cout << " X ";
    else
        std::cout << "   ";
    std::cout << " | "  << quantity << " | " << name << std::endl;
}
