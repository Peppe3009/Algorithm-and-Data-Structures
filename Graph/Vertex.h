#include <vector>
#include <limits>

#define INF numeric_limits<int>::max()

using namespace std;
class Vertex
{
    private:
        int index;
        int distance;
        char color;
        int ttv; // Time to visit
        int key;
        Vertex *predecessor;
        vector<Vertex *> adjacencyList;
        vector<Vertex *> adjacencyListTransposed;
        
    public:
        Vertex();
        Vertex(int i);
        void setIndex(int i);
        void setDistance(int d);
        void setColor(char c);
        void setTtv(int t);
        void setKey(int c);
        void setPredecessor(Vertex *v);
        int getIndex();
        int getDistance();
        char getColor();
        int getTtv();
        int getKey();
        Vertex *getPredecessor();
        vector<Vertex *>getAdjacencyList();
        vector<Vertex *>getAdjacencyListTransposed();
        void addAdjacencyList(Vertex *v);
        void addAdjacencyListTransposed(Vertex *v);
        
        
        
};