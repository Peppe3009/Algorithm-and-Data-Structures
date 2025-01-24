#include "RedBlackTree.cpp"
template <class T>
RedBlackTree<T>::RedBlackTree()
{
    this->root = nullptr;
}

template <class T>
void RedBlackTree<T>::leftRotate(Node<T> *x)
{
    Node<T> *y = x->getRight();
    x->setRight(y->getLeft());
    if (y->getLeft() != nullptr)
    {
        y->getLeft()->setParent(x);
    }
    y->setParent(x->getParent());
    if (x->getParent() == nullptr)
    {
        this->root = y;
    }
    else
    {
        if (x == x->getParent()->getLeft())
        {
            x->getParent()->setLeft(y);
        }
        else
        {
            x->getParent()->setRight(y);
        }
    }
    y->setLeft(x);
    x->setParent(y);
}

template <class T>
void RedBlackTree<T>::rightRotate(Node<T> *x)
{
    Node<T> *y = x->getLeft();
    x->setLeft(y->getRight());
    if (y->getRight() != nullptr)
    {
        y->getRight()->setParent(x);
    }
    y->setParent(x->getParent());
    if (x->getParent() == nullptr)
    {
        this->root = y;
    }
    else
    {
        if (x == x->getParent()->getRight())
        {
            x->getParent()->setRight(y);
        }
        else
        {
            x->getParent()->setLeft(y);
        }
    }
    y->setRight(x);
    x->setParent(y);
}

template <class T>
void RedBlackTree<T>::transplant(Node<T> *u, Node<T> *v)
{
    if (u->getParent() == nullptr)
    {
        this->root = v;
    }
    else if (u == u->getParent()->getLeft())
    {
        u->getParent()->setLeft(v);
    }
    else
    {
        u->getParent()->setRight(v);
    }
    if(v!=nullptr){
        v->setParent(u->getParent());
    }
    
}

template <class T>
Node<T> *RedBlackTree<T>::minimum(Node<T> *x)
{
    while (x->getLeft() != nullptr)
    {
        x = x->getLeft();
    }
    return x;
}

template <class T>
void RedBlackTree<T>::insert(T value)
{
    Node<T> *z = new Node<T>(value);
    Node<T> *x = this->root;
    Node<T> *y = nullptr;
    while (x != nullptr)
    {
        y = x;
        if (z->getValue() < x->getValue())
        {
            x = x->getLeft();
        }
        else
        {
            x = x->getRight();
        }
    }
    z->setParent(y);
    if (y == nullptr)
    {
        this->root = z;
    }
    else if (z->getValue() < y->getValue())
    {
        y->setLeft(z);
    }
    else
    {
        y->setRight(z);
    }
    this->insertFixup(z);
}

template <class T>
void RedBlackTree<T>::insert(vector<T> elementVector)
{
    for (T element : elementVector)
    {
        this->insert(element);
    }
}

template <class T>
void RedBlackTree<T>::insertFixup(Node<T> *z)
{
    Node<T> *y = nullptr;
    while (z != this->root && z->getParent()->getColor() == 'r')
    {
        if (z->getParent() == z->getParent()->getParent()->getLeft())
        {
            y = z->getParent()->getParent()->getRight();
            if (y != nullptr && y->getColor() == 'r')
            {
                z->getParent()->setColor('b');
                y->setColor('b');
                z->getParent()->getParent()->setColor('r');
                z = z->getParent()->getParent();
            }
            else
            {
                if (z == z->getParent()->getRight())
                {
                    z = z->getParent();
                    this->leftRotate(z);
                }
                z->getParent()->setColor('b');
                z->getParent()->getParent()->setColor('r');
                this->rightRotate(z->getParent()->getParent());
            }
        }
        else
        {
            y = z->getParent()->getParent()->getLeft();
            if (y != nullptr && y->getColor() == 'r')
            {
                z->getParent()->setColor('b');
                y->setColor('b');
                z->getParent()->getParent()->setColor('r');
                z = z->getParent()->getParent();
            }
            else
            {
                if (z == z->getParent()->getLeft())
                {
                    z = z->getParent();
                    this->rightRotate(z);
                }
                z->getParent()->setColor('b');
                z->getParent()->getParent()->setColor('r');
                this->leftRotate(z->getParent()->getParent());
            }
        }
    }

    this->root->setColor('b');
}

template <class T>
void RedBlackTree<T>::remove(T value)
{
    pair<bool, Node<T> *> foundPair = this->find(value);
    
    if (!foundPair.first)
    {
        cerr << "Element " << value << " not found in the tree." << endl;
        return;
    }
    this->removeNode(foundPair.second);
}
template <class T>
void RedBlackTree<T>::removeNode(Node<T> *z)
{
    Node<T> *y = z;
    Node<T> *x = nullptr;
    char yOriginalColor = y->getColor();
    if (z->getLeft() == nullptr)
    {
        x = z->getRight();
        this->transplant(z, z->getRight());
    }
    else if (z->getRight() == nullptr)
    {
        x = z->getLeft();
        this->transplant(z, z->getLeft());
    }
    else
    {
        y = this->minimum(z->getRight());
        yOriginalColor = y->getColor();
        x = y->getRight();
        if (y != z->getRight())
        {
            if (x != nullptr)
            {
                x->setParent(y->getParent());
            }
            this->transplant(y, y->getRight());
            y->setRight(z->getRight());
            if (y->getRight() != nullptr)
            {
                y->getRight()->setParent(y);
            }
        }
        else
        {
            if (x != nullptr)
            {
                x->setParent(y);
            }
        }
        this->transplant(z, y);
        y->setLeft(z->getLeft());
        if (y->getLeft() != nullptr)
        {
            y->getLeft()->setParent(y);
        }

        y->setColor(z->getColor());
    }
    if (yOriginalColor == 'b' && x != nullptr)
    {
        this->deleteFixup(x);
    }

}

template <class T>
void RedBlackTree<T>::deleteFixup(Node<T> *x)
{
    Node<T> *w = nullptr;
    while (x != this->root && x != nullptr && x->getColor() == 'b')
    {
        if (x == x->getParent()->getLeft())
        {
            w = x->getParent()->getRight();
            if (w->getColor() == 'r')
            {
                w->setColor('b');
                x->getParent()->setColor('r');
                this->leftRotate(x->getParent());
                w = x->getParent()->getRight();
            }
            if ((w->getLeft() == nullptr || w->getLeft()->getColor() == 'b') && (w->getRight() == nullptr || w->getRight()->getColor() == 'b'))
            {
                w->setColor('r');
                x = x->getParent();
            }
            else
            {
                if (w->getRight() == nullptr || w->getRight()->getColor() == 'b')
                {
                    if (w->getLeft() != nullptr)
                    {
                        w->getLeft()->setColor('b');
                    }
                    w->setColor('r');
                    this->rightRotate(w);
                    w = x->getParent()->getRight();
                }
                w->setColor(x->getParent()->getColor());
                x->getParent()->setColor('b');
                if (w->getRight() != nullptr)
                {
                    w->getRight()->setColor('b');
                }

                this->leftRotate(x->getParent());
                x = this->root;
            }
        }
        else
        {
            w = x->getParent()->getLeft();
            if (w->getColor() == 'r')
            {
                w->setColor('b');
                x->getParent()->setColor('r');
                this->rightRotate(x->getParent());
                w = x->getParent()->getLeft();
            }
            if ((w->getRight() == nullptr || w->getRight()->getColor() == 'b') && (w->getLeft() == nullptr || w->getLeft()->getColor() == 'b'))
            {
                w->setColor('r');
                x = x->getParent();
            }
            else
            {
                if (w->getLeft() == nullptr || w->getLeft()->getColor() == 'b')
                {
                    if (w->getRight() != nullptr)
                    {
                        w->getRight()->setColor('b');
                    }

                    w->setColor('r');
                    this->leftRotate(w);
                    w = x->getParent()->getLeft();
                }
                w->setColor(x->getParent()->getColor());
                x->getParent()->setColor('b');
                if (w->getLeft() != nullptr)
                {
                    w->getLeft()->setColor('b');
                }

                this->rightRotate(x->getParent());
                x = this->root;
            }
        }
    }
    if(x!=nullptr){
        x->setColor('b');
    }
    
}

template <class T>
Node<T> *RedBlackTree<T>::getRoot()
{
    return this->root;
}

template <class T>
void RedBlackTree<T>::printHelper(Node<T> *root, string indent, bool last)
{
    if (root != nullptr)
    {
        cout << indent;
        if (last)
        {
            cout << "R----";
            indent += "   ";
        }
        else
        {
            cout << "L----";
            indent += "|  ";
        }

        cout << root->getValue() << "(" << root->getColor() << ")" << endl;
        printHelper(root->getLeft(), indent, false);
        printHelper(root->getRight(), indent, true);
    }
}

template <class T>
void RedBlackTree<T>::show()
{
    this->printHelper(this->root, "", false);
}

template <class T>
void RedBlackTree<T>::visit(Node<T> *root, T value, bool &found, Node<T> &foundNode)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->getValue() == value)
    {
        found = true;
        foundNode = *root;
        return;
    }
    visit(root->getLeft(), value, found, foundNode);
    visit(root->getRight(), value, found, foundNode);
}

template <class T>
pair<bool, Node<T> *> RedBlackTree<T>::find(T value)
{
    bool found = false;
    Node<T> *foundNode = new Node<T>();
    visit(this->root, value, found, *foundNode);
    return make_pair(found, foundNode);
}