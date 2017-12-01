// Assignment 19
// Assignment 19.cpp
// Leslie Ledeboer

#include <iostream>
#include <cctype>
#include "tree.h"

using namespace std;

int displayMenu(const Tree &);
void addNode(Tree &);

int main()
{
    int choice;
    Tree tree;
    
    do
    {
        do
        {
            choice = displayMenu(tree);
            
        } while (choice < 1 || choice > 2);
        
        switch (choice)
        {
            case 1: addNode(tree);
                    break;
                
            case 2: break;
                
            default: cout << "Error." << endl << endl;
        }
        
    } while (choice != 2);
    
    return 0;
}

int displayMenu(const Tree & tree)
{
    int choice;
    
    cout << "The name of the root node is root." << endl << endl;
    
    cout << "Number of nodes: " << tree.getTreeSize() << endl;
    cout << "Depth of tree: " << tree.getTreeDepth() << endl;
    cout << "Full: " << (tree.isFull() ? "Yes" : "No") << endl;
    cout << "Complete: " << (tree.isComplete() ? "Yes" : "No") << endl;
    
    cout << "Preorder: ";
    tree.preorder(tree.getNode("root"));
    cout << endl;
    
    cout << "Inorder: ";
    tree.inorder(tree.getNode("root"));
    cout << endl;
    
    cout << "Postorder: ";
    tree.postorder(tree.getNode("root"));
    cout << endl << endl;
    
    cout << "(1) Add node" << endl;
    cout << "(2) Exit" << endl << endl;
    
    cout << "Enter a choice: ";
    cin >> choice;
    cout << endl;
    
    return choice;
}

void addNode(Tree & tree)
{
    string parentName;
    char choice;
    
    cout << "Enter name of parent node: ";
    cin.ignore();
    getline(cin, parentName);
    cout << endl;
    
    Tree::Node * parentNode = tree.getNode(parentName);
    
    if (parentNode)
    {
        if (!parentNode->getLeft())
        {
            cout << "(L) Add left child" << endl;
        }
        
        if (!parentNode->getRight())
        {
            cout << "(R) Add right child" << endl << endl;
        }
        
        if (parentNode->getLeft() && parentNode->getRight())
        {
            cout << "Error. Node has left child and right child." << endl << endl;
            
            return;
        }
        
        cout << "Enter a choice: ";
        cin >> choice;
        cout << endl;
        
        if (toupper(choice) == 'L')
        {
            tree.addNode(parentNode, LEFT, parentName + "_L");
        }
        
        else if (toupper(choice) == 'R')
        {
            tree.addNode(parentNode, RIGHT, parentName + "_R");
        }
        
        else
        {
            cout << "Error. Invalid choice." << endl << endl;
        }
    }
    
    else
    {
        cout << "Parent node not found." << endl << endl;
    }
}
