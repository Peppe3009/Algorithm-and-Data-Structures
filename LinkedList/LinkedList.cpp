#include "Node.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

template <class T>
class LinkedList
{
private:
    
    Node<T> *head;
    int length;
    static bool sortingFunction (T i,T j);
public:

    LinkedList();
    LinkedList(vector<T>);
    Node<T> *getHead();
    int size();
    bool isEmpty();
    void insertAtHead(T);
    void insertAtIndex(T, int);
    void insertAtEnd(T);
    void removeAtHead();
    void removeAtIndex(int);
    void removeAtEnd();
    pair<bool, Node<T> *> find(T value);
    vector<T> toVector();
    T *toArray();
    LinkedList<T> sort(string, bool);
    void show();
    void clear();
    void showFullInfo();

};