#include "LinkedListHashTable.h"
#include <algorithm>
int main()
{
    LinkedListHashTable<int> hashtable;
    vector<int> randomNumbers(10);
    generate(randomNumbers.begin(), randomNumbers.end(), rand);
    hashtable.insertVector(randomNumbers);
    hashtable.insert(99);
    hashtable.showHashTable();
    hashtable.remove(99);
    hashtable.showHashTable();
    
}
