template <class T>
class Node
{
private:
    T value;
    Node<T> *next;
    Node<T> *prev;

public:
    Node();
    Node(T v);
    void setValue(T);
    void setNext(Node<T> *);
    void setPrev(Node<T> *);
    T getValue();
    Node<T> *getPrev();
    Node<T> *getNext();
};