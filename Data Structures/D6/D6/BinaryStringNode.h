#ifndef BINARYSTRINGNODE_H
#define BINARYSTRINGNODE_H

#include <string>

using namespace std;

struct BinaryStringNode
{
    public:
        // Constructs a leaf (i.e., left and right child is NULL) with the
        // emtpy string as value.
        BinaryStringNode();
        // Constructs a node with the specified value and left and right
        // children.
        BinaryStringNode(string data, BinaryStringNode *left = NULL, BinaryStringNode *right = NULL);

        string data;
        BinaryStringNode *left;
        BinaryStringNode *right;
};

typedef BinaryStringNode* NodePtr;

#endif // BINARYSTRINGNODE_H
