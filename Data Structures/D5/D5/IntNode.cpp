#include <iostream>
#include "IntNode.h"

IntNode::IntNode() : data(0), link(NULL) {
    // Default constructor
}

IntNode::IntNode(int value, IntNode *next) : data(value), link(next) {
// Constructs a node with a value and next link
}
