//
// Created by Guido Rossi on 21/09/2023.
//

#ifndef SHOPPING_LIST_OBSERVER_H
#define SHOPPING_LIST_OBSERVER_H

class Observer {
public:
    virtual ~Observer() {}

    virtual void update(int add) = 0;
};

#endif //SHOPPING_LIST_OBSERVER_H
