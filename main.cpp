#include <iostream>
#include "Item.h"

int main() {
    Item item1("Biscottti");
    item1.show();
    item1.setName("Biscotti");
    item1.setQuantity(3);
    item1.show();
    return 0;
}
