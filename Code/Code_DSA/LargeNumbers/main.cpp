#include "StackLL.h"
#include <iostream>

using namespace std;

#define PR(x) cout << #x << "=" << (x)

void addChar(char a, char b, char& carry, char& res)
{
    res = a + b + carry;

    res -= 3*'0';
    if (res >= 10)
    {
        res -= 10;
        carry = '1';
    }
    else
        carry = '0';

    res += '0';
}

StackLL add(StackLL& a, StackLL& b)
{
    char carry = '0';
    StackLL res;

    Node* top1 = a.top;
    Node* top2 = b.top;

    while (top1 != nullptr && top2 != nullptr)
    {
        char num1 = top1->data;
        char num2 = top2->data;

        char result = '0';

        addChar(num1, num2, carry, result);
        res.push(result);

        top1 = top1->next;
        top2 = top2->next;
    }
    while (top1 != nullptr)
    {
        char result = '0';
        addChar(top1->data, '0', carry, result);
        res.push(result);
        top1 = top1->next;
    }
    while (top2 != nullptr)
    {
        char result = '0';
        addChar(top2->data, '0', carry, result);
        res.push(result);
        top2 = top2->next;
    }

    return res;
}

StackLL sub(StackLL& a, StackLL& b)
{
    StackLL res;
    bool neg = false;

    Node* top1;
    Node* top2;

    if (a.size() >= b.size())
    {
        top1 = a.top;
        top2 = b.top;
    }
    else
    {
        top1 = b.top;
        top2 = a.top;
        neg = true;
    }

    while (top1 != nullptr && top2 != nullptr)
    {
        char num1 = top1->data - '0';
        char num2 = top2->data - '0';

        char result = '0';

        if (num1 >= num2)
            result = num1 - num2;
        else
        {
            --top1->next->data;
            result = num1 + 10 - num2;
        }

        result += '0';
        res.push(result);

        top1 = top1->next;
        top2 = top2->next;
    }
    while (top1 != nullptr)
    {
        res.push(top1->data);
        top1 = top1->next;
    }
    while (top2 != nullptr)
    {
        res.push(top2->data);
        top2 = top2->next;
    }

    while (res.peek() == '0')
        res.pop();

    if (res.empty())
        res.push('0');

    if (neg)
        res.push('-');

    return res;
}

int main()
{
    string a = "123456783425532454634624529";
    string b = "9874252435525342534663425632";

    StackLL num1;
    for (int i = 0; i < a.size(); ++i)
        num1.push(a[i]);

    StackLL num2;
    for (int i = 0; i < b.size(); ++i)
        num2.push(b[i]);

    StackLL num3 = add(num1, num2);
    num3.print();
}
