#ifndef STRINGNODE_H
#define STRINGNODE_H
#include <string>

using namespace std;

class StringNode
{
    public:
        // Constructors to initialize a node
        StringNode();                      // Constructs a node with a 0 value and a NULL link
        StringNode(string value, StringNode *next); // Constructs a node with a value and next link

        string getData() const;    // Retrieve value for this node
        StringNode* getLink() const;  // Retrieve next node in the list

        void setData(string value); // Use to modify the value stored in the list
        void setLink(StringNode* next); // Use to change the reference to the next node

    private:
        string data;
        StringNode *link;
};

typedef StringNode* NodePtr;

#endif // STRINGNODE_H
