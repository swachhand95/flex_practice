#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <string>

long fact(int n);
long fib(int n);
void binaryPrint(int n);
long binary(int n);
int towerOfHanoi(int n, char src, char temp, char target);

bool checkQueen(int a[], int r);
void printArr(int a[], int n);
void nQueen (int a[], int r, int n);

bool isOperator(char ch);
int convert(std::string &exp, int n, int pos, std::string &exp2);
bool checkSudoku(int** a, int n, int x, int y);
bool sudokuSolve(int** a, int n, int x, int y, int val);

bool palindrome(std::string str, int start, int finish);

#endif // FUNCTIONS_H_INCLUDED
