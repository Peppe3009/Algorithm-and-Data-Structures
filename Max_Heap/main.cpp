#include "MaxHeap.cpp"

int main()
{
    vector<int> prova = {4, 1, 3, 2, 16, 9, 10, 8, 7};
    string file = "file.txt";
    // MaxHeap maxheap(file);
    MaxHeap<int> maxheap(prova);
    
    maxheap.buildMaxHeap();
    maxheap.showHeap();
    // maxheap.heapInsert(22);
    //maxheap.showHeap();
    
    /*
        string outputfile="fileOutput.txt";
        maxheap.save();
        maxheap.save(outputfile);
    */
}