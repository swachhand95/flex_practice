#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;

DoublyLinkedList::DoublyLinkedList()
{
    nil.next = &nil;
    nil.prev = &nil;
    nil.data = 0;
}

void DoublyLinkedList::insertNode(Node* x)
{
    x->next = &nil;
    nil.prev->next = x;
    x->prev = nil.prev;
    nil.prev = x;
}

bool DoublyLinkedList::add(int val)
{
    Node *newNode = new Node;
    newNode->data = val;
    newNode->next = &nil;
    newNode->prev = nil.prev;

    nil.prev->next = newNode;
    nil.prev = newNode;

    return true;
}

void DoublyLinkedList::display() const
{
    Node *p = nil.next;

    if (p == &nil)
        cout << "List Empty!" << endl;
    else
    {
        while (p != &nil)
        {
            cout << p->data << " ";
            p = p->next;
        }

        cout << endl;
    }
}

void DoublyLinkedList::revDisplay() const
{
    Node *p = nil.prev;

    if (p == &nil)
        cout << "List Empty!" << endl;
    else
    {
        while (p != &nil)
        {
            cout << p->data << " ";
            p = p->prev;
        }

        cout << endl;
    }
}

bool DoublyLinkedList::removeNode(int val)
{
    Node *p = nil.next;

    while (p != &nil && p->data != val)
        p = p->next;

    if (p != &nil)
    {
        p->prev->next = p->next;
        p->next->prev = p->prev;

        delete p;
        return true;
    }

    return false;
}

void DoublyLinkedList::listUnion(DoublyLinkedList &other)
{

}
