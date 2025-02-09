#include "Edge.cpp"
#include "../Disjoint_Set/DisjointSet.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_set>

using namespace std;
class Graph
{
private:
    vector<Vertex *> vertices;
    vector<Edge *> edges;
    stack<Vertex *> topologicalSortStack;
    Edge *findEdge(int, int);
    void DFS_Visit(Vertex *, int);
    void DFS_VisitTransposed(Vertex *, int);
    void reset();

public:
    Graph();
    Graph(string);
    void addEdge(int, int, int);
    int getVertexNumber();
    Vertex *findVertex(int);
    int getEdgeNumber();
    void DFS();
    void BFS(int indexSrc);
    stack<Vertex *> TopologicalSort();
    void saveTopologicalSort();
    bool Bellman_Ford(int);
    void Dijkstra(int);
    void StronglyConnectedComponents();
    vector<Edge *> MST_Kruskal();
    vector<Edge *> MST_Prim(int);
};