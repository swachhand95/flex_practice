#include "CircularQueueLL.h"
#include <iostream>

using namespace std;

Queue::Queue() : head{nullptr} {}

void Queue::enqueue(int val)
{
    Node *newNode = new Node;
    newNode->data = val;

    if (head == nullptr)
        newNode->next = newNode;
    else
    {
        newNode->next = head->next;
        head->next = newNode;
    }
    head = newNode;
}

int Queue::dequeue()
{
    int ret = -1;

    if (head != nullptr)
    {
        ret = head->next->data;
        if (head == head->next)
        {
            delete head->next;
            head = nullptr;
        }
        else
        {
            Node *temp = head->next;
            head->next = head->next->next;
            delete temp;
        }
    }

    return ret;
}

void Queue::print() const
{
    if (head != nullptr)
    {
        Node *p = head->next;

        do
        {
            cout << p->data << " ";
            p = p->next;
        } while (p != head->next);
    }
}
