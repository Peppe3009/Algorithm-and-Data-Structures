#include "OpenAddressingHashTable.cpp"

template <class T>
OpenAddressingHashTable<T>::OpenAddressingHashTable()
{
    this->size = 30;
    vector<pair<int, T>> tempV(this->size, make_pair(INF, T{}));
    this->hashtable = tempV;
    
}

template <class T>
OpenAddressingHashTable<T>::OpenAddressingHashTable(int m)
{
    this->size = m;
    vector<pair<int, T>> tempV(this->size, make_pair(INF, T{}));
    this->hashtable = tempV;
}

template <class T>
OpenAddressingHashTable<T>::OpenAddressingHashTable(vector<T> elements)
{
    this->size = 30;
    vector<pair<int, T>> tempV(this->size, make_pair(INF, T{}));
    this->hashtable = tempV;

    for (T element : elements)
    {
        this->insert(element);
    }
}

template <class T>
int OpenAddressingHashTable<T>::getSize()
{
    return this->size;
}

template <class T>
pair<int, T> OpenAddressingHashTable<T>::createKeyValuePair(T element)
{
    return make_pair(element, element);
}

template <>
pair<int, string> OpenAddressingHashTable<string>::createKeyValuePair(string element)
{

    return make_pair(element.size(), element);
}

template <class T>
int OpenAddressingHashTable<T>::doubleHashingFunction(int k, int i)
{
    int h_1 = k % this->size;
    int h_2 = 1 + (k % (this->size - 1));
    return (h_1 + i * h_2) % this->size;
}

template <class T>
void OpenAddressingHashTable<T>::insert(T element)
{
    pair<int, T> KeyValuePair = this->createKeyValuePair(element);
    int i = 0;
    while (i < this->size)
    {
        int q = this->doubleHashingFunction(KeyValuePair.first, i);
        if (this->hashtable.at(q).first == INF)
        {
            this->hashtable.at(q) = KeyValuePair;
            return;
        }
        else
        {
            i++;
        }
    }
    cerr << "Hash Table overflow" << endl;
    return;
}

template <class T>
bool OpenAddressingHashTable<T>::find(T element)
{
    pair<int, T> KeyValuePair = this->createKeyValuePair(element);
    int i = 0;
    int q = this->doubleHashingFunction(KeyValuePair.first, i);
    while (this->hashtable.at(q).first != INF || i != this->size)
    {
        q = this->doubleHashingFunction(KeyValuePair.first, i);
        if (this->hashtable.at(q) == KeyValuePair)
        {
            cout << "Element found at index: " << q << endl;
            return true;
        }
        else
        {
            i++;
        }
    }
    cout << "Element not found" << endl;
    return false;
}

template <class T>
void OpenAddressingHashTable<T>::remove(T element)
{
    if (this->find(element))
    {
        pair<int, T> KeyValuePair = this->createKeyValuePair(element);
        int i = 0;
        int q = this->doubleHashingFunction(KeyValuePair.first, i);
        while (this->hashtable.at(q).first != INF || i != this->size)
        {
            q = this->doubleHashingFunction(KeyValuePair.first, i);
            if (this->hashtable.at(q) == KeyValuePair)
            {
                pair<int, T> deletedPair (INF, T{});
                this->hashtable.at(q) = deletedPair;
                cout << "Element deleted at index: " << q << endl;
                return;
                
            }
            else
            {
                i++;
            }
        }
        return;
    }
    return;
}

template <class T>
void OpenAddressingHashTable<T>::remove(vector<T> elements)
{
    for (T element: elements)
    {
        this->remove(element);
    }
}


template <class T>
void OpenAddressingHashTable<T>::show()
{
    for (int i = 0; i < this->hashtable.size(); i++)
    {
        cout << i << ": " << this->hashtable.at(i).second << endl;
    }
}