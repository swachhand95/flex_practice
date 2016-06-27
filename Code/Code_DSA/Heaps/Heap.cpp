#include "Heap.h"
#include <iostream>

using namespace std;

bool Heap::add(int val)
{
    if (last >= sz)
    {
        cout << "Heap is full" << endl;
        return false;
    }

    if (last == 0)
        a[last] = val;
    else
    {
        int idx = last;
        int parIdx = parentIdx(last);

        while (a[parIdx] > val)
        {
            if (idx != parIdx)
                a[idx] = a[parIdx];
            else
                break;

            idx = parentIdx(last);
            parIdx = parentIdx(idx);
        }

        a[idx] = val;
    }

    ++last;

    return true;
}

int Heap::getTop() const
{
    return a[0];
}

int Heap::remove()
{
    if (last == 0)
    {
        cout << "Heap is empty" << endl;
        return -1;
    }

    int ret = a[0];
    int key = a[--last];

    int i = 1;
    for (; i < last; i = leftIdx(i))
    {
        if ((i+1) < last && a[i] > a[i+1])
            ++i;
        if (a[i] < key)
            a[parentIdx(i)] = a[i];
        else
            break;
    }

    a[parentIdx(i)] = key;

    return ret;
}

void Heap::print() const
{
    for (int i = 0; i < last; ++i)
        cout << a[i] << " ";
    cout << endl;
}
