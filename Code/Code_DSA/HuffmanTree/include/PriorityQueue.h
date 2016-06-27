#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>

#define PR(X) cout << #X << " = " << (X) << endl

template <class T>
class PriorityQueue
{
    public:
        PriorityQueue();

        void add(const T& val, int priority);

        T getMin() const;
        int getMinPriority() const;
        T deleteMin();

        void print() const;

        bool empty() const;
    private:
        struct Node
        {
            T data;
            int priority;
            Node* next;
        };

        Node* top;
};

template <class T> PriorityQueue<T>::PriorityQueue() : top{nullptr} {}

template <class T> void PriorityQueue<T>::add(const T& val, int priority)
{
    Node* newNode = new Node();
    newNode->data = val;
    newNode->priority = priority;

    if (top == nullptr)
        top = newNode;
    else
    {
        Node* p = top;
        Node* prev = nullptr;

        if (top->priority > priority)
        {
            newNode->next = top;
            top = newNode;
            return;
        }

        while (p != nullptr && p->priority <= priority)
        {
            prev = p;
            p = p->next;
        }

        newNode->next = prev->next;
        prev->next = newNode;
    }
}

template <class T> T PriorityQueue<T>::getMin() const
{
    return top != nullptr ? top->data : T();
}

template <class T> int PriorityQueue<T>::getMinPriority() const
{
    return top != nullptr ? top->priority : -1;
}

template <class T> T PriorityQueue<T>::deleteMin()
{
    T ret = getMin();

    if (top != nullptr)
    {
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    return ret;
}

template <class T> void PriorityQueue<T>::print() const
{
    if (top != nullptr)
    {
        Node *p = top;
        while (p != nullptr)
        {
            std::cout << "[" << (char) p->data->data << "," << p->priority << "] ";
            p = p->next;
        }
        std::cout << std::endl;
    }
    else
        std::cout << "List Empty" << std::endl;
}

template <class T> bool PriorityQueue<T>::empty() const
{
    return top == nullptr;
}


#endif // PRIORITYQUEUE_H
