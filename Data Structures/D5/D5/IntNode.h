#ifndef INTNODE_H
#define INTNODE_H

struct IntNode
{
    public:
		// Constructs a node with a 0 value and a NULL link
        IntNode();
		// Constructs a node with a value and next link
        IntNode(int value, IntNode *next);

        int data;
        IntNode *link;
};

typedef IntNode* NodePtr;

#endif // INTNODE_H
