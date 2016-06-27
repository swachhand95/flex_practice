#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class BinaryTree
{
    public:
        BinaryTree();
        BinaryTree(Node* root);

        void add(int val);

        void preorder() const;
        void inorder() const;
        void postorder() const;

        int count() const;
        int max() const;
        bool search(int val) const;
        int height() const;

        bool completeBinaryTree() const;
        bool strictBinaryTree() const;
        bool deleteNode(int val);

        void treeFromPostfix(const std::string& str, double var[]);
        double evaluateTree();
    private:
        Node* root;

        void add(Node **p, int val);

        void preorder(Node *p) const;
        void inorder(Node *p) const;
        void postorder(Node *p) const;

        int count(Node *p) const;
        int max(Node *p) const;
        bool search(Node *p, int val) const;
        int height(Node *p) const;

        bool strictBinaryTree(Node *p) const;
        int completeBinaryTree(Node *p) const;

        Node* searchParent(Node *p, int v);
        double operation(double a, double b, char op);
        double evaluateTree(Node* p);
        bool isOperator(char ch) const;
};

#endif // BINARYTREE_H
