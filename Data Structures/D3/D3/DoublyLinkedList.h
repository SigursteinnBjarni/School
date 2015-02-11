#ifndef DOUBLYLINKEDLIST_H_INCLUDED
#define DOUBLYLINKEDLIST_H_INCLUDED

struct Node
{
    int data;
    Node* forward_link;
    Node* back_link;
};
typedef Node* NodePtr;

NodePtr createNode(int the_number);
// Creates a new node with value the_number
// Both links are initialised to NULL
// A pointer to the new node is returned

void display(NodePtr head);
// displays the contents of the list pointed to by head on the screen

void displayReverse(NodePtr head);
// displays the contents of the list pointed to by head on the screen in a reverse order

void insert(NodePtr& after_me, NodePtr& newNode);
// after_me is a pointer to the node after which newNode will be inserted

void remove(NodePtr& head, NodePtr discard);
// head is a pointer to the head of the list
// discard is a pointer to the node to remove

#endif // DOUBLYLINKEDLIST_H_INCLUDED
