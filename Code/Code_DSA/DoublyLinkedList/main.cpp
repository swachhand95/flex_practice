#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;

int main()
{
    DoublyLinkedList y;
    y.add(10);
    y.add(20);
    y.add(30);
    y.display();
    y.revDisplay();
    y.remove(20);
    y.display();
    y.revDisplay();
    y.remove(10);
    y.display();
    y.revDisplay();
    y.remove(30);
    y.display();
    y.revDisplay();

    y.add(10);
    y.add(20);
    y.add(30);
    y.add(40);

    y.display();

    y.insertAt(5, 1);
    y.display();

    y.insertAt(5, 3);
    y.display();

    y.insertAt(5, 9);
    y.display();

}
