#include "../LinkedList/LinkedList.h"
#include <vector>
#include <fstream>


//**** HASH TABLE IMPLEMENTED WITH LINKEDLIST TO HANDLE COLLISIONS
//**** DUE TO THE NATURE OF THE HASH FUNCTION THE CLASS DOESN'T WORK WITH std::string
//**** WORKS FINE WITH ALL THE OTHER STANDARD TYPE THO

/**
 * TODO: IMPLEMENT A HASH FUNCTION FOR std::string
 */


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
    void insertVector(vector<T>);
    void insertFromFile(string);
    void remove(T);
    void find(T);
    void showHashTable();
};