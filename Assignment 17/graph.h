// Assignment 17
// graph.h
// Leslie Ledeboer

#ifndef graph_h
#define graph_h

#include <vector>

using namespace std;

class Graph
{
private:
    
    class Vertex
    {
    private:
        
        class Edge
        {
        private:
                    
            Vertex * _head;
            Vertex * _tail;
                    
        public:
                    
            Edge(Vertex *, Vertex *);
            const Vertex * head() const;
            const Vertex * tail() const;
        };
            
        vector <Edge> _edges;
            
    public:
            
        unsigned long degrees() const;
        unsigned int degrees(const Vertex &) const;
        Vertex & addEdge(Vertex &);
        bool isOnlyLoops() const;
    };
    
    vector <Vertex *> _vertices;
    
public:
    
    ~Graph();
    Graph & addVertex();
    vector <vector<unsigned int>> getAdjacency() const;
    unsigned long size() const;
    Vertex * & operator[](unsigned long);
    Vertex * operator[](unsigned long) const;
};

#endif
