#include <iostream>
#include "Item.h"
#include "List.h"
#include "ScratchPad.h"

// enum class
enum class ListEvent {
    Quit, Back, Open, New, Remove,Null
};

// poll event from keyboard
ListEvent getEvent() {
    char c;
    while (std::cin.get(c)) {
        std::cin.ignore(100, '\n');
        switch (c) {
            case 'Q':
                return ListEvent::Quit;
            case 'b':
                return ListEvent::Back;
            case 'o':
                return ListEvent::Open;
            case 'n':
                return ListEvent::New;
            case 'r':
                return ListEvent::Remove;
            default:
                return ListEvent::Null;
        }
    }
    return ListEvent::Null;
}

bool updateList(const ListEvent &listEvent, ScratchPad &pad) {
    switch (listEvent) {
        case ListEvent::Quit: //close program
            return true;
        case ListEvent::Back: {
            // turn back if we are in a list
            if(pad.getIndexListOpen() < pad.size())
                pad.setIndexListOpen(pad.size()+1);
            system("cls");
            pad.showLists();
            break;
        }
        case ListEvent::Open: {
            if(pad.getIndexListOpen() > pad.size()) {
                int indexL = -1;
                while(indexL > pad.size() || indexL < 0) {
                    std::cout << "Insert index of list to open: ";
                    std::cin >> indexL;
                    std::cin.ignore(100, '\n');
                }
                pad.setIndexListOpen(indexL);
            }
            system("cls");
            pad.showItems();
            break;
        }
        case ListEvent::New: {
            //new list
            if(pad.getIndexListOpen() > pad.size()) {
                pad.addList();
                system("cls");
                pad.showLists();
            }
            //new item
            else if (pad.getIndexListOpen() < pad.size()){
                pad.addItem();
                system("cls");
                pad.showItems();
            }
            break;
        }
        case ListEvent::Remove: {
            break;
        }
        case ListEvent::Null: {
            std::cout << "Press: (n)ew,(r)emove,(o)pen,(b)ack or Q to quit." << std::endl;
            break;
        }
    }
    return false;
}

int main() {
    /*
    Item item1("Biscottti");
    item1.show();
    item1.setName("Biscotti");
    item1.setQuantity(3);
    item1.show();
    Item item2(item1);
    item2.setQuantity(2);
    item2.show();
    */
    /*
    List list1("Lista della spesa");
    list1.add("Fusilli",2);
    list1.add("Mezze maniche",2);
    list1.add("Eliche",2);
    list1.show();
    list1.changeQuantityItem("Fusilli",1);
    list1.changeNameItem("Fusilli","Maniche");
    list1.show();
    list1.changeQuantityItem("Fusilli",1);
    list1.changeNameItem("Fusillli","Fusilli");
    list1.remove("Mezze maniche");
    list1.show();
    list1.add("Mezze maniche",4, true);
    list1.changeTakenItem("Maniche");
    list1.show();
    */
    /*
    ScratchPad lists;
    lists.addList("Spesa personale");
    lists.addList("Spesa casa");
    lists.addList("Vestiti");
    lists.showLists();
    lists.removeList("Spesa casa");
    lists.showLists();
    lists.removeList(2);
    lists.showLists();
    */
    ScratchPad lists;
    lists.addList("Spesa casa");
    lists.addList("Vestiti");
    lists.showLists();
    while(true){
        ListEvent listEvent = getEvent();
        bool quit = updateList(listEvent, lists);
        if (quit)
            return 0;
    }


    return 0;
}
