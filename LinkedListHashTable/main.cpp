#include "LinkedListHashTable.h"
#include <algorithm>
int main()
{
    LinkedListHashTable<string> hashtable;
    vector<string> strings = {"ciccio", "cane", "pippo"};
    hashtable.insert(strings);
    hashtable.showHashTable();
    
}
