#ifndef COMPRESSION_H
#define COMPRESSION_H

#include <fstream>

class Compression
{
    public:
        Compression();
    private:
        HuffmanTree t;
        ofstream fout;
        ifstream fin;
};

#endif // COMPRESSION_H
