#include "Vertex.cpp"
#include <iostream>

using namespace std;
class Edge
{
    private:
        Vertex *src;
        Vertex *dst;
        int weight;
    public:
        Edge();
        Edge(Vertex *s, Vertex *d, int p);
        void setSource(Vertex *s);
        void setDestination(Vertex *d);
        void setWeight(int p);
        Vertex *getSource();
        Vertex *getDestination();
        int getWeight();     
        void relax();
        void showEdge(); 
};