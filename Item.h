//
// Created by Guido Rossi on 20/07/2023.
//

#ifndef SHOPPING_LIST_ITEM_H
#define SHOPPING_LIST_ITEM_H

#include <iostream>

class Item {
public:
    Item(const std::string& Name, int Quantity = 1);
    ~Item();

    //copy constructor and assignment operator
    Item(const Item& original);
    Item& operator=(const Item& right);

    //getter and setter method
    const std::string& getName() const;
    int getQuantity() const;
    void setName(const std::string& Name);
    void setQuantity(int Quantity);

    //print all variables
    void show();
private:
    std::string name;
    int quantity;
};

#endif //SHOPPING_LIST_ITEM_H
