#include "Graph.h"
using namespace std;
Graph ::Graph()
{
    stack<Vertex *> emptyTopologicalSortStack;
    this->vertices.resize(0);
    this->edges.resize(0);
    this->topologicalSortStack = emptyTopologicalSortStack;
}
/**
 * This constructor allows to create a graph from a file structured as follows:
 * nVert nEdg
 * V1 V2 W1
 * V2 V3 W2
 * ....
 * 
 */

Graph ::Graph(string filename)
{
    ifstream inputFile(filename);
    int vertices, edges;
    if (!inputFile)
    {
        cerr << "Errore while opening. " << filename << " not found." << endl;
        return;
    }

    inputFile >> vertices >> edges;
    cout << "Vertecis: " << vertices << "\nEdges: " << edges << endl;

    while (!inputFile.eof())
    {
        int src, dst, weight;
        inputFile >> src >> dst >> weight;
        this->addEdge(src, dst, weight);
    }
    if (this->vertices.size() == vertices && this->edges.size() == edges)
    {
        cout << "Loading completed successfully." << endl;
    }
    else if (this->vertices.size() != vertices || this->edges.size() != edges)
    {
        cerr << "Problema while loading." << endl;
    }
    cout << "Loaded Vertices: " << this->vertices.size() << "\nLoaded Edges: " << this->edges.size() << endl;
}

int Graph ::getVertexNumber()
{
    return this->vertices.size();
}
int Graph ::getEdgeNumber()
{
    return this->edges.size();
}

void Graph ::reset()
{
    for (Vertex *v : this->vertices)
    {
        v->setColor('W');
        v->setTtv(0);
        v->setDistance(INF);
        v->setPredecessor(nullptr);
    }
}

Vertex *Graph ::findVertex(int index)
{
    Vertex *foundVertex = new Vertex();

    for (Vertex* v : this->vertices)
    {
        if (v->getIndex() == index)
        {
            foundVertex = v;
        }
    }
    return foundVertex;
}

Edge *Graph ::findEdge(int src, int dst)
{
    Edge *foundEdge = new Edge();

    for (Edge* a : this->edges)
    {
        if (a->getSource()->getIndex() == src && a->getDestination()->getIndex() == dst)
        {
            foundEdge = a;
        }
    }

    return foundEdge;
}

void Graph ::addEdge(int indexSrc, int indexDst, int p)
{

    Vertex *src = this->findVertex(indexSrc);
    Vertex *dst = this->findVertex(indexDst);

    if (src->getIndex() == INF)
    {
        src = new Vertex(indexSrc);
        this->vertices.push_back(src);
    }
    if (dst->getIndex() == INF)
    {
        dst = new Vertex(indexDst);
        this->vertices.push_back(dst);
    }
    src->addAdjacencyList(dst);

    Edge *edge = new Edge(src, dst, p);
    this->edges.push_back(edge);
}

void Graph ::DFS_Visit(Vertex *u, int t)
{
    u->setColor('G');
    t = t + 1;
    u->setDistance(t);
    for (auto &v : u->getAdjacencyList())
    {
        if (v->getColor() == 'W')
        {
            v->setPredecessor(u);
            this->DFS_Visit(v, t);
        }
    }
    t = t + 1;
    u->setColor('B');
    u->setTtv(t);
    this->topologicalSortStack.push(u);
}

void Graph ::DFS_VisitTransposed(Vertex *u, int t)
{
    u->setColor('G');
    t = t + 1;
    u->setDistance(t);
    for (auto &v : u->getAdjacencyListTransposed())
    {
        if (v->getColor() == 'W')
        {
            v->setPredecessor(u);
            this->DFS_VisitTransposed(v, t);
        }
    }
    t = t + 1;
    u->setColor('B');
    cout << u->getIndex() << " ";
    u->setTtv(t);
}

void Graph ::DFS()
{
    // reset everything
    this->reset();

    while (!this->topologicalSortStack.empty())
    {
        this->topologicalSortStack.pop();
    }

    // DFS VISIT
    int time = 0;
    for (auto &u : this->vertices)
    {
        if (u->getColor() == 'W')
        {
            this->DFS_Visit(u, time);
        }
    }
}

void Graph::BFS(int indexSrc)
{

    this->reset();

    Vertex *s = this->findVertex(indexSrc);
    if (s->getIndex() == INF)
    {
        cerr << "Vertex not found." << endl;
        return;
    }

    s->setColor('G');
    s->setDistance(0);
    queue<Vertex *> visitedVertexQueue;
    visitedVertexQueue.push(s);
    while (!visitedVertexQueue.empty())
    {
        Vertex *u = visitedVertexQueue.front();
        for (auto &v : u->getAdjacencyList())
        {
            if (v->getColor() == 'W')
            {
                v->setColor('G');
                v->setDistance(u->getDistance() + 1);
                v->setPredecessor(u);
                visitedVertexQueue.push(v);
            }
        }
        visitedVertexQueue.pop();
        u->setColor('B');
    }
}

stack<Vertex *> Graph ::TopologicalSort()
{
    this->DFS();
    return this->topologicalSortStack;
}

void Graph ::saveTopologicalSort()
{
    stack<Vertex *> sortedVertices = this->TopologicalSort();
    ofstream outputFile("Out.txt");
    outputFile << "Topological Sort: " << endl;
    while (!sortedVertices.empty())
    {
        outputFile << sortedVertices.top()->getIndex() << " - t: " << sortedVertices.top()->getTtv() << endl;
        sortedVertices.pop();
    }
    cout << "File written." << endl;
}

bool Graph ::Bellman_Ford(int indexSrc)
{

    Vertex *s = this->findVertex(indexSrc);
    bool foundCycle = false;
    if (s->getIndex() == INF)
    {
        cerr << "Vertex " << s->getIndex() << " not found." << endl;
        return foundCycle;
    }

    this->reset();
    s->setDistance(0);
    for (int i = 0; i < this->vertices.size(); i++)
    {
        for (auto &a : edges)
        {
            a->relax();
        }
    }
    for (Edge *e : edges)
    {
        Vertex *v = e->getDestination();
        Vertex *u = e->getSource();
        if (v->getDistance() > u->getDistance() + e->getWeight())
        {
            foundCycle = true;
        }
    }

    return foundCycle;
}

void Graph ::Dijkstra(int src)
{
    struct lessOnDistance
    {
        bool operator()(Vertex *l, Vertex *r) const { return l->getDistance() < r->getDistance(); }
    };

    Vertex *s = this->findVertex(src);
    if (s->getIndex() == INF)
    {
        cerr << "Vertex " << s->getIndex() << " not found." << endl;
        return;
    }
    vector<Vertex *> visitedVertices;
    priority_queue<Vertex *, vector<Vertex *>, lessOnDistance> queue;

    this->reset();

    s->setDistance(0);

    for (Vertex *v : this->vertices)
    {

        queue.push(v);
    }

    while (!queue.empty())
    {
        Vertex *u = queue.top();
        queue.pop();
        visitedVertices.push_back(u);
        for (Vertex *v  : u->getAdjacencyList())
        {
            Edge *a = this->findEdge(u->getIndex(), v->getIndex());
            a->relax();
        }
    }
    for (Vertex *v  : vertices)
    {
        cout << "v: " << v->getIndex() << " " << v->getDistance() << endl;
    }
}

vector<Edge *> Graph ::MST_Kruskal()
{
    struct compare
    {
        bool operator()(Edge *a, Edge *b) const { return a->getWeight() <= b->getWeight(); }
    } compareEdges;

    vector<Edge *> spanningEdgesSet;
    DisjointSet<int> disjointSet;

    for (auto &vertice : this->vertices)
    {
        disjointSet.makeSet(vertice->getIndex());
    }

    sort(this->edges.begin(), this->edges.end(), compareEdges);

    for (auto &e : this->edges)
    {
        Vertex *u = e->getSource();
        Vertex *v = e->getDestination();
        if (disjointSet.findSet(u->getIndex()) != disjointSet.findSet(v->getIndex()))
        {
            spanningEdgesSet.push_back(e);
            disjointSet.unionSet(u->getIndex(), v->getIndex());
        }
    }
    return spanningEdgesSet;
}

vector<Edge *> Graph::MST_Prim(int indexSrc)
{
    struct lessOnKey
    {
        bool operator()(Vertex *l, Vertex *r) const { return l->getKey() > r->getKey(); }
    };

    vector<Edge *> spanningEdgesSet;
    priority_queue<Vertex *, vector<Vertex *>, lessOnKey> queue;
    unordered_set<Vertex *> set;

    for (Vertex *v : this->vertices)
    {
        queue.push(v);
        set.insert(v);
    }

    Vertex *r = this->findVertex(indexSrc);

    r->setKey(0);
    r->setPredecessor(nullptr);

    while (!queue.empty())
    {
        Vertex *u = queue.top();
        queue.pop();
        set.erase(u);
        for (auto &v : u->getAdjacencyList())
        {
            bool inQueue = find(set.begin(), set.end(), v) != set.end();
            Edge *uv_edge = this->findEdge(u->getIndex(), v->getIndex());
            if (inQueue && uv_edge->getWeight() < v->getKey())
            {
                v->setPredecessor(u);
                v->setKey(uv_edge->getWeight());
                spanningEdgesSet.push_back(uv_edge);
            }
        }
    }
    return spanningEdgesSet;
}

void Graph ::StronglyConnectedComponents()
{
    stack<Vertex *> topologicalSortStackTopologico = this->TopologicalSort();

    for (Edge *e : this->edges)
    {
        e->getDestination()->setColor('W');
        e->getSource()->setColor('W');
        e->getDestination()->addAdjacencyListTransposed(e->getSource());
    }

    int t = 0;
    while (!topologicalSortStackTopologico.empty())
    {
        Vertex *v = topologicalSortStackTopologico.top();
        topologicalSortStackTopologico.pop();
        if (v->getColor() == 'W')
        {
            this->DFS_VisitTransposed(v, t);
            cout << endl << "--------------" << endl;
        }
    }
}