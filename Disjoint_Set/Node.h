#include "Node.cpp"
template <class T>
Node<T>::Node()
{
    this->value = T();
    this->rank = 0;
    this->parent = nullptr;
}

template <class T>
Node<T>::Node(int value)
{
    this->value = value;
    this->rank = 0;
    this->parent = nullptr;
}

template <class T>
T Node<T>::getValue()
{
    return this->value;
}

template <class T>
int Node<T>::getRank()
{
    return this->rank;
}

template <class T>
Node<T> *Node<T>::getParent()
{
    return this->parent;
}

template <class T>
void Node<T>::setValue(int v)
{
    this->value = v;
}

template <class T>
void Node<T>::setRank(int r)
{
    this->rank = r;
}

template <class T>
void Node<T>::setParent(Node *p)
{
    this->parent = p;
}