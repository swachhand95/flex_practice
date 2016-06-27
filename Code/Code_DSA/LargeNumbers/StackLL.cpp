#include "StackLL.h"
#include <iostream>

using namespace std;

StackLL::StackLL()
{
    top = NULL;
    sz = 0;
}

void StackLL::push(char val)
{
    Node *newNode = new Node;
    newNode->data = val;
    newNode->next = top;
    top = newNode;
    ++sz;
}

char StackLL::pop()
{
    if (top == NULL)
        return -1;
    char ret = top->data;
    Node *temp = top;
    top = top->next;
    delete temp;
    --sz;
    return ret;
}

char StackLL::peek() const
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
            cout << p->data;
            p = p->next;
        }
    }
    else
        cout << "List Empty" << endl;
}

bool StackLL::empty() const
{
    return top == nullptr;
}

int StackLL::size() const
{
    return sz;
}

