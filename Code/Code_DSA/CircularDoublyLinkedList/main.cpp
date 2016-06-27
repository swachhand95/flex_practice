#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;

int main()
{
    DoublyLinkedList y;
    for (int i = 1; i <= 10; ++i)
        y.add(i);
    y.display();
    y.remove(1);
    y.display();
    y.remove(10);
    y.display();
    y.remove(5);
    y.display();
}
