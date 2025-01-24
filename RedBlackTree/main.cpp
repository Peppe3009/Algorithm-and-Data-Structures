#include "RedBlackTree.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    RedBlackTree<int> alberoRB;
    vector<int> vector(10);
    generate(vector.begin(), vector.end(), rand);
    alberoRB.insert(vector);
    alberoRB.insert(71);
    alberoRB.show();
    alberoRB.remove(55);
    alberoRB.show();
}