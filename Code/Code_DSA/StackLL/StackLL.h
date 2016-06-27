#ifndef STACKLL_H
#define STACKLL_H

#define PR(X) cout << #X << " = " << X << endl

struct Node
{
    int data;
    Node* next;
};

class StackLL
{
    public:
        StackLL();
        void push(int val);
        int pop();
        int peek() const;
        void print() const;
    private:
        Node *top;
};

#endif // STACKLL_H
