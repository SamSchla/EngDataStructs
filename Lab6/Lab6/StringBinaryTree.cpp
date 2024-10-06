#include "StringBinaryTree.hpp"
#include <iostream>
using namespace std;

StringBinaryTree::StringBinaryTree() : root(nullptr), treeSize(0) {
}

//destructor for the binary tree class
StringBinaryTree::~StringBinaryTree() {
    EmptyTree();
}

//defining the public member function by using the private member function 
void StringBinaryTree::Insert(const string& value) {
    insert(root, value);
}

void StringBinaryTree::insert(Node*& node, const string& value) {

    //if there is nothing in the binary tree, add a new node and increment to the tree size
    if (node == nullptr) {
        node = new Node(value);
        treeSize++;

        //used for correct traversal through the tree based on whether the data is 
    }
    else if (value < node->data) {
        insert(node->left, value);
    }
    else if (value > node->data) {
        insert(node->right, value);
    }
}


//uses public member function to define the private find member function 
string StringBinaryTree::Find(const string& value) const {
    return find(root, value) ? value : "";
}

bool StringBinaryTree::find(Node* node, const string& value) const {

    //esures if the node is a nullptr, that the tree is empty and returns false
    if (node == nullptr)
        return false;
    //for if the beginning node contains the desired string
    if (value == node->data)
        return true;

    //traverses the list based on user inputted relative size to the current node and continues
    //on as needed 
    else if (value < node->data)
        return find(node->left, value);
    else
        return find(node->right, value);
}

//functions kept track of tree size and uses that to return the tree size
int StringBinaryTree::Size() const {
    return treeSize;
}

//function for emptying the tree
void StringBinaryTree::EmptyTree() {
    destroyTree(root);
    root = nullptr;
    treeSize = 0;
}

//used to destroy the binary tree without any memory leaks
void StringBinaryTree::destroyTree(Node* node) {
    if (node != nullptr) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}


string StringBinaryTree::Remove(const string& value) {
    //traverses list to find the desired string and removes it
    if (find(root, value)) {

        remove(root, value);
        //decrements the tree size value as needed 
        treeSize--;
        return value;
    }
    return "";
}

void StringBinaryTree::remove(Node*& node, const string& value) {

    if (node == nullptr)
        return;
    //if/else if functions for traversing the tree and removing the string as necessary 
    if (value < node->data) {
        remove(node->left, value);
    }
    else if (value > node->data) {
        remove(node->right, value);
    }
    else {
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            node = temp;
        }
        else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            node = temp;
        }
        else {
            Node* temp = node->right;
            while (temp->left != nullptr)
                temp = temp->left;
            node->data = temp->data;
            remove(node->right, temp->data);
        }
    }
}

//public member function used to define the private member function to print the tree
void StringBinaryTree::PrintTree() const {
    printTree(root);
    cout << endl;
}


//common function used to print binary trees from A to Z
void StringBinaryTree::printTree(Node* node) const {
    if (node != nullptr) {
        printTree(node->left);
        cout << node->data << " ";
        printTree(node->right);
    }
}