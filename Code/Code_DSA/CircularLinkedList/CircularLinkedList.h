#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

#define PR(X) cout << #X << " = " << X << endl

struct Node
{
    int data;
    Node* next;
};

class CircularLinkedList
{
    public:
        CircularLinkedList();
        void add(int val);
        void print() const;
        bool removeNode(int val);
    private:
        Node *last;
};

#endif // CIRCULARLINKEDLIST_H
