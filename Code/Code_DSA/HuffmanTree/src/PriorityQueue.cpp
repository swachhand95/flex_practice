//#include "PriorityQueue.h"
//#include <iostream>
//
//using namespace std;
//
//template <class T> PriorityQueue<T>::PriorityQueue() : top{nullptr} {}
//
//template <class T> void PriorityQueue<T>::add(const T& val, int priority)
//{
//    Node* newNode = new Node;
//    newNode->data = val;
//    newNode->priority = priority;
//
//    if (top == nullptr)
//        top = newNode;
//    else
//    {
//        Node* p = top;
//        Node* prev = nullptr;
//
//        if (top->priority > priority)
//        {
//            newNode->next = top;
//            top = newNode;
//            return;
//        }
//
//        while (p != nullptr && p->priority <= priority)
//        {
//            prev = p;
//            p = p->next;
//        }
//
//        newNode->next = prev->next;
//        prev->next = newNode;
//    }
//}
//
//template <class T> T PriorityQueue<T>::getMin() const
//{
//    return top != nullptr ? top->data : T();
//}
//
//template <class T> T PriorityQueue<T>::deleteMin()
//{
//    T ret = getMin();
//
//    if (top != nullptr)
//    {
//        Node* temp = top;
//        top = top->next;
//        delete temp;
//    }
//
//    return ret;
//}
//
//template <class T> void PriorityQueue<T>::print() const
//{
//    if (top != nullptr)
//    {
//        Node *p = top;
//        while (p != nullptr)
//        {
//            std::cout << p->data << " ";
//            p = p->next;
//        }
//        std::cout << std::endl;
//    }
//    else
//        std::cout << "List Empty" << std::endl;
//}
//
//template <class T> bool PriorityQueue<T>::empty() const
//{
//    return top == nullptr;
//}
