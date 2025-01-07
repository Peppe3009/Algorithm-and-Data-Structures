#include "DisjointSet.cpp"

template <class T>
DisjointSet<T>::DisjointSet()
{
    this->set.resize(0);
}

/**
 * It creates a set based on the value given as parameter
 *
 * @param value Node value
 *
 *
 */
template <class T>
void DisjointSet<T>::makeSet(T value)
{
    Node<T> *x = new Node<T>(value);
    x->setParent(x);
    this->set.push_back(x);
}
template <class T>
Node<T> *DisjointSet<T>::findSet(T value)
{
    Node<T> *x = new Node<T>();

    for (auto &node : this->set)
    {
        if (node->getValue() == value)
        {
            x = node;
        }
    }

    if (x->getValue() == T())
    {
        cout << "Node with value " << value << " is not in the set." << endl;
        return x;
    }

    if (x != x->getParent())
    {
        x->setParent(findSet(x->getParent()->getValue()));
    }
    return x->getParent();
}

/**
 *  Add the node with value src to the set defined from node with dst value
 * @param src The value of the source node
 * @param dst The value of the destination node
 */
template <class T>
void DisjointSet<T>::unionSet(T src, T dst)
{
    Node<T> *x = this->findSet(src);
    Node<T> *y = this->findSet(dst);

    if (x->getRank() > y->getRank())
    {
        y->setParent(x);
    }
    else
    {
        x->setParent(y);
        if (x->getRank() == y->getRank())
        {
            y->setRank(y->getRank() + 1);
        }
    }
}