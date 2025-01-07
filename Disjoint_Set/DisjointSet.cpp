#include <vector>
#include <iostream>
#include "Node.h"
using namespace std;

template<class T>
class DisjointSet
{
    private:
        vector<Node<T> *> set;
    public:
        DisjointSet();
        void makeSet(T value);
        Node<T> *findSet(T value);
        void unionSet(T val_x, T val_y);
};