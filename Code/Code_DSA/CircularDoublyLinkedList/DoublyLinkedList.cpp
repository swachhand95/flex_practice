#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;

DoublyLinkedList::DoublyLinkedList()
{
    last = NULL;
}

bool DoublyLinkedList::add(int val)
{
    Node *newNode = new Node;
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (last == NULL)
    {
        last = newNode;
        last->next = newNode;
        last->prev = newNode;
    }
    else
    {
        newNode->next = last->next;
        newNode->prev = last;
        last->next->prev = newNode;
        last->next = newNode;
        last = newNode;
    }

    return true;
}

void DoublyLinkedList::display() const
{
    if (last != NULL)
    {
        Node *p = last->next;
        while (p != last)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << p->data << endl;
    }
    else
        cout << "List Empty" << endl;
}

void DoublyLinkedList::revDisplay() const
{

}

bool DoublyLinkedList::remove(int val)
{
    if (last != NULL)
    {
        Node *p = last->next;

        if (p->data == val)
        {
            Node *temp = last->next;
            last->next = last->next->next;
            last->next->prev = last;
            delete temp;
            return true;
        }

        while (p->next->data != val && p->next != last)
            p = p->next;

        if (p->next->data == val && p->next != last)
        {
            Node *temp = p->next;
            p->next = p->next->next;
            p->next->prev = temp->prev;
            delete temp;
//            PR(last->data);
            return true;
        }
        else if (p->next->data == val && p->next == last)
        {
            Node *temp = p->next;
            p->next = p->next->next;
            temp->next->prev = p;
            if (last->next != last)
                last = p;
            else
                last = NULL;
            delete temp;
//            PR(last->data);
            return true;
        }
    }

    return false;
}
