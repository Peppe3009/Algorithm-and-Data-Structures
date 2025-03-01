#include "Node.h"

/**
 * @brief Implement the tree used to encode and decode with Huffman algorithm.
 * 
 * The solution is build upon the idea that the element that needs to be encoded and decode is text and text alone.
 * This solution doesn't work if the data is, for example, an image since the file is not opened in binary mode and no considerations in this sense are made.  
*/


class HuffmanTree
{
private:
    Node *root;
    string filename;
    void preorderTraversal(Node *);
    void encodeCharacter(Node *, string , string &, string &);
public:
    HuffmanTree(string);
    void preorderTraversal();
    string encodeText(string);
    string decodeString(string);
    void encode();
    void decode();
};
