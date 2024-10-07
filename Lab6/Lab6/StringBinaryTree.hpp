#ifndef STRINGBINARYTREE_H
#define STRINGBINARYTREE_H

#include "Node.hpp"
#include <string>
using namespace std;

class StringBinaryTree {
private:
    //creating Node class pointer of the root
    Node* root;
    int treeSize;

    //defining private member functions to do operations on the tree
    void insert(Node*& node, const string& value);
    bool find(Node* node, const string& value) const;
    void remove(Node*& node, const string& value);
    void destroyTree(Node* node);
    void printTree(Node* node) const;

public:

    //constructor and destructor for the binary tree
    StringBinaryTree();
    ~StringBinaryTree();

    //needed member functions for the traversal and manipulation of the binary tree
    void Insert(const string& value);
    string Find(const string& value) const;
    int Size() const;
    void EmptyTree();
    string Remove(const string& value);
    void PrintTree() const;
};

#endif 