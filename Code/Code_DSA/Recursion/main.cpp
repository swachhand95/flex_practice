#include "functions.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

char* preToIn(char *pre, char *in)
{
    if (*pre >= 'a' && *pre <= 'z')
    {
        strncat(in, pre, 1);
        return pre;
    }
    else
    {
        //strcat(in, "(");
        char *p = preToIn(pre + 1, in);
        p = preToIn(p + 1, in);
        strncat(in, pre, 1);
        //strcat(in, ")");
        return p;
    }
}

int cannonBall(int ht)
{
    if (ht == 1)
        return 1;
    return ht * ht + cannonBall(ht - 1);
}

int raiseIntToPower(int n, int k)
{
    if (k == 0)
        return 1;
    return n * raiseIntToPower(n, k - 1);
}

int gcd(int a, int b)
{
    if (a < b)
        return gcd(b, a);
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}

int digitSum(int a)
{
    if (a == 0)
        return 0;
    return a % 10 + digitSum(a / 10);
}

int digitalRoot(int n)
{
    if (digitSum(n) / 10 == 0)
        return digitSum(n);
    return digitalRoot(digitSum(n));
}

int combinations(int n, int k)
{
    if (n == 0 || k == 0 || k == n)
        return 1;
    return combinations(n-1, k-1) + combinations(n-1, k);
}

string reverseStr(const string& str)
{
    int n = str.size();
    if (n <= 1)
        return str;
    string ret = str[n-1] + reverseStr(str.substr(0, n-1));
    return ret;
}

//string intToStr(int a)
//{
//    if (a / 10 == 0)
//        return a + '0';
//    // something to do with tail recursion ?
//}

void recursivePermute(const string& prefix, const string& rest)
{
    if (rest == "")
    {
        cout << prefix << endl;
        return;
    }
    for (int i = 0; i < rest.size(); ++i)
    {
        string newPrefix = prefix + rest[i];
        string newRest = rest.substr(0, i) + rest.substr(i + 1);
        recursivePermute(newPrefix, newRest);
    }
}

int main()
{
//    cout << fact(5) << endl;
//    binaryPrint(18);
//    cout << endl;
//    cout << binary(18) << endl;
//    cout << towerOfHanoi(3, 'A', 'B', 'C') << endl;
//
//    int a[4] = {0};
//    nQueen(a, 0, 4);
//
//    cout << endl;
//
//    string exp = "/+ab+cd";
//    string exp1 = "+a/-*bcd-+e*fgh";
//    string exp2 = "++ab^+-*cdef^g+hi";
//    string res = "";
//
//    convert(exp2, exp2.size(), 0, res);
//    char in[40] = {0};
//
//    preToIn(const_cast<char*>(exp2.c_str()), in);
//    cout << in << endl;
//
//    cout << res << endl;
//cout << endl;
//    cout << palindrome("noon", 0, 3) << endl;
//    cout << palindrome("abba", 0, 3) << endl;
//    cout << palindrome("a", 0, 0) << endl;
//    cout << palindrome("aa", 0, 1) << endl;
//    cout << palindrome("swachhand", 0, 8) << endl;

    cout << cannonBall(1) << endl;
    cout << cannonBall(2) << endl;
    cout << cannonBall(3) << endl;
    cout << cannonBall(4) << endl;
    cout << cannonBall(6) << endl;

    cout << endl;

    cout << raiseIntToPower(2, 2) << endl;
    cout << raiseIntToPower(3, 2) << endl;
    cout << raiseIntToPower(4, 5) << endl;
    cout << raiseIntToPower(2, 10) << endl;
    cout << raiseIntToPower(6, 0) << endl;

    cout << endl;

    cout << gcd(10, 3) << endl;
    cout << gcd(5, 3) << endl;
    cout << gcd(12, 3) << endl;
    cout << gcd(10, 45) << endl;
    cout << gcd(99, 47) << endl;

    cout << endl;

    cout << digitSum(1234) << endl;
    cout << digitSum(0) << endl;
    cout << digitSum(98625) << endl;
    cout << digitSum(21) << endl;

    cout << endl;

    cout << digitalRoot(1729) << endl;
    cout << digitalRoot(123) << endl;
    cout << digitalRoot(794) << endl;

    cout << endl;

    cout << combinations(6, 2) << endl;
    cout << combinations(1, 1) << endl;
    cout << combinations(0, 0) << endl;
    cout << combinations(6, 1) << endl;
    cout << combinations(6, 6) << endl;

    cout << endl;

    cout << reverseStr("program") << endl;
    cout << reverseStr("hello") << endl;
    cout << reverseStr("swachhand") << endl;
    cout << reverseStr("potty") << endl;
    cout << reverseStr("aabb") << endl;
    cout << reverseStr("a") << endl;
    cout << reverseStr("") << endl;

    cout << endl;

    recursivePermute("", "abc");
}
