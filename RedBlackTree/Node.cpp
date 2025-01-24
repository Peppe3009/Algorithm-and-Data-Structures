using namespace std;

template <class T>
class Node
{
private:
    T value;
    char color;
    Node<T> *left;
    Node<T> *right;
    Node<T> *parent;

public:
    Node<T>();
    Node<T>(T value);
    T getValue();
    Node<T> *getLeft();
    Node<T> *getRight();
    Node<T> *getParent();
    char getColor();
    void setValue(T);
    void setLeft(Node<T> *);
    void setRight(Node<T> *);
    void setParent(Node<T> *);
    void setColor(char);
    bool isLeaf();
    bool isRoot();
};