#include "ThreadedBST.h"
#include <iostream>

using namespace std;

int main()
{
    ThreadedBST t;

    t.add(50);
    t.add(70);
    t.add(60);
    t.add(65);
    t.add(25);
    t.add(35);

    t.inorder();
}
