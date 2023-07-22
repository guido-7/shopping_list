//
// Created by Guido Rossi on 20/07/2023.
//

#ifndef SHOPPING_LIST_ITEM_H
#define SHOPPING_LIST_ITEM_H

#include <iostream>

class Item {
public:
    explicit Item(const std::string& Name, int Quantity = 1, bool Taken = false);
    ~Item();

    //copy constructor and assignment operator
    Item(const Item& original);
    Item& operator=(const Item& right);

    //getter and setter method
    const std::string& getName() const;
    int getQuantity() const;
    bool isTaken() const;
    void setName(const std::string& Name);
    void setQuantity(int Quantity);
    void setTaken(bool taken);

    //print all variables
    void show();
private:
    std::string name;
    int quantity;
    bool taken;
};

#endif //SHOPPING_LIST_ITEM_H
