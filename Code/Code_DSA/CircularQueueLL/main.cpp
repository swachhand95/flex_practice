#include "CircularQueueLL.h"
#include <iostream>

using namespace std;

int main()
{
    Queue q;
    for (int i = 1; i <= 10; ++i)
        q.enqueue(i);
    q.print();
    PR(q.dequeue());
    PR(q.dequeue());
    PR(q.dequeue());
    PR(q.dequeue());
    PR(q.dequeue());
    PR(q.dequeue());
    PR(q.dequeue());
    PR(q.dequeue());
    PR(q.dequeue());
    PR(q.dequeue());
    PR(q.dequeue());
    PR(q.dequeue());
    q.enqueue(100);
    q.enqueue(300);
    q.print();
}
