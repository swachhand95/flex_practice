#include "BinarySearchTree.h"
#include <iostream>

using namespace std;

int main()
{
    BinarySearchTree bst;
//    bst.addIter(50);
//    bst.add(40);
//    bst.add(90);
//    bst.add(20);
//    bst.addIter(45);
//    bst.add(80);
//    bst.add(100);
//    bst.addIter(30);
//    bst.add(70);
//    bst.add(85);
//    bst.add(75);

    bst.addIter(50);
    bst.addIter(25);
    bst.addIter(60);
    bst.addIter(45);
    bst.addIter(70);
    bst.addIter(55);

    bst.preorderStack();
    cout << endl;
    bst.inorder();
    cout << endl;    bst.inorderStack();
    cout << endl;
    bst.postorder();
    cout << endl;
    bst.postorderStack();
    cout << endl;

    cout << "Number of Nodes: " << bst.count() << endl;
    cout << "Max = " << bst.max() << endl;
    cout << "Height = " << bst.height() << endl;
    if (bst.search(30))
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    cout << endl << endl;

    bst.deleteNode(70);
    bst.inorder();
    cout << endl;
    bst.deleteNode(50);
    bst.inorder();
    cout << endl;
    bst.deleteNode(100);
    bst.inorder();
    cout << endl;
    bst.deleteNode(90);
    bst.inorder();
    cout << endl;

    return 0;
}
