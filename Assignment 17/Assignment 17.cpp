// Assignment 17
// Assignment 17.cpp
// Leslie Ledeboer

#include <iostream>
#include <vector>
#include "graph.h"

using namespace std;

int displayMenu();

int main()
{
    int choice;
    vector <Vertex> graph;
    
    do
    {
        do
        {
            choice = displayMenu();
            
        } while (choice < 1 || choice > 3);
        
        switch (choice)
        {
            case 1: graph.push_back(Vertex());
                    break;
                
            case 2:
                    break;
                
            case 3: break;
                
            default: cout << "Error." << endl << endl;
        }
        
    } while (choice != 3);
    
    return 0;
}

int displayMenu()
{
    int choice;
    
    cout << "Number of vertices: " << endl;
    cout << "Number of edges: " << endl << endl;
    
    cout << "Vertex with highest degree: " << endl;
    cout << "Isolated vertices: " << endl;
    cout << "Number of loops: " << endl;
    cout << "Connected: " << endl;
    cout << "Complete: " << endl << endl;
    
    cout << "(1) Add vertex" << endl;
    cout << "(2) Add edge" << endl;
    cout << "(3) Exit" << endl << endl;
    
    cout << "Enter a choice: ";
    cin >> choice;
    cout << endl;
    
    return choice;
}
