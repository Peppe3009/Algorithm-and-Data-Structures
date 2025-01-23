#include "Node.cpp"

template <class T>
Node<T>::Node()
{
    this->value = -1;
    this->next = nullptr;
    this->prev = nullptr;
}
template <class T>
Node<T>::Node(T v)
{
    this->value = v;
    this->next = nullptr;
    this->prev = nullptr;
}

template <class T>
void Node<T>::setValue(T v)
{
    this->value = v;
}

template <class T>
void Node<T>::setNext(Node *n)
{
    this->next = n;
}
template <class T>
void Node<T>::setPrev(Node<T> *n)
{
    this->prev = n;
}
template <class T>
T Node<T>::getValue()
{
    return this->value;
}

template <class T>
Node<T> *Node<T>::getNext()
{
    return this->next;
}
template <class T>
Node<T> *Node<T>::getPrev()
{
    return this->prev;
}

template <class T>
bool Node<T>::isNull()
{
    return this->prev == nullptr && this->next == nullptr;
}
