#include "QueueLL.h"
#include <iostream>

using namespace std;

QueueLL::QueueLL()
{
    head = NULL;
    tail = NULL;
}

void QueueLL::enqueue(int val)
{
    Node *newNode = new Node;
    newNode->data = val;
    newNode->next = NULL;

    if (tail == NULL && head == NULL)
    {
        head = tail = newNode;
    }
    else if (tail != NULL)
    {
        tail->next = newNode;
        tail = newNode;
    }
}

int QueueLL::dequeue()
{
    int ret = -1;

    if (head != NULL && tail != NULL)
    {
        if (head == tail)
        {
            ret = head->data;
            delete head;
            head = NULL;
            tail = NULL;
        }
        else if (head != NULL)
        {
            Node *temp = head;
            ret = head->data;
            head = head->next;
            delete temp;
        }
    }

    return ret;
}

void QueueLL::print() const
{
    if (head != NULL && tail != NULL)
    {
        Node *p = head;
        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
    else
        cout << "List Empty" << endl;
}
