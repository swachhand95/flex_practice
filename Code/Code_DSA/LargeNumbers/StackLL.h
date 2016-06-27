#ifndef STACKLL_H
#define STACKLL_H

#define PR(X) cout << #X << " = " << X << endl

struct Node
{
    char data;
    Node* next;
};

class StackLL
{
    public:
        StackLL();
        void push(char val);
        char pop();
        char peek() const;
        void print() const;
        bool empty() const;
        int size() const;
        friend StackLL add(StackLL& a, StackLL& b);
        friend StackLL sub(StackLL& a, StackLL& b);
    private:
        Node *top;
        int sz;
};

#endif // STACKLL_H
