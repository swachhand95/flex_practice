#include "StackLL.h"
#include <iostream>

using namespace std;

int main()
{
    StackLL s;
    for (int i = 1; i <= 10; ++i)
        s.push(i);
    s.print();
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    s.push(100);
    s.print();
    cout << s.pop() << endl;
    s.push(3000);
    cout << s.pop() << endl;

}
