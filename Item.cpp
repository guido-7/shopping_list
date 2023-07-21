//
// Created by Guido Rossi on 20/07/2023.
//

#include "Item.h"

Item::Item(const std::string& Name, int Quantity) : name(Name), quantity(Quantity) {

}

Item::~Item() {

}

void Item::show() {
    std::cout << quantity << " | " << name << std::endl;
}

const std::string &Item::getName() const {
    return name;
}

int Item::getQuantity() const {
    return quantity;
}

void Item::setName(const std::string& Name) {
    Item::name = Name;
}

void Item::setQuantity(int Quantity) {
    Item::quantity = Quantity;
}
