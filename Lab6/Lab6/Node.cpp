#include "Node.hpp"

Node::Node(const string& value) : data(value), left(nullptr), right(nullptr) {
}

Node::~Node() {
    // Destructor is empty because deletion is handled in the tree class
}
