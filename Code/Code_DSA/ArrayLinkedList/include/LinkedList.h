#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node
{
    int data;
    int next;
};

class LinkedList
{
    public:
        LinkedList(int n);
        ~LinkedList();
        void add(int val);
        bool insertAfter(int val, int after);
        bool removeNode(int val);
        void display() const;
        void displayDetails() const;
    private:
        int sz;
        int first;
        int avail;
        Node *arr;
};

#endif // LINKEDLIST_H
