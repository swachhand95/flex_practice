#include "QueueLL.h"
#include <iostream>

using namespace std;

int main()
{
    QueueLL q;
    q.enqueue(1);
    q.print();
    cout << q.dequeue() << endl;
    for (int i = 1; i <= 10; ++i)
        q.enqueue(i);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    q.print();
}
