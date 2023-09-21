//
// Created by Guido Rossi on 21/09/2023.
//

#ifndef SHOPPING_LIST_SUBJECT_H
#define SHOPPING_LIST_SUBJECT_H

#include "Observer.h"

class Subject {
public:
    virtual ~Subject() {}

    virtual void subscribe(Observer *o) = 0;
    virtual void unsubscribe(Observer *o) = 0;
    virtual void notify(int x) = 0;
};

#endif //SHOPPING_LIST_SUBJECT_H
