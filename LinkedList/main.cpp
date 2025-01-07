#include "LinkedList.h"

int main(int argc, char const *argv[])
{
    vector<int> numbers = {1, 5, 2, 4};
    LinkedList<int> lista(numbers);
    lista.sort("desc", true);
    lista.show();

    return 0;
}
