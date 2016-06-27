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
    Node nil;
    void insertNode(Node* x);
public:
    DoublyLinkedList();
    bool add(int data);
    void display() const;
    void revDisplay() const;
    bool removeNode(int val);
    void listUnion(DoublyLinkedList &other);
};

#endif // DOUBLYLINKEDLIST_H_INCLUDED
