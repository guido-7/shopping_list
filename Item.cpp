//
// Created by Guido Rossi on 20/07/2023.
//

#include "Item.h"

Item::Item(Observer *o, const std::string& Name, int Quantity, bool Taken) : name(Name), quantity(Quantity), taken(Taken) {
    Item::subscribe(o);
    if(taken)
        Item::notify(0);
    else
        Item::notify(1);
}

Item::~Item() {
    if(taken)
        Item::notify(0);
    else
        Item::notify(-1);
    observers.clear();
}

Item::Item(const Item &original) {
    name = original.name;
    quantity = original.quantity;
    taken = original.taken;
    if(taken)
        Item::notify(0);
    else
        Item::notify(1);
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
    if(Item::taken == Taken)
        return;
    else if(Taken){
        Item::taken = Taken;
        Item::notify(-1);
        return;
    }
    else {
        Item::taken = Taken;
        Item::notify(1);
        return;
    }
}

void Item::show() {
    if(taken)
        std::cout << " X ";
    else
        std::cout << "   ";
    std::cout << " | "  << quantity << " | " << name << std::endl;
}

void Item::subscribe(Observer *o) {
    observers.push_back(o);
}

void Item::unsubscribe(Observer *o) {
    observers.remove(o);
}

void Item::notify(int x) {
    for(auto i : observers)
        i->update(x);
}