#include <iostream>
#include <string>
#include "StringNode.h"

StringNode::StringNode() : data(""), link(NULL) {
    // Default constructor
}

StringNode::StringNode(string value, StringNode *next) : data(value), link(next) {
    // Constructs a node with a value and next link
}

// Accessor and Mutator methods follow
string StringNode::getData() const {
    return data;
}

StringNode* StringNode::getLink( ) const {
    return link;
}

void StringNode::setData(string value) {
    data = value;
}

void StringNode::setLink(StringNode *next) {
    link = next;
}
