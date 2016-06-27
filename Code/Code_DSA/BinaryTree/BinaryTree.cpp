#include "BinaryTree.h"
#include <iostream>
#include <cmath>
#include <stack>

using namespace std;

BinaryTree::BinaryTree() : root {nullptr} {}

BinaryTree::BinaryTree(Node* p) : root {p} {}

void BinaryTree::add(int val)
{
    add(&root, val);
}

void BinaryTree::add(Node **p, int val)
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
        cout << "Inserting " << val << " ";
        cout << "Enter 1.left 2.right of " << (*p)->data << ": ";

        char in = 0;
        cin >> in;

        if (in == '1')
            add(&(*p)->left, val);
        else
            add(&(*p)->right, val);

    }
}

void BinaryTree::preorder() const
{
    preorder(root);
}

void BinaryTree::preorder(Node *p) const
{
    if (p == nullptr)
        return;
    else
    {
        if (isOperator((char) p->data))
            cout << (char) p->data << "\t";
        else cout << p->data << "\t";
        preorder(p->left);
        preorder(p->right);
    }
}

void BinaryTree::inorder() const
{
    inorder(root);
}

void BinaryTree::inorder(Node *p) const
{
    if (p == nullptr)
        return;
    else
    {
        inorder(p->left);
        if (isOperator((char) p->data))
            cout << (char) p->data << "\t";
        else cout << p->data << "\t";
        inorder(p->right);
    }
}

void BinaryTree::postorder() const
{
    postorder(root);
}

void BinaryTree::postorder(Node *p) const
{
    if (p == nullptr)
        return;
    else
    {
        postorder(p->left);
        postorder(p->right);
        if (isOperator((char) p->data))
            cout << (char) p->data << "\t";
        else cout << p->data << "\t";
    }
}

int BinaryTree::count() const
{
    return count(root);
}

int BinaryTree::count(Node* p) const
{
    if (p == nullptr) return 0;
    return 1 + count(p->left) + count(p->right);
}

int BinaryTree::max() const
{
    return max(root);
}

int BinaryTree::max(Node *p) const
{
    if (p == nullptr)
        return -1;
    if (p->left == nullptr && p->right == nullptr)
        return p->data;
    return std::max(std::max(p->data, max(p->left)),
                    std::max(p->data, max(p->right)));
}

bool BinaryTree::search(int val) const
{
    return search(root, val);
}

bool BinaryTree::search(Node *p, int val) const
{
    if (p == nullptr)
        return false;
    if (p->data == val)
        return true;
    if (search(p->left, val))
        return true;
    else if (search(p->right, val))
        return true;
    return false;
}

int BinaryTree::height() const
{
    return height(root);
}

int BinaryTree::height(Node *p) const
{
    if (p == nullptr)
        return 0;
    if (p->left == nullptr && p->right == nullptr)
        return 0;
    return 1 + std::max(height(p->left), height(p->right));
}

bool BinaryTree::strictBinaryTree() const
{
    return strictBinaryTree(root);
}

bool BinaryTree::strictBinaryTree(Node* p) const
{
    if (p == nullptr)
        return false;
    if (p->left == nullptr && p->right == nullptr)
        return true;
    else if (p->left != nullptr && p->right != nullptr)
        return strictBinaryTree(p->left) && strictBinaryTree(p->right);
    return false;
}

bool BinaryTree::completeBinaryTree() const
{
    return completeBinaryTree(root);
}

//bool BinaryTree::completeBinaryTree(Node* p, int level, int ht) const
//{
//    if (p == nullptr)
//        return false;
//
//    if (p->left == nullptr && p->right == nullptr)
//    {
//        if (level == ht)
//            return true;
//        return false;
//    }
//
//    if (p->left != nullptr && p->right != nullptr)
//        return completeBinaryTree(p->left, level + 1, ht) &&
//               completeBinaryTree(p->right, level + 1, ht);
//}

int BinaryTree::completeBinaryTree(Node* p) const
{
    if (p == nullptr)
        return false;

    if (p->left == nullptr && p->right == nullptr)
        return false;

    if (p->left != nullptr && p->right != nullptr)
    {
        int x = completeBinaryTree(p->left);
        int y = completeBinaryTree(p->right);
        return x != 0 && x == y ? x + 1 : 0;
    }
}


bool BinaryTree::deleteNode(int val)
{
    Node* p = root;
    Node* prev = nullptr;

    if (p == nullptr)
        return false;

    if (p->data != val)
    {
        prev = searchParent(p, val);
        if (prev == nullptr)
            p = nullptr;
        else if (prev->left->data == val)
            p = prev->left;
        else
            p = prev->right;
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

Node* BinaryTree::searchParent(Node* p, int v)
{
    if (p == nullptr)
        return nullptr;
    if ((p->left != nullptr && p->left->data == v) ||
        (p->right != nullptr && p->right->data == v))
            return p;
    else
    {
        Node *x = searchParent(p->left, v);
        if (x != nullptr)
            return x;
        else
        {
            Node *y = searchParent(p->right, v);
            return y;
        }
    }
}

void BinaryTree::treeFromPostfix(const string& exp, double var[])
{
    root = nullptr;

    Node* stck[50] = {0};
    int top = -1;

    for (int i = 0; i < exp.size(); ++i)
    {
        Node* newNode = new Node;

        if (exp[i] >= 'a' && exp[i] <= 'z')
        {
            newNode->data = var[exp[i] - 'a'];

            newNode->left = nullptr;
            newNode->right = nullptr;
        }
        else
        {
            newNode->data = exp[i];

            newNode->right = stck[top--];
            newNode->left = stck[top--];

            root = newNode;
        }

        stck[++top] = newNode;
    }
}

double BinaryTree::operation(double a, double b, char op)
{
    switch(op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '/':
        return a / b;
    case '*':
        return a * b;
    case '%':
        return (int) a % (int) b;
    case '^':
        return pow(a, b);
    }
    return 0;
}

double BinaryTree::evaluateTree()
{
    return evaluateTree(root);
}

double BinaryTree::evaluateTree(Node* p)
{
    if (p == nullptr)
        return 0;
    if (!isOperator(p->data))
        return p->data;
    else return operation(evaluateTree(p->left),
                          evaluateTree(p->right),
                          (char)p->data);
}

bool BinaryTree::isOperator(char ch) const
{
    switch(ch)
    {
    case '+':
    case '-':
    case '/':
    case '*':
    case '%':
    case '^':
        return true;
    default:
        return false;
    }
}
