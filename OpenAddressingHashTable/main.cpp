#include "OpenAddressingHashTable.h"
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main()
{
    
    vector<string> strings = {"foo", "bar"};

    OpenAddressingHashTable<string> HashTable;
    for (string s: strings){
        HashTable.insert(s);
    }
    HashTable.show();
    HashTable.find("foo");



}