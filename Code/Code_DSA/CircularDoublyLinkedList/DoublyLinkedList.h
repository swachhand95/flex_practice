#ifndef DOUBLYLINKEDLIST_H_INCLUDED
#define DOUBLYLINKEDLIST_H_INCLUDED

#define PR(X) cout << #X << " = " << X << endl

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

class DoublyLinkedList
{
    Node *last;
public:
    DoublyLinkedList();
    bool add(int data);
    void display() const;
    void revDisplay() const;
    bool remove(int val);
};

#endif // DOUBLYLINKEDLIST_H_INCLUDED
