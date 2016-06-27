#include "LinkedList.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList(int n) : sz{n}, first{-1}, avail{0}
{
    arr = new Node[sz];
    for (int i = 0; i < sz; ++i)
        arr[i].data = 0;
    for (int i = 0; i < sz - 1; ++i)
        arr[i].next = i + 1;
    arr[sz - 1].next = -1;
}

LinkedList::~LinkedList()
{
    delete []arr;
}

void LinkedList::add(int val)
{
    if (avail != -1)
    {
        if (first != -1)
        {
            int i = first;
            while (arr[i].next != -1)
                i = arr[i].next;
            arr[i].next = avail;
            arr[avail].data = val;
            int temp = avail;
            avail = arr[avail].next;
            arr[temp].next = -1;
        }
        else
        {
            first = avail;
            arr[first].data = val;
            avail = arr[first].next;
            arr[first].next = -1;
        }
    }
    else
        cout << "List Full" << endl;
}

bool LinkedList::insertAfter(int val, int after)
{
    if (avail != -1)
    {
        if (first != -1)
        {
            int i = first;
            while (i != -1 && arr[i].data != after)
                i = arr[i].next;
            if (i == -1)
            {
                cout << "Element not found" << endl;
                return false;
            }
            else if (arr[i].data == after)
            {
                int newNodeIdx = avail;
                avail = arr[avail].next;
                arr[newNodeIdx].data = val;
                arr[newNodeIdx].next = arr[i].next;
                arr[i].next = newNodeIdx;
            }
        }
        else
        {
            first = avail;
            arr[first].data = val;
            avail = arr[first].next;
            arr[first].next = -1;
        }
        return true;
    }
    return false;
}

bool LinkedList::removeNode(int val)
{
    if (first != -1)
    {
        int i = first;

        if (arr[first].data == val)
        {
            int tempIdx = first;
            avail = first;
            first = arr[first].next;
            return true;
        }

        while (arr[i].next != -1 && arr[arr[i].next].data != val)
            i = arr[i].next;
        if (i == -1)
        {
            cout << "Element not found" << endl;
            return false;
        }

/*  10  20  30  40  50
    1   2   3   4   -1
    2   4

        i = 0
        temp = 2;
        avail = 2;

        arr[i].next = arr[arr[i].next].next;
        arr[temp].next = avail;
        avail = temp;


    */

        int temp = arr[arr[i].next].next;
        arr[i].next = arr[arr[i].next].next;
        arr[temp].next = avail;
        avail = temp;

        return true;
    }

    return false;
}

void LinkedList::display() const
{
    if (first != -1)
    {
        int i = first;

        while (i != -1)
        {
            cout << arr[i].data << " ";
            i = arr[i].next;
        }

        cout << endl;
    }
    else
        cout << "List is empty" << endl;
}

void LinkedList::displayDetails() const
{
    for (int i = 0; i < sz; ++i)
        cout << arr[i].data << "\t";
    cout << endl;
    for (int i = 0; i < sz; ++i)
        cout << arr[i].next << "\t";
    cout << endl;
    // cout << "Avial: " << avail << "First: " << first << endl;
}
