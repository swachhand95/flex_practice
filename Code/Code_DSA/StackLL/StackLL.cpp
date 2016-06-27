#include "StackLL.h"
#include <iostream>

using namespace std;

StackLL::StackLL()
{
    top = NULL;
}

void StackLL::push(int val)
{
    Node *newNode = new Node;
    newNode->data = val;
    newNode->next = top;
    top = newNode;
}

int StackLL::pop()
{
    if (top == NULL)
        return -1;
    int ret = top->data;
    Node *temp = top;
    top = top->next;
    delete temp;
    return ret;
}

int StackLL::peek() const
{
    return top != NULL ? top->data : -1;
}

void StackLL::print() const
{
    if (top != NULL)
    {
        Node *p = top;
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
