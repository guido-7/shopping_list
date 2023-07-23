#include <iostream>
#include "Item.h"
#include "List.h"
#include "ScratchPad.h"

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
    ScratchPad lists;
    lists.addList("Spesa personale");
    lists.addList("Spesa casa");
    lists.addList("Vestiti");
    lists.showLists();
    lists.removeList("Spesa casa");
    lists.showLists();
    lists.removeList(2);
    lists.showLists();

    return 0;
}
