#ifndef THREADEDBST_H
#define THREADEDBST_H

struct Node
{
    int data;
    Node* left;
    Node* right;
    bool lf, rf;
};

class ThreadedBST
{
    public:
        ThreadedBST();
        void add(int val);
        void inorder() const;
    private:
        Node* root;
};

#endif // THREADEDBST_H
