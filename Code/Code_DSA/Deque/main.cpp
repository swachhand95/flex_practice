#include "Deque.h"
#include <iostream>

using namespace std;

int main()
{
    Deque dq(5);

    dq.pushBack(1);
    dq.pushBack(6);
    dq.pushBack(7);

    cout << dq.popBack() << endl;
    cout << dq.popBack() << endl;
    cout << dq.popBack() << endl;
    cout << dq.popBack() << endl;

    dq.pushFront(2);
    dq.pushBack(6);
    dq.pushBack(7);
    dq.pushBack(7);
    dq.pushBack(7);
    dq.pushFront(2);

    cout << dq.popFront() << endl;
    cout << dq.popFront() << endl;
    cout << dq.popFront() << endl;
    cout << dq.popFront() << endl;
    cout << dq.popFront() << endl;

    return 0;
}
