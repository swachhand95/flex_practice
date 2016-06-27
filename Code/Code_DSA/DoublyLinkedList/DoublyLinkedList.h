#ifndef DOUBLYLINKEDLIST_H_INCLUDED
#define DOUBLYLINKEDLIST_H_INCLUDED

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

class DoublyLinkedList
{
    Node *first;
    void swapNodes(Node **a, Node **b);
public:
    DoublyLinkedList();
    bool add(int data);
    void display() const;
    void revDisplay() const;
    bool remove(int val);
    bool insertAt(int val, int pos);
};

#endif // DOUBLYLINKEDLIST_H_INCLUDED
