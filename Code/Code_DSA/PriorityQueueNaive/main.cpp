#include "PriorityQueue.h"
#include <iostream>

using namespace std;

int main()
{
    PriorityQueue pq(10);

    pq.insertItem(50, 1);
    pq.insertItem(2, 2);
    pq.insertItem(23, 3);
    pq.insertItem(44, 4);
    pq.insertItem(52, 5);

    cout << pq.getHighestPriorityItem().data << endl;
    pq.deleteHighestPriorityItem();
    cout << pq.getHighestPriorityItem().data << endl;
    pq.deleteHighestPriorityItem();
    cout << pq.getHighestPriorityItem().data << endl;
    pq.deleteHighestPriorityItem();
    cout << pq.getHighestPriorityItem().data << endl;
    pq.deleteHighestPriorityItem();
    cout << pq.getHighestPriorityItem().data << endl;
    pq.deleteHighestPriorityItem();
    cout << pq.getHighestPriorityItem().data << endl;
    cout << pq.getHighestPriorityItem().data << endl;
}
