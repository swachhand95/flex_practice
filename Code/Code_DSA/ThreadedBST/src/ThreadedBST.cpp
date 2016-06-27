#include "ThreadedBST.h"
#include <iostream>

using namespace std;

ThreadedBST::ThreadedBST() : root{nullptr} {}

void ThreadedBST::add(int val)
{
    Node* newNode = new Node;
    newNode->data = val;
    newNode->lf = newNode->rf = false;

    if (root == nullptr)
    {
        root = newNode;
        newNode->left = nullptr;
        newNode->right = nullptr;
    }
    else
    {
        Node* p = root;

        while (true)
        {
            if (p->data > val && p->lf)
                p = p->left;
            else if (p->data < val && p->rf)
                p = p->right;
            else break;
        }

        if (p->data > val)
        {
            newNode->left = p->left;
            p->left = newNode;
            p->lf = true;
            newNode->right = p;
        }
        else
        {
            newNode->right = p->right;
            p->right = newNode;
            p->rf = true;
            newNode->left = p;
        }
    }
}

void ThreadedBST::inorder() const
{

}
