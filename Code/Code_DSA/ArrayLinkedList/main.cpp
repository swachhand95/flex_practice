#include "LinkedList.h"
#include <iostream>

using namespace std;

int main()
{
    LinkedList l(30);
    l.insertAfter(3, 10);
    l.add(10);
    l.add(20);
    l.add(30);
    l.add(40);
    l.add(50);
    l.insertAfter(4, 3);
    l.insertAfter(3, 88);
    l.display();
    l.removeNode(50);
    l.display();
    l.removeNode(30);
    l.display();

}
