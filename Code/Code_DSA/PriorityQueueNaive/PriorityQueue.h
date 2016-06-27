#ifndef PRIORITYQUEUE_H_INCLUDED
#define PRIORITYQUEUE_H_INCLUDED

struct Item
{
    int data;
    int priority;
    Item() : data{0}, priority{-1} {}
    Item(int val, int pri) : data{val}, priority{pri} {}
};

class PriorityQueue
{
private:
    Item *arr;
    int tail;
    int cnt;
    int sz;
public:
    PriorityQueue(int n);
    ~PriorityQueue();
    bool isEmpty() const;
    bool isFull() const;
    void insertItem(int val, int priority);
    Item getHighestPriorityItem() const;
    void deleteHighestPriorityItem();
};

#endif // PRIORITYQUEUE_H_INCLUDED
