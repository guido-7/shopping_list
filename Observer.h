//
// Created by Guido Rossi on 21/09/2023.
//

#ifndef SHOPPING_LIST_OBSERVER_H
#define SHOPPING_LIST_OBSERVER_H

class Subject;

class Observer {
public:
    virtual ~Observer() {}

    virtual void update(const std::string& s) = 0;
    virtual void attach(int i) = 0;
    virtual void detach(int i) = 0;
};

#endif //SHOPPING_LIST_OBSERVER_H
