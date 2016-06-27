#include "functions.h"
#include <cmath>
#include <iostream>

using namespace std;

long fact(int n)
{
    if (n == 0) return 1;
    return n * fact(n - 1);
}

long fib(int n)
{
    if (n == 0 || n == 1)
        return n;
    return fib(n-1) + fib(n-2);
}

void binaryPrint(int n)
{
    if (n == 0 || n == 1)
    {
        cout << n << " ";
        return;
    }
    binaryPrint(n/2);
    cout << n % 2 << " ";
}

long binary(int n)
{
    if (n == 1) return n;
    return 10 * binary(n/2) + n%2;
}

void printStep(char src, char target)
{
    cout << "Move from " << src << " to " << target << endl;
}

int towerOfHanoi(int n, char src, char temp, char target)
{
    if (n == 1)
    {
        printStep(src, target);
        return 1;
    }
    return towerOfHanoi(n - 1, src, target, temp) +
            towerOfHanoi(1, src, temp, target) +
            towerOfHanoi(n - 1, temp, src, target);
}

bool checkQueen(int a[], int r)
{
    for (int i = 0; i < r; ++i)
    {
        if (a[i] == a[r] || abs(i - r) == abs(a[i] - a[r]))
            return false;
    }
    return true;
}

void printArr(int a[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << a[i] << "," << i << " ";
    cout << endl;
}

void nQueen (int a[], int r, int n)
{
    for (int i = 0; i < n; ++i)
    {
        a[r] = i;

        if (checkQueen(a, r))
        {
            if (r + 1 < n)
                nQueen(a, r + 1, n);
            else
                printArr(a, n);
        }
    }
}

bool isOperator(char ch)
{
    return ch == '+' || ch == '-' ||
            ch == '/' || ch == '*' || ch == '^';
}

int convert(string &exp, int n, int pos, string &exp2)
{
    int cnt = 0;
    int i = pos;
    for (; i < n && cnt != 2; ++i)
    {
        int newPos = i;
        if (isOperator(exp[i]))
        {
            newPos = convert(exp, n, i + 1, exp2);
            exp2 += exp[i];
            ++cnt;
        }
        else
        {
            exp2 += exp[i];
            ++cnt;
        }
        i = newPos;
    }
    return i - 1;
}

bool checkSudoku(int** a, int n, int x, int y)
{
    int blockX = sqrt(n) * (x / sqrt(n));
    int blockY = sqrt(n) * (y / sqrt(n));

    for (int i = blockY; i < blockY + 3; ++i)
    {
        for (int j = blockX; j < blockX + 3; ++j)
        {
            if (j == x || i == y) continue;
            if (a[i][j] == a[y][x]) return false;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        if (i == x) continue;
        if (a[y][i] == a[y][x]) return false;
    }

    for (int i = 0; i < n; ++i)
    {
        if (i == y) continue;
        if (a[i][x] == a[y][x]) return false;
    }

    return true;
}

bool sudokuSolve(int** a, int n, int x, int y, int val)
{
    if (x >= n || y >= n) return true;

    if (a[y][x] != 0)
    {
        if (x + 1 < n && sudokuSolve(a, n, x + 1, y, val + 1))
            return true;
        else if (y + 1 < n && sudokuSolve(a, n, 0, y + 1, val + 1))
            return true;
    }

    for (int i = 1; i <= n; ++i)
    {
        a[y][x] = i;
        if (checkSudoku(a, n, x, y))
        {
            if (x + 1 < n && sudokuSolve(a, n, x + 1, y, val + 1))
                return true;
            else if (y + 1 < n && sudokuSolve(a, n, 0, y + 1, val + 1))
                return true;
        }
    }
}

// noon, 0, 3

bool palindrome(string str, int start, int finish)
{
    if (finish - start < 1)
        return true;
    if (str[start] != str[finish])
        return false;
    return palindrome(str, start + 1, finish - 1);
}
