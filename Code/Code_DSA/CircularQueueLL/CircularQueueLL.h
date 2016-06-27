#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

#define PR(X) cout << #X << " = " << X << endl

struct Node
{
    int data;
    Node* next;
};

class Queue
{
    public:
        Queue();
        void enqueue(int val);
        void print() const;
        int dequeue();
    private:
        Node *head;
};

#endif // CIRCULARLINKEDLIST_H
