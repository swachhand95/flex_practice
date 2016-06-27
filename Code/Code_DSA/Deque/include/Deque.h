#ifndef DEQUE_H
#define DEQUE_H

class Deque
{
    public:
        Deque(int sz);
        ~Deque();
        void pushBack(int val);
        int popBack();
        void pushFront(int val);
        int popFront();
        bool isEmpty() const;
        bool isFull() const;
    private:
        int *arr;
        int size;
        int head;
        int tail;
};

#endif // DEQUE_H
