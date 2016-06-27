#include <iostream>

using namespace std;

inline int fact(int n)
{
    int f = 1;

//    for (int i = 1; i <= n; ++i)
//        f *= i;

    return f;
}

int fact1(int n)
{
    if (n == 0)
        return 1;
    return n * fact(n-1);
}

int main()
{
    int i = fact(5);
    ++i;
}
