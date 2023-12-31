#include <iostream>
#include "ScratchPad.h"

// enum class
enum class ListEvent {
    Quit, Back, Open, New, Remove, Select, Null
};

void cleanOutput() {
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

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
            case 's':
                return ListEvent::Select;
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
            cleanOutput();
            pad.showLists();
            break;
        }
        case ListEvent::Open: {
            if(pad.getIndexListOpen() > pad.size()) {
                int indexL = -1;
                while(indexL > pad.size() || indexL < 1) {
                    std::cout << "Insert index of list to open: ";
                    std::cin >> indexL;
                    std::cin.ignore(100, '\n');
                }
                pad.setIndexListOpen((indexL-1));
            }
            cleanOutput();
            pad.showItems();
            break;
        }
        case ListEvent::New: {
            //new list
            if(pad.getIndexListOpen() > pad.size()) {
                pad.addList();
                cleanOutput();
                pad.showLists();
            }
                //new item
            else if (pad.getIndexListOpen() < pad.size()){
                pad.addItem();
                cleanOutput();
                pad.showItems();
            }
            break;
        }
        case ListEvent::Remove: {
            //remove list
            if(pad.getIndexListOpen() > pad.size()) {
                pad.removeList();
                cleanOutput();
                pad.showLists();
            }
                //remove item
            else if (pad.getIndexListOpen() < pad.size()){
                pad.removeItem();
                cleanOutput();
                pad.showItems();
            }
            break;
        }
        case ListEvent::Select: {
            // select or deselect a item if we are in a list
            if(pad.getIndexListOpen() < pad.size())
                pad.selectItem();
            cleanOutput();
            pad.showItems();
            break;
        }
        case ListEvent::Null: {
            std::cout << "Not valid command. ";
            break;
        }
    }
    return false;
}

//render command user interface
void renderCUI(ScratchPad &pad) {
    //Scratchpad
    if(pad.getIndexListOpen() > pad.size())
        std::cout << "Press: (n)ew,(r)emove,(o)pen or Q to quit." << std::endl;
        //list
    else
        std::cout << "Press: (n)ew,(r)emove,(s)elect,(b)ack or Q to quit." << std::endl;
}

int main() {
    ScratchPad lists;
    lists.addList("Spesa casa");
    lists.addList("Vestiti");
    lists.setIndexListOpen(0);
    lists.addItem("pane");
    lists.addItem("latte",2);
    lists.addItem("marmellata",3,true);
    lists.closeListOpen();

    cleanOutput();
    lists.showLists();
    renderCUI(lists);

    while(true){
        ListEvent listEvent = getEvent();
        bool quit = updateList(listEvent, lists);
        if (quit)
            return 0;
        renderCUI(lists);
    }
}