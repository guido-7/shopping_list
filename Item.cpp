//
// Created by Guido Rossi on 20/07/2023.
//

#include "Item.h"

Item::Item(const std::string& n) : name(n){

}

Item::~Item() {

}

void Item::show() {
    std::cout << name << std::endl;
}
