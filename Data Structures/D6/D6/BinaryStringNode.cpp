#include "BinaryStringNode.h"

BinaryStringNode::BinaryStringNode()
    : data(""), left(NULL), right(NULL)
{

}

BinaryStringNode::BinaryStringNode(string data, BinaryStringNode *left, BinaryStringNode *right)
    : data(data), left(left), right(right)
{

}
