#include "Node.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

template <class T>
class RedBlackTree
{
private:
    Node<T> *root;
    Node<T> *nillNode;
    Node<T> *minimum(Node<T> *);
    void leftRotate(Node<T> *);
    void rightRotate(Node<T> *);
    void insertFixup(Node<T> *);
    void transplant(Node<T> *, Node<T> *);
    void visit(Node<T> *root, T value, bool &found, Node<T> &foundNode);
    void printHelper(Node<T> *, string, bool);
    void removeNode(Node<T> *);
    void deleteFixup(Node<T> *);

public:
    RedBlackTree();
    void insert(T);
    void insert(vector<T>);
    void remove(T);
    pair<bool, Node<T> *> find(T);
    Node<T> *getRoot();
    void show();
};
