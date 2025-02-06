#include <vector>
#include <string>
#include <iostream>
#include <limits>
#include <type_traits>

using namespace std;
#define INF numeric_limits<int>::max()

template <class T>
class OpenAddressingHashTable
{
private:
    vector<pair<int, T>> hashtable;
    int size;
    int doubleHashingFunction(int, int);
    pair<int, T> createKeyValuePair(T);
public:
    OpenAddressingHashTable();
    OpenAddressingHashTable(int);
    OpenAddressingHashTable(vector<T>);
    void insert(T);
    bool find(T);
    void remove(T);
    void remove(vector<T>);
    void show();
    int getSize();
};
