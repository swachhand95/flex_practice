#include "Deque.h"
#include <iostream>

using namespace std;

Deque::Deque(int sz) : head{0}, tail{1}, size{sz}, arr{new int[sz]} {}

Deque::~Deque() { delete []arr; }

bool Deque::isEmpty() const
{
    return (head + 1) % size == tail;
}

bool Deque::isFull() const
{
    return head == tail;
}

void Deque::pushBack(int val)
{
    if (!isFull())
    {
        arr[tail] = val;
        ++tail;
        tail %= size;
    }
    else
        cout << "Overflow" << endl;
}

int Deque::popBack()
{
    if (!isEmpty())
    {
        --tail;
        tail = tail < 0 ? size - 1 : tail;
        return arr[tail];
    }
    cout << "Underflow" << endl;
    return -1;
}

void Deque::pushFront(int val)
{
    if (!isFull())
    {
        arr[head] = val;
        --head;
        head = head < 0 ? size - 1 : head;
    }
    else
        cout << "Overflow" << endl;
}

int Deque::popFront()
{
    if (!isEmpty())
    {
        ++head;
        head %= size;
        return arr[head];
    }
    cout << "Underflow" << endl;
    return -1;
}
