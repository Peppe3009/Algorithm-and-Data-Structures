#include "../LinkedList/LinkedList.h"
#include <vector>
#include <fstream>


//**** HASH TABLE IMPLEMENTED WITH LINKEDLIST TO HANDLE COLLISIONS


template <class T>
class LinkedListHashTable
{
private:
    int dim;
    vector<LinkedList<T> *> hashTable;
    int hashFunction(T k);

public:
    LinkedListHashTable();
    LinkedListHashTable(int);
    void insert(T);
    void insert(vector<T>);
    void insertFromFile(string);
    void remove(T);
    void find(T);
    void showHashTable();
};