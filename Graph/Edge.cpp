#include "Edge.h"
Edge ::Edge()
{
    this->src = nullptr;
    this->dst = nullptr;
    this->weight = INF;
}

Edge ::Edge(Vertex *s, Vertex *d, int w)
{
    this->src = s;
    this->dst = d;
    this->weight = w;
}

void Edge::setSource(Vertex *s)
{
    this->src = s;
}

void Edge::setDestination(Vertex *d)
{
    this->dst = d;
}

void Edge::setWeight(int w)
{
    this->weight = w;
}

Vertex *Edge ::getSource()
{
    return this->src;
}

Vertex *Edge ::getDestination()
{
    return this->dst;
}

int Edge ::getWeight()
{
    return this->weight;
}

void Edge :: showEdge()
{
    cout << "{(" << this->src->getIndex() << ", " << this->dst->getIndex() << "), " << this->weight << "}" << endl;
}

void Edge ::relax()
{   
    Vertex *u = this->src;
    Vertex *v = this->dst;
    
    if (v->getDistance() > u->getDistance() + this->weight)
    {
        v->setDistance(u->getDistance() + this->weight);
        v->setPredecessor(u);
    }
}