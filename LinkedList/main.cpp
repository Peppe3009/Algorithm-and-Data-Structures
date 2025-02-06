#include "LinkedList.h"

int main(int argc, char const *argv[])
{
    vector<string> numbers = {"foo", "bar"};
    LinkedList<string> linkedlist (numbers);
    linkedlist.show();
    linkedlist.remove("foo");
    linkedlist.show();
    return 0;
}
