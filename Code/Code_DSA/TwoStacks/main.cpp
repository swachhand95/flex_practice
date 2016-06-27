#include <iostream>

using namespace std;

class TwoStacks
{
public:
    TwoStacks(int sz) : arr{new int[sz]}, top1{0}, top2{sz - 1}, size{sz} {}
    bool isStackOneEmpty() { return top1 == 0; }
    bool isStackTwoEmpty() { return top2 == size - 1; }
    bool isFull() { return top1 == top2; }
    bool pushStackOne(int val)
    {
        if (!isFull())
        {
            arr[top1] = val;
            ++top1;
            return true;
        }
        cout << "OverFlow" << endl;
        return false;
    }
    int popStackOne()
    {
        if (!isStackOneEmpty())
        {
            --top1;
            return arr[top1];
        }
        return -1;
    }

    bool pushStackTwo(int val)
    {
        if (!isFull())
        {
            arr[top2] = val;
            --top2;
            return true;
        }
        cout << "OverFlow" << endl;
        return false;
    }
    int popStackTwo()
    {
        if (!isStackTwoEmpty())
        {
            ++top2;
            return arr[top2];
        }
        return -1;
    }
private:
    int *arr;
    int size;
    int top1;
    int top2;
};

int main()
{
    TwoStacks ts(5);

    ts.pushStackOne(1);
    ts.pushStackOne(2);
    ts.pushStackTwo(3);
    ts.pushStackTwo(4);
    ts.pushStackTwo(4);

    cout << ts.popStackOne() << endl;
    cout << ts.popStackOne() << endl;
    cout << ts.popStackOne() << endl;

    cout << ts.popStackTwo() << endl;
    cout << ts.popStackTwo() << endl;
    cout << ts.popStackTwo() << endl;
}
