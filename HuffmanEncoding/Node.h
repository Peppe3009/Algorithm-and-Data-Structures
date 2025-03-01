#include "Node.cpp"
Node::Node()
{
    this->left = nullptr;
    this->right = nullptr;
}

Node::Node(string s, int f)
{
    this->left = nullptr;
    this->right = nullptr;
    this->string_freq.first = s;
    this->string_freq.second = f;
    
}

void Node ::set_left(Node *l)
{
    this->left = l;
}

void Node ::set_right(Node *r)
{
    this->right = r;
}

void Node ::set_string_freq(pair<string, int> sf)
{
    this->string_freq = sf;
}
Node *Node::get_right()
{
    return this->right;
}
Node *Node::get_left()
{
    return this->left;
}
pair<string, int> Node::get_string_freq()
{
    return this->string_freq;
}
