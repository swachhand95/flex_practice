#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;

int main()
{
    DoublyLinkedList l;

    l.add(1);
    l.add(2);
    l.add(3);

    l.display();

    l.revDisplay();

    l.removeNode(2);
    l.display();
    l.removeNode(3);
    l.display();
    l.removeNode(1);
    l.display();

    return 0;
}
