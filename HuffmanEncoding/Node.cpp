#include <string>
using namespace std;
class Node
{
private:
    Node *left;
    Node *right;
    pair<string, int>string_freq;
public:
    Node();
    Node(string, int);
    void set_left(Node *);
    void set_right(Node *);
    void set_string_freq(pair<string, int>);
    Node *get_left();
    Node *get_right();
    pair<string, int> get_string_freq();
};
