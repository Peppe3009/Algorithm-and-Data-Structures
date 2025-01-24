#include "Node.cpp"
template <class T>
Node<T>::Node()
{
    this->value = -1;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
    this->color = 'r';
}
template <class T>
Node<T>::Node(T value)
{
    this->value = value;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
    this->color = 'r';
}
template <class T>
T Node<T>::getValue()
{
    return this->value;
}
template <class T>
Node<T> *Node<T>::getLeft()
{
    return this->left;
}
template <class T>
Node<T> *Node<T>::getRight()
{
    return this->right;
}
template <class T>
Node<T> *Node<T>::getParent()
{
    return this->parent;
}
template <class T>
char Node<T>::getColor()
{
    return this->color;
}
template <class T>
void Node<T>::setValue(T value)
{
    this->value = value;
}
template <class T>
void Node<T>::setLeft(Node<T> *left)
{
    this->left = left;
}
template <class T>
void Node<T>::setRight(Node<T> *right)
{
    this->right = right;
}
template <class T>
void Node<T>::setParent(Node<T> *parent)
{
    this->parent = parent;
}
template <class T>
void Node<T>::setColor(char color)
{
    this->color = color;
}
template <class T>
bool Node<T>::isRoot()
{
    return this->parent == nullptr;
}
template <class T>
bool Node<T>::isLeaf()
{
    return this->left == nullptr && this->right == nullptr;
}