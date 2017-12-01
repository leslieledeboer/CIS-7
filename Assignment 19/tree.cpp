// Assignment 19
// tree.cpp
// Leslie Ledeboer

#include <iostream>
#include "tree.h"

using namespace std;

Tree::Node::Node(string name, Node * left, Node * right)
{
    _name = name;
    _left = left;
    _right = right;
}

string Tree::Node::getName() const
{
    return _name;
}

Tree::Node * Tree::Node::getLeft() const
{
    return _left;
}

Tree::Node * Tree::Node::getRight() const
{
    return _right;
}

void Tree::Node::setLeft(Node * left)
{
    _left = left;
}

void Tree::Node::setRight(Node * right)
{
    _right = right;
}

Tree::Node * Tree::traversal(const string & name, Node * current) const
{
    Node * temp;
    
    if (current == nullptr)
    {
        return nullptr;
    }
    
    if (current->getName() == name)
    {
        return current;
    }
    
    temp = traversal(name, current->getLeft());
    
    if (temp)
    {
        return temp;
    }
    
    return traversal(name, current->getRight());
}

unsigned int Tree::traverseForDepth(Node * current, unsigned int currentDepth) const
{
    static unsigned int maxDepth = 0;
    
    if (current)
    {
        maxDepth = currentDepth;
        
        traverseForDepth(current->getLeft(), currentDepth + 1);
        traverseForDepth(current->getRight(), currentDepth + 1);
    }
    
    return maxDepth;
}

bool Tree::traverseForComplete(Node * current, unsigned int index) const
{
    if (current == nullptr)
    {
        return true;
    }
    
    if (index >= treeSize)
    {
        return false;
    }
    
    return (traverseForComplete(current->getLeft(), 2 * index + 1) &&
            traverseForComplete(current->getRight(), 2 * index + 2));
}

Tree::Tree()
{
    root = new Node("root", nullptr, nullptr);
    treeSize = 1;
}

Tree::~Tree()
{
    delete root;
}

Tree & Tree::addNode(Node * node, bool side, const string & name)
{
    if (!(side ? node->getLeft() : node->getRight()))
    {
        Node * leaf = new Node(name, nullptr, nullptr);
        
        if (side)
        {
            node->setLeft(leaf);
        }
        
        else
        {
            node->setRight(leaf);
        }
        
        treeSize++;
    }
    
    return * this;
}

unsigned int Tree::getTreeSize() const
{
    return treeSize;
}

Tree::Node * Tree::getNode(const string & name) const
{
    return traversal(name, root);
}

unsigned int Tree::getTreeDepth() const
{
    return traverseForDepth(root, 0);
}

bool Tree::isFull() const
{
    return ((1 << (getTreeDepth() + 1)) - 1 == treeSize);
}

bool Tree::isComplete() const
{
    return traverseForComplete(root, 0);
}

void Tree::preorder(Node * current) const
{
    if (current)
    {
        cout << current->getName() << " ";
        
        preorder(current->getLeft());
        preorder(current->getRight());
    }
}

void Tree::inorder(Node * current) const
{
   if (current)
   {
       inorder(current->getLeft());
       
       cout << current->getName() << " ";
       
       inorder(current->getRight());
   }
}

void Tree::postorder(Node * current) const
{
    if (current)
    {
        postorder(current->getLeft());
        postorder(current->getRight());
        
        cout << current->getName() << " ";
    }
}
