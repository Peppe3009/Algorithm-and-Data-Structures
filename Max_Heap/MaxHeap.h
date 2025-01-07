#include <vector>
#include <iostream>
#include <string>
using namespace std;

template <class T>
class MaxHeap
{
private:
    int heapSize;
    vector<T> heapVector;
    int parent(int);
    int right(int);
    int left(int);
    void maxHeapify(int);
    void swap(int, int);

public:
    MaxHeap();
    MaxHeap(vector<T>);
    MaxHeap(string);
    void buildMaxHeap();
    void heapInsert(T);
    void showHeap();
    void save();
    void save(string);
};