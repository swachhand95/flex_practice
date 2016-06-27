#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#define PR(X) cout << #X << " = " << X << endl

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class BinarySearchTree
{
    public:
        BinarySearchTree();

        void add(int val);
        void addIter(int val);

        void preorder() const;
        void inorder() const;
        void postorder() const;

        void preorderStack() const;
        void inorderStack() const;
        void postorderStack() const;

        int count() const;
        int max() const;
        bool search(int val) const;
        int height() const;

        bool deleteNode(int val);
    private:
        Node *root;

        void add(Node **p, int val);

        void preorder(Node *p) const;
        void inorder(Node *p) const;
        void postorder(Node *p) const;

        int count(Node *p) const;
        int height(Node *p) const;
};

#endif // BINARYSEARCHTREE_H
