#include "PriorityQueue.h"
#include "HuffmanTree.h"
#include <iostream>
#include <fstream>

using namespace std;

string makeBitString(char ch, int numBits);

long getFileSize(const string& fileName)
{
    ifstream fin(fileName, ios::binary | ios::ate);

    if (fin.is_open())
        return fin.tellg();

    return -1;
}

/*
        bits = 4
        bits to fill = 7
        code =  0   0   0   0   0   1   1   0
        ch =    0   0   0   0   0   0   0   0

        ch |= ((code >> bits) & 1) << bitstofill
        bits--

        bitstofill--
        if bitstofill == 0
            res += ch
            ch = 0;
            bitstofill = 7
*/

void compress(const string& msg, HuffmanTree& t, string& res)
{
    res = "";
    //res.resize(msg.size());

    vector<int> table = t.getTable();

    cout << "Table copied" << endl;

    char ch = 0;
    int bitsToFill = 7;

    cout << "Compression began" << endl;

    for (long long i = 0; i < msg.size(); ++i)
    {
        int bits = table[2 * msg[i]];
        int code = table[2 * msg[i] + 1];

/*
        cout << msg[i] << " " << makeBitString(code, bits) << endl;
        -- FOR DEBUGGING PURPOSES --
        cout << msg[i] << " ";
        PR(bits);
        PR(code);
*/
        while (bits--)
        {
            ch |= (((code >> bits) & 1) << bitsToFill);
            --bitsToFill;
            if (bitsToFill < 0)
            {
                res += ch;
                ch = 0;
                bitsToFill = 7;
            }
        }
    }
    res += ch;

    cout << "Compression done:" << endl;
}

void compress(const string& msg, HuffmanTree& t, ofstream& out)
{
    vector<int> table = t.getTable();

    cout << "Table copied" << endl;

    char ch = 0;
    int bitsToFill = 7;

    cout << "Compression began" << endl;

    for (int i = 0; i < msg.size(); ++i)
    {
        int bits = table[2 * msg[i]];
        int code = table[2 * msg[i] + 1];

        while (bits--)
        {
            ch |= (((code >> bits) & 1) << bitsToFill);
            --bitsToFill;
            if (bitsToFill < 0)
            {
                out.write(&ch, sizeof(char));
                ch = 0;
                bitsToFill = 7;
            }
        }
    }
    out.write(&ch, sizeof(char));

    cout << "Compression done" << endl;
}


void printBinary(char ch)
{
    for (int i = 7; i >= 0; --i)
        cout << ((ch >> i) & 1);
    cout << endl;
}

string makeBitString(char ch, int numBits)
{
    string ret;

    while (numBits--)
        ret += ((ch >> numBits) & 1) ? '1' : '0';

    return ret;
}

vector<int> generateFreq(const string& in)
{
    int freq[256] = {0};
    for (auto ch : in)
        ++freq[ch];

    vector<int> ret;
    for (int i = 0; i < 256; ++i)
    {
        if (freq[i] > 0)
        {
            ret.push_back(i);
            ret.push_back(freq[i]);
        }
    }

    return ret;
}

bool writeTableToFile(const string& file, const vector<int>& table)
{
    ofstream fout(file, ios::binary);

    if (!fout.is_open())
        return false;

    int sz = table.size();
    fout.write((char*) &sz, sizeof(int));

    for (int i = 0; i < table.size(); ++i)
    {
        int x = table[i];
        fout.write((char*) &x, sizeof(int));
    }

    fout.close();
    return true;
}

bool generateFreqFromFile(const string& file, vector<int>& freq)
{
    ifstream fin(file, ios::binary);

    if (!fin.is_open())
        return false;

    int sz = 0;
    fin.read((char*) &sz, sizeof(int));

    freq.clear();
    for (int i = 0; i < sz; ++i)
    {
        int data = 0;
        fin.read((char*) &data, sizeof(int));
        freq.push_back(data);
    }

    fin.close();
    return true;
}


bool compressFile(const string& inFile, const string& outFile)
{
    ifstream fin(inFile, ios::binary);

    if (!fin.is_open())
        return false;

    string contents;
    fin.seekg(0, ios::end);
    contents.resize(fin.tellg());
    fin.seekg(0, ios::beg);
    fin.read(&contents[0], contents.size());
    fin.close();

    //cout << contents << endl;

    vector<int> freq = generateFreq(contents);
    HuffmanTree t(freq);
    if (writeTableToFile(outFile, freq))
    {
        cout << "Table written to the file successfully" << endl;
    }
    else
    {
        cout << "Could not write table to file." << endl;
        return false;
    }

    ofstream fout(outFile, ios::binary | ios::app);

    if (!fout.is_open())
        return false;

    string compressed;
    compress(contents, t, compressed);

//    cout << compressed << endl;

    int sz = contents.size();
    fout.write((char*) &sz, sizeof(int));

    sz = compressed.size();
    fout.write((char*) &sz, sizeof(int));
    for (long long i = 0; i < compressed.size(); ++i)
    {
        char ch = compressed[i];
        fout.write(&ch, sizeof(char));
    }

//    compress(contents, t, fout);

    cout << "File Compressed" << endl;

    fout.close();

    return true;
}

bool decompressFile(const string& in, const string& out)
{
    ifstream fin(in, ios::binary);

    if (!fin.is_open())
        return false;

    int sz = 0;
    fin.read((char*) &sz, sizeof(int));

    vector<int> freq;
    for (int i = 0; i < sz; ++i)
    {
        int data = 0;
        fin.read((char*) &data, sizeof(int));
        freq.push_back(data);
    }

//    for (auto i : freq)
//        cout << i << " ";

    HuffmanTree t(freq);

    Node* p = t.getRoot();

    int contentSize = 0;
    fin.read((char*) &contentSize, sizeof(sz));


    sz = 0;
    fin.read((char*) &sz, sizeof(sz));

//    cout << sz << endl;

    ofstream fout(out, ios::binary);
    if (!fout.is_open())
        return false;

    for(int i = 0; i < sz; ++i)
    {
        char ch = 0;
        fin.read(&ch, sizeof(ch));
//        PR(ch);

        char op = 0;
        int bitsToRead = 7;
        while (bitsToRead >= 0 /*&& contentSize > 0*/)
        {
            if (p->left == nullptr && p->right == nullptr)
            {
                op = p->data;
//                cout << op << endl;
                fout.write(&op, sizeof(char));
                op = 0;
                p = t.getRoot();
                //--contentSize;
            }
            bool bit = ch & (1 << bitsToRead);
//            PR(bit);
            if (!bit)
                p = p->left;
            else
                p = p->right;

            --bitsToRead;
        }
    }

    fin.close();
    return true;
}

void displayMenu()
{
    cout << "Please select an option: \n1.Compress\n2.Decompress" << endl;
}

int main()
{
    displayMenu();

    char choice = '2';
    string file1 = "outString.txt" , file2 = "asf.txt";

    cin >> choice;

    switch(choice)
    {
    case '1':
        cout << "Enter file to be compressed: ";
        cin >> file1;
        cout << "Enter the name of the output file: ";
        cin >> file2;
        compressFile(file1, file2);
        break;
    case '2':
        cout << "Enter file to be decompressed: ";
        cin >> file1;
        cout << "Enter the name of the output file: ";
        cin >> file2;
        decompressFile(file1, file2);
        break;
    default:
        cout << "Invalid Input! Exiting.." << endl;
    }

//    compressFile("test.txt", "test.comp");
//    decompressFile("test.comp", "test1.txt");

    return 0;
}
