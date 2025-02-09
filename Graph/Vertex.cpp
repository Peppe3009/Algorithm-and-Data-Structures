#include "Vertex.h"

Vertex::Vertex()
{
    this->index = numeric_limits<int>::min();
    this->distance = INF;
    this->color = 'W';
    this->key = INF;
    this->predecessor = nullptr;
    vector<Vertex *> vectorVuoto;
    this->adjacencyList = vectorVuoto;
}

Vertex::Vertex(int i)
{
    this->index = i;
    this->distance = INF;
    this->color = 'W';
    this->key = INF;
    this->predecessor = nullptr;
    vector<Vertex *> vectorVuoto;
    this->adjacencyList = vectorVuoto;
}

void Vertex ::setIndex(int i)
{
    this->index = i;
}
void Vertex ::setDistance(int d)
{
    this->distance = d;
}
void Vertex ::setColor(char c)
{
    this->color = c;
}
void Vertex:: setTtv(int t)
{
    this->ttv = t;
}
void Vertex:: setKey(int c)
{
    this->key = c;
}

void Vertex ::setPredecessor(Vertex *v)
{
    this->predecessor = v;
}

int Vertex :: getIndex()
{
    return this->index;
}
int Vertex :: getDistance()
{
    return this->distance;
}
char Vertex :: getColor()
{
    return this->color;
}
int Vertex :: getTtv()
{
    return this->ttv;
}
int Vertex :: getKey()
{
    return this->key;
}

Vertex *Vertex :: getPredecessor()
{
    return this->predecessor;
}
vector<Vertex *> Vertex :: getAdjacencyList()
{
    return this->adjacencyList;
}

vector<Vertex *> Vertex :: getAdjacencyListTransposed()
{
    return this->adjacencyListTransposed;
}


void Vertex :: addAdjacencyList(Vertex *v)
{
    this->adjacencyList.push_back(v);
}

void Vertex :: addAdjacencyListTransposed(Vertex *v)
{
    this->adjacencyListTransposed.push_back(v);
}