#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

class Heap
{
private:
    int* a;
    int sz;
    int last;
    int parentIdx(int p) { return (p - 1) / 2; }
    int leftIdx(int p) { return 2*p + 1; }
    int rightIdx(int p) { return 2*p + 2; }
public:
    Heap(int n) : a{new int[n]}, sz{n}, last{0} {}
    ~Heap() { delete []a; }
    bool add(int val);
    int remove();
    int getTop() const;
    void print() const;
};

#endif // HEAP_H_INCLUDED
