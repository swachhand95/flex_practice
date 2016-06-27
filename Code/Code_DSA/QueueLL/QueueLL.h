#ifndef QUEUELL_H
#define QUEUELL_H

#define PR(X) cout << #X << " = " << X << endl

struct Node
{
    int data;
    Node* next;
};

class QueueLL
{
    public:
        QueueLL();
        void enqueue(int val);
        int dequeue();
        void print() const;
    private:
        Node *head;
        Node *tail;
};

#endif // QUEUELL_H
