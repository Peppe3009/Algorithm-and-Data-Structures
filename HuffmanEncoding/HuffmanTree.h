#include "HuffmanTree.cpp"
#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <map>

HuffmanTree::HuffmanTree(string filename)
{
    this->filename = filename;
    struct LessThanByFreq
    {
        bool operator()(Node *lnode, Node *rnode) const { return lnode->get_string_freq().second > rnode->get_string_freq().second; }
    };

    ifstream inputFile(this->filename);
    
    vector<Node *> nodes;
    map<char, int> string_freq_map;
    char c;
    if (!inputFile)
    {
        cout << "File " << filename << " not found." << endl;
        return;
    }

    while ((c = inputFile.get()) && inputFile.good())
    {
        string_freq_map[c]++;
        inputFile.peek();
    }

    inputFile.close();


    for (auto element : string_freq_map)
    {
        string character_str(1, element.first);
        nodes.push_back(new Node(character_str, element.second));
    }

    //** HUFFMAN TREE INITIALIZATION

    // ****** Insert each node in min_priority queue
    priority_queue<Node *, vector<Node *>, LessThanByFreq> min_queue(nodes.begin(), nodes.end());

    //** HUFFMAN ALGORITHM
    for (int i = 1; i < nodes.size(); i++)
    {
        Node *x = min_queue.top(); 
        min_queue.pop();
        Node *y = min_queue.top();
        min_queue.pop();
        Node *z = new Node();

        z->set_left(x);
        z->set_right(y);

        pair<string, int> new_pair(x->get_string_freq().first + y->get_string_freq().first, x->get_string_freq().second + y->get_string_freq().second);
        z->set_string_freq(new_pair);
        min_queue.push(z);
    }
    this->root = min_queue.top();
    min_queue.pop();
}

/**
 * @brief Encoding using huffman algorithm. 
 * 
 * @return Generate a text file containing the encoded text
 * 
*/
void HuffmanTree::encode()
{
    ifstream inputFile(this->filename);
    ofstream outputFile("encoded_" + this->filename);
    char c;
    while (( c = inputFile.get() ) && inputFile.good())
    {
        string character_string(1, c);
        string tmp_string = "", encodedCharacter = "";
        encodeCharacter(this->root, character_string, tmp_string, encodedCharacter);
        outputFile << encodedCharacter;
    }
}

void HuffmanTree::decode()
{
    ifstream inputFile("encoded_" + this->filename);
    ofstream outputFile("decoded_"+this->filename);
    Node *current = this->root;
    char symbol;
    while (!inputFile.eof())
    {
        inputFile >> symbol;
        if(symbol == '0')
         {
            current = current->get_left();
        }
        else
        {
            current = current->get_right();
        }
        if (current->get_left() == nullptr && current->get_right() == nullptr)
        {
            outputFile << current->get_string_freq().first;
            current = this->root;
        }

    }
}

void HuffmanTree::encodeCharacter(Node *root, string c, string &tmp_string, string &encodedCharacter)
{
    if (root != nullptr)
    {
        if (root->get_string_freq().first == c)
        {
            encodedCharacter = tmp_string;
        }
        else
        {
            tmp_string.push_back('0');
            encodeCharacter(root->get_left(), c, tmp_string, encodedCharacter);
            tmp_string.pop_back();
            tmp_string.push_back('1');
            encodeCharacter(root->get_right(), c, tmp_string, encodedCharacter);
            tmp_string.pop_back();
        }
    }
    return;
}

/**
 * @brief Encode some text based the huffman tree build upon the file content.
 * @param text Some text to encode.
*/
string HuffmanTree::encodeText(string text)
{
    string encodedText;
    for (char character : text)
    {
        string encodedCharacter = "";
        string tmp_string = "";

        // ****** Convert char to string for convenience
        string character_str(1, character);
        encodeCharacter(this->root, character_str, tmp_string, encodedCharacter);
        encodedText += encodedCharacter;
    }
    return encodedText;
}
/**
 * @brief Decode a string based on the huffman tree build upon the file content.
 * @param decodingString The [0,1] string that needs to be decoded.
*/
string HuffmanTree ::decodeString(string decodindString)
{
    Node *current = this->root;
    string decodedString;

    for (char symbol : decodindString)
    {
        if (symbol == '0')
        {
            current = current->get_left();
        }
        else
        {
            current = current->get_right();
        }
        if (current->get_left() == nullptr && current->get_right() == nullptr)
        {
            decodedString += current->get_string_freq().first;
            current = this->root;
        }
    }
    return decodedString;
}

void HuffmanTree ::preorderTraversal()
{
    preorderTraversal(this->root);
}

void HuffmanTree ::preorderTraversal(Node *root)
{
    if (root != nullptr)
    {
        cout << "{" << root->get_string_freq().first << ", " << root->get_string_freq().second << "}" << endl;
        preorderTraversal(root->get_left());
        preorderTraversal(root->get_right());
    }
    return;
}
