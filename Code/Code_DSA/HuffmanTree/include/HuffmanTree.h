#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include <string>
#include <vector>

struct Node
{
    int data;
    int intCode;
    int bits;

    Node* left;
    Node* right;
};

class HuffmanTree
{
    public:
        HuffmanTree(const std::vector<int>& freq);
        void print() const;

        std::vector<int> getTable() const { return table; }
        Node* getRoot() const { return root; }
    private:
        static const int SIZE = 256;
        //int freq[SIZE];

        Node* root;
        std::vector<int> table;

        void print(Node* p) const;

        void assignBits();
};

#endif // HUFFMANTREE_H
