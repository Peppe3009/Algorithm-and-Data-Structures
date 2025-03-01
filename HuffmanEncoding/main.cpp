#include "HuffmanTree.h"
int main(int argc, char const *argv[])
{   

    string filename = "Lorem.txt";
    HuffmanTree huffman(filename);
    huffman.preorderTraversal();
    huffman.encode();
}