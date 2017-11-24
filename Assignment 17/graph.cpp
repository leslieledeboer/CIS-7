// Assignment 17
// graph.cpp
// Leslie Ledeboer

#include "graph.h"

Vertex::Edge::Edge(Vertex *head, Vertex *tail)
{
    _head = head;
    _tail = tail;
}

const Vertex * Vertex::Edge::head() const
{
    return _head;
}

const Vertex * Vertex::Edge::tail() const
{
    return _tail;
}

unsigned int Vertex::degrees() const
{
    unsigned int count = 0;
    
    for (int i = 0; i < _edges.size(); i++)
    {
        if (_edges[i].head() == _edges[i].tail())
        {
            count += 2;
        }
        
        else
        {
            count++;
        }
    }
    
    return count;
}

unsigned int Vertex::degrees(const Vertex & other) const
{
    unsigned int count = 0;
    
    for (int i = 0; i < other._edges.size(); i++)
    {
        if (other._edges[i].head() == this && other._edges[i].tail() == this)
        {
            count += 2;
        }
        
        else if (other._edges[i].tail() == this)
        {
            count++;
        }
    }
    
    return count;
}

Vertex & Vertex::addEdge(Vertex & other)
{
    _edges.push_back(Edge(this, & other));
    
    other._edges.push_back(Edge(& other, this));
    
    return * this;
}

vector <vector<unsigned int>> getAdjacency(const vector <Vertex> & graph)
{
    vector <vector<unsigned int>> adjacency(graph.size());
    
    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = 0; j < graph.size(); j++)
        {
            adjacency[i].push_back(graph[i].degrees(graph[j]));
        }
    }
    
    return adjacency;
}
