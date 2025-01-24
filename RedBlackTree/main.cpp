#include "RedBlackTree.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    RedBlackTree<int> alberoRB;
    vector<int> vettore(10);
    generate(vettore.begin(), vettore.end(), rand);
    alberoRB.insert(vettore);
    alberoRB.insert(71);
    alberoRB.show();
    alberoRB.remove(55);
    alberoRB.show();
}