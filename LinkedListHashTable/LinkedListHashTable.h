#include "LinkedListHashTable.cpp"
#include <cmath>

template <class T>
LinkedListHashTable<T> ::LinkedListHashTable()
{
    this->dim = 10;
    for (int i= 0; i < this->dim; i++){
        LinkedList<T> *l = new LinkedList<T>();
        this->hashTable.push_back(l);    
    }
}
template <class T>
LinkedListHashTable<T> ::LinkedListHashTable(int d)
{
    this->dim = d;
    for (int i= 0; i < this->dim; i++){
        LinkedList<T> *l = new LinkedList<T>();
        this->hashTable.push_back(l);    
    }
}
template <class T>
int LinkedListHashTable<T> ::hashFunction(T k)
{
    double A = 0.618033;
    return floor(this->dim * (fmod(k * A, 1)));
}

template <>
int LinkedListHashTable<string> ::hashFunction(string k)
{
    double A = 0.618033;
    return floor(this->dim * (fmod(k.size() * A, 1)));
}

template<class T>
void LinkedListHashTable<T> ::insert(T value)
{
    int key = this->hashFunction(value);
    
    hashTable.at(key)->insertAtHead(value);
}

template<class T>
void LinkedListHashTable<T> ::insert(vector<T> vector)
{
    for (T element: vector)
    {
        int key = this->hashFunction(element);
        hashTable.at(key)->insertAtHead(element);
    }
}

template<class T>
void LinkedListHashTable<T> ::find(T value)
{
    
    int key = this->hashFunction(value);
    pair<bool, Node<T> *> foundNode = hashTable.at(key)->find(value);
    if (foundNode.first){
        cout << "Element " << value << " found in position " << key << endl;
    }else{
        cout << "Element " << value << " not found" << endl;
    }

}


template<class T>
void LinkedListHashTable<T> ::insertFromFile(string filename)
{
    ifstream inputFile(filename);
    T n;
    if (!inputFile)
    {
        cerr << "File " << filename << " not found." << endl;
        return;
    }

    while (!inputFile.eof())
    {
        inputFile >> n;
        this->insert(n);
    }
}


template <class T>
void LinkedListHashTable<T> ::remove(T element)
{
    int key = this->hashFunction(element);
    hashTable.at(key)->remove(element);
}




template <class T>
void LinkedListHashTable<T> ::showHashTable()
{
    
    for (int i = 0; i < this->hashTable.size(); i++){
        cout << i << ": ";
        this->hashTable.at(i)->show();
    }
}
