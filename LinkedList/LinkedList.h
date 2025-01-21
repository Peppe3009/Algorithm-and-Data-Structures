#include "LinkedList.cpp"

template <class T>
LinkedList<T> ::LinkedList()
{
    this->head = nullptr;
    this->length = 0;
}

template <class T>
LinkedList<T> ::LinkedList(vector<T> v)
{
    this->head = nullptr;
    this->length = 0;
    for (int i = 0; i < v.size(); i++)
    {
        this->insertAtEnd(v.at(i));
    }
}

template <class T>
Node<T> *LinkedList<T> ::getHead()
{
    if (this->isEmpty())
    {
        cerr << "ERROR: List is Empty.";
        return nullptr;
    }
    return this->head;
}

/**
 * @brief Insert a value at head.
 * @param value The value that has to be inserted.
*/
template <class T>
void LinkedList<T> ::insertAtHead(T value)
{
    Node<T> *newNode = new Node(value);
    if (this->head == nullptr)
    {

        this->head = newNode;
        this->length++;
        return;
    }
    this->head->setPrev(newNode);
    newNode->setNext(this->head);
    this->head = newNode;
    this->length++;
    
}

/**
 * @brief Insert a value at the end.
 * @param value The value that has to be inserted.
*/
template <class T>
void LinkedList<T> ::insertAtEnd(T value)
{
    Node<T> *newNode = new Node(value);
    if (this->head == nullptr)
    {
        this->head = newNode;
        this->length++;
        return;
    }

    Node<T> *sentinel = this->head;
    while (sentinel->getNext() != nullptr)
    {
        sentinel = sentinel->getNext();
    }
    sentinel->setNext(newNode);
    newNode->setPrev(sentinel);
    this->length++;
}

/**
 * @brief Insert a value at given index.
 * @param value The value that has to be inserted.
 * @param index The index in the list starting from 0
*/
template <class T>
void LinkedList<T> ::insertAtIndex(T value, int index)
{
    if (index > this->length)
    {
        cout << "ERROR: Index not in the list. " << endl;
        return;
    }

    if (index == 0)
    {
        this->insertAtHead(value);
    }
    else if (index == this->length)
    {
        this->insertAtEnd(value);
    }
    else
    {
        Node<T> *sentinel = this->head;
        Node<T> *newNode = new Node(value);

        for (int i = 0; i < index; i++)
        {
            sentinel = sentinel->getNext();
        }

        newNode->setPrev(sentinel);
        newNode->setNext(sentinel);
        sentinel->getPrev()->setNext(newNode);
        this->length++;
    }
}

/**
 * @brief Remove a specific element from the list.
 * 
*/

template <class T>
void LinkedList<T> :: remove(T element)
{
    if (this->isEmpty())
    {
        cerr << "ERROR: List is empty." << endl;
        return;
    }

    if (this->head->getValue() == element){
        this->removeAtHead();
        return;
    }
    
    Node <T>*sentinel = this->head;
    Node <T>*deletedNode = new Node<T>();
    while(sentinel->getNext() != nullptr) {
        if (sentinel->getValue() == element) {
            deletedNode = sentinel;
        }
        sentinel= sentinel->getNext();
    }

    if (deletedNode->isNull()){
        cerr << "ERROR: Element not in list." << endl;
        return;
    }


    Node <T>*precNode = deletedNode->getPrev();
    Node <T>*nextNode = deletedNode->getNext();
    precNode->setNext(nextNode);
    nextNode->setPrev(precNode);
    delete(deletedNode);
}


/**
 * @brief Remove the element at head.
 * 
*/
template <class T>
void LinkedList<T> ::removeAtHead()
{
    if (this->isEmpty())
    {
        cerr << "ERROR: List is empty." << endl;
        return;
    }
    Node<T> *removedNode = this->head;
    this->head = this->head->getNext();
    this->length--;

    delete (removedNode);
}

/**
 * @brief Remove an element at given index.
 * @param index The index in the list starting from 0.
 * 
*/
template <class T>
void LinkedList<T> ::removeAtIndex(int index)
{
    if (this->isEmpty())
    {
        cerr << "ERROR: List is Empty";
        return;
    }

    if (index > this->length)
    {
        cout << "ERROR: Index not in the list. " << endl;
        return;
    }

    if (index == 0)
    {
        this->removeAtHead();
        return;
    }

    if (index == this->length)
    {
        this->removeAtEnd();
        return;
    }

    Node<T> *sentinel = this->head;
    for (int i = 0; i < index; i++)
    {
        sentinel = sentinel->getNext();
    }
    Node<T> *prev = sentinel->getPrev();

    prev->setNext(sentinel->getNext());

    delete (sentinel);
    this->length--;
}

/**
 * @brief Remove the element at end.
 * 
*/
template <class T>
void LinkedList<T> ::removeAtEnd()
{
    if (this->isEmpty())
    {
        cerr << "ERROR: List is empty." << endl;
        return;
    }

    if (this->length == 1)
    {
        this->length--;
        delete (this->head);
        return;
    }

    Node<T> *sentinel = this->head;
    Node<T> *prec = sentinel->getPrev();
    while (sentinel->getNext() != nullptr)
    {
        prec = sentinel;
        sentinel = sentinel->getNext();
    }
    prec->setNext(nullptr);
    this->length--;

    delete (sentinel);
}

/**
 * @brief Clear the list.
 * 
*/
template <class T>
void LinkedList<T> ::clear()
{
    if (this->isEmpty())
    {
        cerr << "ERROR: List already empty." << endl;
        return;
    }

    while (this->head != nullptr)
    {
        Node<T> *deletedNode = this->head;
        this->head = this->head->getNext();
        delete (deletedNode);
        this->length--;
    }
}

/**
 * @brief Shows the list.
 * 
*/
template <class T>
void LinkedList<T> ::show()
{
    Node<T> *sentinel = this->head;
    while (sentinel != nullptr)
    {
        cout << sentinel->getValue() << " -> ";
        sentinel = sentinel->getNext();
    }
    cout << endl;
}

/**
 * @brief Shows the list and its length.
 *
*/
template <class T>
void LinkedList<T> ::showFullInfo()
{
    if (this->isEmpty())
    {
        cerr << "ERROR: List is empty. Nothing to show." << endl;
        return;
    }

    cout << "List Length: " << this->length << endl;
    this->show();
}

template <class T>
int LinkedList<T> ::size()
{
    return this->length;
}

/**
 * @brief Convert the list in a Vector.
 * 
 * @return The converted list.
 * 
*/
template <class T>
vector<T> LinkedList<T> ::toVector()
{
    vector<T> valuesVector;
    Node<T> *sentinel = this->head;

    while (sentinel != nullptr)
    {
        valuesVector.push_back(sentinel->getValue());
        sentinel = sentinel->getNext();
    }
    return valuesVector;
}

/**
 * @brief Convert the list in Array.
 * 
 * @return The converted list.
 * 
*/
template <class T>
T *LinkedList<T> ::toArray()
{
    T *valuesArray = (int *)malloc(this->length * sizeof(T));

    Node<T> *sentinel = this->head;

    for (int i = 0; i < this->length; i++)
    {
        valuesArray[i] = sentinel->getValue();
        sentinel = sentinel->getNext();
    }

    return valuesArray;
}

template <class T>
bool LinkedList<T> ::isEmpty()
{
    return this->length <= 0 || this->head == nullptr;
}

/**
 * @brief Sort the list in ascending / descending order based on type.
 * 
 * @param type Type of sorting. Types are ["asc", "desc"]
 * @param inPlace Specify if the sorting has to be made in place or not.
 * @return An empty list if in place else an ordered list.
 * 
*/
template <class T>
LinkedList<T> LinkedList<T> ::sort(string type, bool inPlace)
{
    vector<T> vectorList = this->toVector();
    if (type.compare("asc"))
    {
        std::sort(vectorList.begin(), vectorList.end(), this->sortingFunction);
    }
    else{
        std::sort(vectorList.begin(), vectorList.end());
    }
    

    LinkedList<T> newList(vectorList);

    if (inPlace)
    {
        this->head = newList.getHead();
        LinkedList<T> emptyList;
        return emptyList;
    }
    else
    {
        return newList;
    }
}

/**
 * @brief Check if an element is in list or not.
 * 
 * @param value 
 * @return A pair<bool, Node>. The bool represents if the value is in the list, if True the node is also returned.
 * 
*/
template <class T>
pair<bool, Node<T> *> LinkedList<T> ::find(T value)
{
    pair<bool, Node<T> *> foundPair(false, new Node<T>());
    Node<T> *sentinel = this->head;

    while (sentinel != nullptr)
    {
        if (sentinel->getValue() == value)
        {
            foundPair.first = true;
            foundPair.second = sentinel;
        }
        sentinel = sentinel->getNext();
    }
    return foundPair;
}

template <class T>
bool LinkedList<T> :: sortingFunction (T i,T j)
{
    return i > j;
}