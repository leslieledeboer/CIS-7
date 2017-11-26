// Assignment 17
// Assignment 17.cpp
// Leslie Ledeboer

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "graph.h"

using namespace std;

int displayMenu(const Graph &, unsigned int);
unsigned int addEdge(Graph &);
unsigned int highestDegree(const Graph &);
string isolatedVertices(const Graph &);
unsigned int numberOfLoops(const Graph &);
bool isConnected(const Graph &);
bool isComplete(const Graph &);

int main()
{
    int choice;
    Graph graph;
    unsigned int edgeCount = 0;
    
    do
    {
        do
        {
            choice = displayMenu(graph, edgeCount);
            
        } while (choice < 1 || choice > 3);
        
        switch (choice)
        {
            case 1: graph.addVertex();
                    break;
                
            case 2: edgeCount = addEdge(graph);
                    break;
                
            case 3: break;
                
            default: cout << "Error." << endl << endl;
        }
        
    } while (choice != 3);
    
    return 0;
}

int displayMenu(const Graph & graph, unsigned int edgeCount)
{
    int choice;
    
    cout << "Number of vertices: " << graph.size() << endl;
    cout << "Number of edges: " << edgeCount << endl << endl;
    
    cout << "Vertex with highest degree: ";
    
    if (graph.size() != 0)
    {
        cout << highestDegree(graph) << endl;
    }
    
    else
    {
        cout << "N/A" << endl;
    }
    
    cout << "Isolated vertices: " << isolatedVertices(graph) << endl;
    cout << "Number of loops: " << numberOfLoops(graph) << endl;
    
    cout << "Connected: ";
    
    if (graph.size() != 0)
    {
        cout << (isConnected(graph) ? "Yes" : "No") << endl;
    }
    
    else
    {
        cout << "N/A" << endl;
    }
    
    cout << "Complete: ";
    
    if (graph.size() != 0)
    {
        cout << (isComplete(graph) ? "Yes" : "No") << endl << endl;
    }
    
    else
    {
        cout << "N/A" << endl << endl;
    }
    
    cout << "(1) Add vertex" << endl;
    cout << "(2) Add edge" << endl;
    cout << "(3) Exit" << endl << endl;
    
    cout << "Enter a choice: ";
    cin >> choice;
    cout << endl;
    
    return choice;
}

unsigned int addEdge(Graph & graph)
{
    static unsigned int count = 0;
    
    if (graph.size() == 0)
    {
        cout << "Error." << endl << endl;
    }
    
    else
    {
        unsigned int first = 0, second = 0;
        
        cout << "Enter first vertex: ";
        cin >> first;
        cout << endl;
        
        cout << "Enter second vertex: ";
        cin >> second;
        cout << endl;
        
        if (graph.size() <= --first || graph.size() <= --second)
        {
            cout << "Error." << endl << endl;
        }
        
        else
        {
            graph[first]->addEdge(* graph[second]);
            
            count++;
        }
    }
    
    return count;
}

unsigned int highestDegree(const Graph & graph)
{
    unsigned int highest = 0;
    
    for (int i = 0; i < graph.size(); i++)
    {
        if (graph[i]->degrees() > graph[highest]->degrees())
        {
            highest = i;
        }
    }
    
    return highest + 1;
}

string isolatedVertices(const Graph & graph)
{
    stringstream lonelyVertices;
    
    for (int i = 0; i < graph.size(); i++)
    {
        if (graph[i]->degrees() == 0)
        {
            lonelyVertices << i + 1;
            
            if (i + 1 < graph.size())
            {
                lonelyVertices << ", ";
            }
        }
    }
    
    return lonelyVertices.str().empty() ? "N/A" : lonelyVertices.str();
}

unsigned int numberOfLoops(const Graph & graph)
{
    unsigned int loopCount = 0;
    
    for (int i = 0; i < graph.size(); i++)
    {
        loopCount += graph[i]->degrees(* graph[i]) / 2;
    }
    
    return loopCount;
}

bool isConnected(const Graph & graph)
{
    if (graph.size() > 1)
    {
        for (int i = 0; i < graph.size(); i++)
        {
            if (graph[i]->degrees() == graph[i]->degrees(* graph[i]) || graph[i]->isOnlyLoops())
            {
                return false;
            }
        }
    }
    
    return true;
}

bool isComplete(const Graph & graph)
{
    vector <vector<unsigned int>> adjacency = graph.getAdjacency();
    
    for (int i = 0; i < adjacency.size(); i++)
    {
        for (int j = 0; j < adjacency[i].size(); j++)
        {
            if (i != j && adjacency[i][j] == 0)
            {
                return false;
            }
        }
    }
    
    return true;
}
