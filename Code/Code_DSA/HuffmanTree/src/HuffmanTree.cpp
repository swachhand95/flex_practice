#include "HuffmanTree.h"
#include "PriorityQueue.h"

#include <string>
#include <stack>
#include <iostream>

using namespace std;

HuffmanTree::HuffmanTree(const vector<int>& freq) :
    /*freq{0},*/ root{nullptr}
{
    table.resize(2*SIZE);

    PriorityQueue<Node*> pq;

    // check the comparison if error occurs
    for (int i = 0; i < freq.size(); i += 2)
    {
        Node* newNode = new Node();
        newNode->data = freq[i];

        pq.add(newNode, freq[i+1]);
    }

//    pq.print();

    while (!pq.empty())
    {
        int priority = pq.getMinPriority();
        Node* leftNode = pq.deleteMin();

        if (pq.empty())
            break;

        priority += pq.getMinPriority();
        Node* rightNode = pq.deleteMin();

        Node* parent = new Node();
        parent->data = -1;
        parent->left = leftNode;
        parent->right = rightNode;

        root = parent;

        pq.add(parent, priority);

//        pq.print();
    }

    assignBits();

}

void HuffmanTree::print() const
{
    print(root);
}

void HuffmanTree::print(Node* p) const
{
    if (p == nullptr)
        return;

    if (p->data != -1)
        cout << (char) p->data << endl;
    else cout << -1 << endl;

    print(p->left);
    print(p->right);
}

void HuffmanTree::assignBits()
{
    Node* prev = root;
    Node* p = root->left;

    Node* s[100];
    int top = -1;

    s[++top] = root;

    while (true)
    {
        while(p != nullptr)
        {
            p->intCode |= prev->intCode;

            if (prev->left == p)
            {
                p->intCode <<= 1;
            }
            else if (prev->right == p)
            {
                p->intCode <<= 1;
                p->intCode |= 1;
            }

            p->bits += (prev->bits + 1);

            if (p->left == nullptr && p->right == nullptr)
            {
                table[2 * p->data] = p->bits;
                table[2 * p->data + 1] = p->intCode;
            }
            s[++top] = p;

            prev = p;
            p = p->left;
        }

        if(top == -1)
          break;

        p = s[top--];
        prev = p;
        p = p->right;
    }
}
