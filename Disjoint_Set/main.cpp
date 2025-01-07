#include "DisjointSet.h"


int main()
{
    DisjointSet<int> set;
    for (int i = 1; i < 5; i++)
    {
        set.makeSet(i);
    }


    set.unionSet(1, 2);
    set.unionSet(2, 2);
    set.unionSet(3, 3);

    
    
    
    
}