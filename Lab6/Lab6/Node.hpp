#ifndef NODE_H
#define NODE_H

#include <string>
using namespace std;

//creating standard Node class for a binary tree
class Node {
private:

public:
    string data;
    Node* left;
    Node* right;

    //overloaded constructor for passing the address of the value inserted
    Node(const string& value);

    //destructor for Node class
    ~Node();
};

#endif // NODE_H