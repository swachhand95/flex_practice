#include "CircularLinkedList.h"
#include <iostream>

using namespace std;

int main()
{
    CircularLinkedList l;
    for (int i = 1; i <= 10; ++i)
        l.add(i);
    l.print();
    for (int i = 1; i <= 10; ++i)
        l.removeNode(i);
    l.print();
}
