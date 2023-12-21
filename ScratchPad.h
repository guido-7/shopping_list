//
// Created by Guido Rossi on 22/07/2023.
//

#ifndef SHOPPING_LIST_SCRATCHPAD_H
#define SHOPPING_LIST_SCRATCHPAD_H

#include <iostream>
#include <vector>
#include <string>
#include "List.h"
#include "Observer.h"

class ScratchPad : public Observer {
public:
    ScratchPad();
    virtual ~ScratchPad();

    void addList();
    void addList(const std::string& Name);
    void removeList();
    void removeList(int Index);
    void removeList(const std::string& Name);
    void addItem();
    void addItem(const std::string& Name, int Quantity = 1, bool Taken = false);
    void removeItem();
    void removeItem(const std::string& Name);
    void selectItem();
    void showLists() const;
    void showItems() const;

    int getIndexListOpen() const;
    void setIndexListOpen(int IndexListOpen);
    void closeListOpen();
    int size();

    //observer
    virtual void update(const std::string& name) override;
    virtual void attach(int i) override;
    virtual void detach(int i) override;

private:
    std::vector<std::shared_ptr<List>> lists;
    int indexListOpen;
};


#endif //SHOPPING_LIST_SCRATCHPAD_H