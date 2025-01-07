template <class T>
class Node
{
    private:
        T value;
        int rank;
        Node *parent;
    public:
        Node();
        Node(int);
        T getValue();
        int getRank();
        Node* getParent();
        void setValue(int v);
        void setRank(int r);
        void setParent(Node *p);
        
        
};