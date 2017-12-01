// Assignment 19
// tree.h
// Leslie Ledeboer

#ifndef tree_h
#define tree_h
#define LEFT true
#define RIGHT false

#include <string>

using namespace std;

class Tree
{
public:
    
    class Node;
    
private:
    
    Node * root;
    unsigned int treeSize;
    Node * traversal(const string &, Node *) const;
    unsigned int traverseForDepth(Node *, unsigned int) const;
    bool traverseForFull(Node *) const;
    bool traverseForComplete(Node *, unsigned int) const;
    
public:
    
    class Node
    {
    private:
        
        string _name;
        Node * _left, * _right;
        
    public:
        
        Node(string, Node *, Node *);
        string getName() const;
        Node * getLeft() const;
        Node * getRight() const;
        void setLeft(Node *);
        void setRight(Node *);
    };
    
    Tree();
    ~Tree();
    Tree & addNode(Node *, bool, const string &);
    unsigned int getTreeSize() const;
    Node * getNode(const string &) const;
    unsigned int getTreeDepth() const;
    bool isFull() const;
    bool isComplete() const;
    void preorder(Node *) const;
    void inorder(Node *) const;
    void postorder(Node *) const;
};

#endif
