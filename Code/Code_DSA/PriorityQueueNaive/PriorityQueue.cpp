#include "PriorityQueue.h"
#include <iostream>

using namespace std;

PriorityQueue::PriorityQueue(int n) : tail{0}, cnt{0}, sz{n}
{
    arr = new Item[sz];
}

PriorityQueue::~PriorityQueue()
{
    delete []arr;
}

bool PriorityQueue::isEmpty() const
{
    return !cnt;
}

bool PriorityQueue::isFull() const
{
    return cnt == sz;
}

void PriorityQueue::insertItem(int val, int priority)
{
    if (!isFull())
    {
        arr[tail].data = val;
        arr[tail].priority = priority;
        ++tail;
        ++cnt;
        tail %= sz;
    }
    else
        cout << "Overflow" << endl;
}

Item PriorityQueue::getHighestPriorityItem() const
{
    if (!isEmpty())
    {
        int maxIdx = -1;
        int max = -1;
        for (int i = 0; i < tail; ++i)
            if (arr[i].priority > max)
            {
                max = arr[i].priority;
                maxIdx = i;
            }
        return arr[maxIdx];
    }
    return Item(-1, -1);
}

void PriorityQueue::deleteHighestPriorityItem()
{
    if (!isEmpty())
    {
        int maxIdx = -1;
        int max = -1;
        for (int i = 0; i < tail; ++i)
            if (arr[i].priority > max)
            {
                max = arr[i].priority;
                maxIdx = i;
            }
        for (int i = maxIdx; i < cnt - 1; ++i)
            arr[i] = arr[i+1];
        --cnt;
        --tail;
        tail = tail > 0 ? tail % sz : 0;
    }
    else
        cout << "PQ Empty" << endl;
}
