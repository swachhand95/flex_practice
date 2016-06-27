#include "BinaryTree.h"
#include <iostream>

using namespace std;

int main()
{
    BinaryTree bt;

//    bt.add(10);
//    bt.add(20);
//    bt.add(30);
//    bt.add(40);
//    bt.add(50);
//    bt.add(80);
//    bt.add(90);

//    bt.treeFromPostfix("abc*d-efg*+h-/+");
    double var[6] = {10, 20, 30, 15, 3};
    bt.treeFromPostfix("ab*cde/-+", var);
    cout << bt.evaluateTree() << endl;

    bt.preorder();
    cout << endl;

    bt.inorder();
    cout << endl;

    bt.postorder();
    cout << endl;

//    cout << bt.search(10) << endl;
//    cout << bt.search(50) << endl;
//    cout << bt.search(85) << endl;
//    cout << bt.search(15) << endl;
//    cout << bt.search(40) << endl;
//
//    cout << "Max = " << bt.max() << endl;
//
//    cout << "Strictly Binary Tree: " << bt.strictBinaryTree() << endl;
//    cout << "Complete Binary Tree: " << bt.completeBinaryTree() << endl;
}
