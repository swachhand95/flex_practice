#include "BinarySearchTree.h"
#include <iostream>

using namespace std;

BinarySearchTree::BinarySearchTree() : root {nullptr} {}

void BinarySearchTree::add(int val)
{
    add(&root, val);
}

void BinarySearchTree::add(Node **p, int val)
{
    if (*p == nullptr)
    {
        Node *newNode = new Node;
        newNode->data = val;
        newNode->left = nullptr;
        newNode->right = nullptr;

        *p = newNode;
    }
    else
    {
        if ((*p)->data > val)
            add(&(*p)->left, val);
        else
            add(&(*p)->right, val);
    }
}

void BinarySearchTree::addIter(int val)
{
    Node* newNode = new Node;
    newNode->data = val;
    newNode->left = nullptr;
    newNode->right = nullptr;

    Node* p = root;
    Node* prev = nullptr;

    if (p == nullptr)
    {
        root = newNode;
    }
    else
    {
        while (p != nullptr)
        {
            prev = p;
            p = p->data > val ? p->left : p->right;
        }

        if (prev->data > val)
            prev->left = newNode;
        else
            prev->right = newNode;
    }
}

void BinarySearchTree::preorder() const
{
    preorder(root);
}

void BinarySearchTree::preorder(Node *p) const
{
    if (p == nullptr)
        return;
    else
    {
        cout << p->data << "\t";
        preorder(p->left);
        preorder(p->right);
    }
}

void BinarySearchTree::inorder() const
{
    inorder(root);
}

void BinarySearchTree::inorder(Node *p) const
{
    if (p == nullptr)
        return;
    else
    {
        inorder(p->left);
        cout << p->data << "\t";
        inorder(p->right);
    }
}

void BinarySearchTree::postorder() const
{
    postorder(root);
}

void BinarySearchTree::postorder(Node *p) const
{
    if (p == nullptr)
        return;
    else
    {
        postorder(p->left);
        postorder(p->right);
        cout << p->data << "\t";
    }
}

int BinarySearchTree::count() const
{
    return count(root);
}

int BinarySearchTree::count(Node* p) const
{
    if (p == nullptr) return 0;
    return 1 + count(p->left) + count(p->right);
}

int BinarySearchTree::max() const
{
    if (root != nullptr)
    {
        Node *p = root;

        while (p->right != nullptr)
            p = p->right;

        return p->data;
    }

    cout << "Tree is empty" << endl;
    return -1;
}

bool BinarySearchTree::search(int val) const
{
    bool found = false;

    Node *p = root;

    while (p != nullptr && p->data != val)
    {
        if (val > p->data)
            p = p->right;
        else
            p = p->left;
    }

    if (p != nullptr)
        found = true;

    return found;
}

int BinarySearchTree::height() const
{
    return height(root);
}

int BinarySearchTree::height(Node *p) const
{
    if (p == nullptr)
        return 0;
    if (p->left == nullptr && p->right == nullptr)
        return 0;
    return 1 + std::max(height(p->left), height(p->right));
}

bool BinarySearchTree::deleteNode(int val)
{
    Node* p = root;
    Node* prev = nullptr;

    while (p != nullptr && p->data != val)
    {
        prev = p;

        if (val < p->data)
            p = p->left;
        else
            p = p->right;
    }

    if (p == nullptr)
        return false;

    if (p->left != nullptr && p->right != nullptr)
    {
        Node *succ = p->right;
        prev = p;

        while (succ->left != nullptr)
        {
            prev = succ;
            succ = succ->left;
        }

        p->data = succ->data;
        p = succ;
    }

    if (p == root)
    {
        if (p->left == nullptr)
            root = p->right;
        else
            root = p->left;
    }
    else if (p->left != nullptr && p->right == nullptr)
    {
        if (prev->left == p)
            prev->left = p->left;
        else
            prev->right = p->left;
    }
    else if (p->left == nullptr && p->right != nullptr)
    {
        if (prev->left == p)
            prev->left = p->right;
        else
            prev->right = p->right;
    }
    else if (p->left == nullptr && p->right == nullptr)
    {
        if (prev->left == p)
            prev->left = nullptr;
        else
            prev->right = nullptr;
    }

    delete p;
    return true;
}

void BinarySearchTree::preorderStack() const
{
    Node* a[20];
    int top = -1;

    Node* p = root;

    while (true)
    {
        while (p != nullptr)
        {
            cout << p->data << "\t";
            a[++top] = p;
            p = p->left;
        }

        if (top != -1)
        {
            p = a[top--];
            p = p->right;
        }
        else
            break;
    }
}

void BinarySearchTree::inorderStack() const
{
    Node* a[20];
    int top = -1;

    Node* p = root;

    while (true)
    {
        while (p != nullptr)
        {
            a[++top] = p;
            p = p->left;
        }

        if (top != -1)
        {
            p = a[top--];
            cout << p->data << "\t";
            p = p->right;
        }
        else
            break;
    }
}

void BinarySearchTree::postorderStack() const
{
    Node* a[20];
    int b[20] = {0};
    int top = -1;

    Node* p = root;

    while (true)
    {
        while (p != nullptr)
        {
            // push into stack
            ++top;
            a[top] = p;
            b[top] = 0;
            p = p->left;
        }

        while (top != -1 && b[top] == 1)
        {
            p = a[top];
            --top;
            cout << p->data << " ";
        }

        if (top == -1)
            break;

        ++b[top];
        p = a[top]->right;
    }
}
