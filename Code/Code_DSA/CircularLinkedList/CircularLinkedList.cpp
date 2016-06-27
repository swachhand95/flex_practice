#include "CircularLinkedList.h"
#include <iostream>

using namespace std;

CircularLinkedList::CircularLinkedList()
{
    last = NULL;
}

void CircularLinkedList::add(int val)
{
    Node *newNode = new Node;
    newNode->data = val;

    if (last == NULL)
        newNode->next = newNode;
    else
    {
        newNode->next = last->next;
        last->next = newNode;
    }

    last = newNode;
}

void CircularLinkedList::print() const
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

bool CircularLinkedList::removeNode(int val)
{
    if (last != NULL)
    {
        Node *p = last;

        while (p->next->data != val && p->next != last)
            p = p->next;
        // The node to be deleted is not the last node
        if (p->next->data == val && p->next != last)
        {
            // delete p->next
            Node *temp = p->next;
            p->next = p->next->next;
            delete temp;
            return true;
        }
        else if (p->next->data == val && p->next == last)
        {
            Node *temp = p->next;
            p->next = p->next->next;
            if (last->next != last)
                last = p;
            else
                last = NULL;
            delete temp;
            return true;
        }
    }

    return false;
}
