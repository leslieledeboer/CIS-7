// Assignment 17
// graph.cpp
// Leslie Ledeboer

#include "graph.h"

Graph::Vertex::Edge::Edge(Vertex * head, Vertex * tail):_head(head), _tail(tail)
{
}

const Graph::Vertex * Graph::Vertex::Edge::head() const
{
    return _head;
}

const Graph::Vertex * Graph::Vertex::Edge::tail() const
{
    return _tail;
}

unsigned long Graph::Vertex::degrees() const
{
    return _edges.size();
}

unsigned int Graph::Vertex::degrees(const Vertex & other) const
{
    unsigned int count = 0;
    
    for (int i = 0; i < other._edges.size(); i++)
    {
        if (other._edges[i].tail() == this)
        {
            count++;
        }
    }
    
    return count;
}

Graph::Vertex & Graph::Vertex::addEdge(Vertex & other)
{
    _edges.push_back(Edge(this, & other));
    
    other._edges.push_back(Edge(& other, this));
    
    return * this;
}

bool Graph::Vertex::isOnlyLoops() const
{
    if (degrees(* this) == degrees())
    {
        return true;
    }
    
    return false;
}

Graph::~Graph()
{
    for (int i = 0; i < _vertices.size(); i++)
    {
        delete _vertices[i];
    }
}

Graph & Graph::addVertex()
{
    Vertex * vertex = new Vertex;
    
    _vertices.push_back(vertex);
    
    return * this;
}

vector <vector<unsigned int>> Graph::getAdjacency() const
{
    vector <vector<unsigned int>> adjacency(_vertices.size());
    
    for (int i = 0; i < _vertices.size(); i++)
    {
        for (int j = 0; j < _vertices.size(); j++)
        {
            adjacency[i].push_back(_vertices[i]->degrees(* _vertices[j]));
        }
    }
    
    return adjacency;
}

unsigned long Graph::size() const
{
    return _vertices.size();
}

Graph::Vertex * & Graph::operator[](unsigned long index)
{
    return _vertices[index];
}

Graph::Vertex * Graph::operator[](unsigned long index) const
{
    return _vertices[index];
}
