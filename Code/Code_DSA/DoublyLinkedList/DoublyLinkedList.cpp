#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;

DoublyLinkedList::DoublyLinkedList()
{
    first = NULL;
}

bool DoublyLinkedList::add(int val)
{
    Node *newNode = new Node;
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (first == NULL)
        first = newNode;
    else
    {
        Node *p = first;
        while (p->next != NULL)
            p = p->next;
        p->next = newNode;
        newNode->prev = p;
    }

    return true;
}

void DoublyLinkedList::display() const
{
    Node *p = first;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void DoublyLinkedList::revDisplay() const
{
    if (first == NULL)
        return;
    Node *p = first;
    while (p->next != NULL)
        p = p->next;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->prev;
    }
    cout << endl;
}

bool DoublyLinkedList::remove(int val)
{
    Node *p = first;
    while (p != NULL && p->data != val)
        p = p->next;

    if (p == first && p->next == NULL)
    {
        first = NULL;
        delete p;
        return true;
    }
    if (p == first)
    {
        first = p->next;
        p->next->prev = NULL;
        delete p;
        return true;
    }
    if (p->next == NULL)
    {
        p->prev->next = NULL;
        delete p;
        return true;
    }
    if (p != NULL)
    {
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        return true;
    }

    return false;
}

void DoublyLinkedList::swapNodes(Node **a, Node **b)
{
    Node *temp = *a;
    *a = *b;
    *b = temp;
}

bool DoublyLinkedList::insertAt(int val, int pos)
{
    Node *newNode = new Node;
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = NULL;

    int cnt = 1;
    Node *p = first;
    if (first == NULL)
    {
        first = newNode;
        return true;
    }

    while (p->next != NULL && pos != cnt)
    {
        p = p->next;
        ++cnt;
    }

    if (p == NULL && pos != cnt)
    {
        p->prev->next = newNode;
        newNode->prev = p;
    }
    else if (p->prev == NULL)
    {
        first = newNode;
        newNode->next = p;
        p->prev = newNode;
    }
    else if (p->next == NULL)
    {
        p->next = newNode;
        newNode->prev = p;
    }
    else
    {
        newNode->prev = p->prev;
        newNode->next = p;
        p->prev->next = newNode;
        p->prev = newNode;
    }

    return true;
}
