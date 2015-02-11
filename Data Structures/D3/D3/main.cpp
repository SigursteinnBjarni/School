#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;

int main() {
    NodePtr head, nodePtr1, nodePtr2, nodePtr3;

    head = NULL;    // Initially, the list is empty

    nodePtr1 = createNode(1);   // NodePtr1 points to a new node with data=1
    insert(head, nodePtr1);     // Insert that node after NULL, i.e. into an empty list
    nodePtr2 = createNode(2);   // NodePtr2 points to a new node with data=2
    insert(head, nodePtr2);     // Insert that node after the head node
    nodePtr3 = createNode(3);   // NodePtr3 points to a new node with data=3
    insert(head->forward_link, nodePtr3); // Insert that node after the second node

    display(head);              // Display the nodes of the list
    displayReverse(head);       // Display the nodes in a reverse order
    remove(head, nodePtr2);     // Remove the second node
    display(head);
    displayReverse(head);

    remove(head, nodePtr1);     // Remove the first node
    display(head);
    displayReverse(head);

    remove(head, nodePtr3);     // Remove the first node (which originally was the third node)
    display(head);
    displayReverse(head);
    return 0;
}
