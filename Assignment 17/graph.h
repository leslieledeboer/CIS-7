// Assignment 17
// graph.h
// Leslie Ledeboer

#ifndef graph_h
#define graph_h

#include <vector>

using namespace std;

class Vertex
{
    private:
    
        class Edge
        {
            private:
            
                Vertex *_head, *_tail;
            
            public:
            
                Edge(Vertex *, Vertex *);
                const Vertex * head() const;
                const Vertex * tail() const;
        };
    
        vector <Edge> _edges;
    
    public:
    
        unsigned int degrees() const;
        unsigned int degrees(const Vertex &) const;
        Vertex & addEdge(Vertex &);
};

vector <vector<unsigned int>> getAdjacency(const vector <Vertex> &);

#endif
