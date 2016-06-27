#include "Heap.h"
#include <iostream>

using namespace std;

int main()
{
    Heap h(10);

    h.add(20);
    h.add(17);
    h.add(60);
    h.add(30);
    h.add(25);
    h.add(40);

//    h.add(1);
//    h.add(2);
//    h.add(3);
//    h.add(4);

    h.print();

    cout << h.remove() << endl;
    h.print();
    cout << h.remove() << endl;
    h.print();
    cout << h.remove() << endl;
    h.print();
    cout << h.remove() << endl;
    h.print();
}
