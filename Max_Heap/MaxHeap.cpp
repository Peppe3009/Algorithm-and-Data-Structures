#include "MaxHeap.h"
#include <fstream>
#include <cmath>


template <class T>
MaxHeap<T>::MaxHeap()
{
    this->heapSize = 0;
    this->heapVector.resize(0);
}

template <class T>
MaxHeap<T>::MaxHeap(vector<T> externalVector)
{
    this->heapVector = externalVector;
}

template <class T>
MaxHeap<T>::MaxHeap(string filename)
{
    ifstream inputFile(filename);
    int numero;
    if (!inputFile)
    {
        cerr << "Error. File " << filename << " not found.";
    }
    while (!inputFile.eof())
    {
        inputFile >> numero;
        this->heapVector.push_back(numero);
    }
}

template <class T>
int MaxHeap<T>::parent(int i)
{
    return floor((i - 1) / 2);
}

template <class T>
int MaxHeap<T>::right(int i)
{
    return 2 * i + 2;
}

template <class T>
int MaxHeap<T>::left(int i)
{
    return 2 * i + 1;
}

template <class T>
void MaxHeap<T>::swap(int i, int j)
{
    int temp = this->heapVector.at(i);
    this->heapVector.at(i) = this->heapVector.at(j);
    this->heapVector.at(j) = temp;
}

template <class T>
void MaxHeap<T>::maxHeapify(int i)
{
    int l = this->left(i);
    int r = this->right(i);
    int max = 0;
    if (l < this->heapSize &&this->heapVector.at(l) > this->heapVector.at(i))
    {
        max = l;
    }
    else
    {
        max = i;
    }
    if (r < this->heapSize &&this->heapVector.at(r) > this->heapVector.at(max))
    {
        max = r;
    }
    if (max != i)
    {
        this->swap(i, max);
        this->maxHeapify(max);
    }
}

template <class T>
void MaxHeap<T>::buildMaxHeap()
{
    this->heapSize = this->heapVector.size();
    for (int i = ((this->heapVector.size() - 1) / 2); i >= 0; i--)
    {
        this->maxHeapify(i);
    }
}

template <class T>
void MaxHeap<T>::heapInsert(T key)
{
    this->heapSize++;
    this->heapVector.resize(this->heapVector.size() + 1);
    int i = this->heapSize - 1;

    while (i > 0 && this->heapVector.at(parent(i)) < key)
    {
        this->heapVector.at(i) = this->heapVector.at(parent(i));
        i = parent(i);
    }
    this->heapVector.at(i) = key;
}

template <class T>
void MaxHeap<T>::showHeap()
{
    cout << "Heap: ";
    for (int i = 0; i < this->heapVector.size(); i++)
    {
        cout << this->heapVector.at(i) << " ";
    }
    cout << endl;
}

template <class T>
void MaxHeap<T>::save()
{
    string filename = "OUT.txt";
    ofstream outputFile(filename);
    outputFile << "Heap: ";
    for (int i = 0; i < this->heapVector.size(); i++)
    {
        outputFile << this->heapVector.at(i) << " ";
    }
    outputFile.close();
}

template <class T>
void MaxHeap<T>::save(string filename)
{
    ofstream outputFile(filename);
    outputFile << "Heap: ";
    for (int i = 0; i < this->heapVector.size(); i++)
    {
        outputFile << this->heapVector.at(i) << " ";
    }

    outputFile.close();
}
