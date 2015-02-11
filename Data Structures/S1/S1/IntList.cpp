#include "IntList.h"
// Constructor: creates an empty list
IntList::IntList()
{
    head = NULL;
}
IntList::~IntList()    // Destructor
{
    removeAll();
}

int IntList::length() // Returns the length of the list
{
    if(head == NULL){
        return 0;
    }
    
    NodePtr curr = head;
    int count = 0;
    while (curr != NULL) {
        count++;
        curr = curr->getLink();
    }
    return count;
}

// Inserts a node with value the_number at the head of the list
void IntList::headInsert(int the_number)
{
    NodePtr new_node = new IntNode(the_number, head);
    head = new_node;
    // head = new IntNode(the_number, head);
}

// Inserts a node with value the_number at the end of the list
void IntList::endInsert(int the_number)
{
    NodePtr new_node = new IntNode(the_number, NULL);
    if (head == NULL) {
        head = new_node;
        return;
    }
    
    NodePtr curr = head;
    while (curr->getLink() != NULL) {
        curr = curr->getLink();
    }
    
    curr->setLink(new_node);
    
}

// Removes the first instance of a node with value the_number from the list
void IntList::remove(int the_number)
{
    /*
    if(head == NULL){
        return;
    }
    
    NodePtr temp;
    if(head -> getData() == the_number){
        temp = head;
        head = head -> getLink();
        delete temp;
    }
    else
    {
        NodePtr current = head;
        //forum i gegnum listann
        while (current != NULL){
			temp = current->getLink();
            if(temp -> getData() == the_number){
                current->setLink(temp -> getLink());
                delete temp;
                return;
            }
			current = current -> getLink();
        }
    }
     */
    NodePtr prev = NULL;
    NodePtr curr = head;
    while (curr->getLink() != NULL) {
        if (curr->getData() == the_number) {
            if (prev == NULL) {
                head = head->getLink();
            }
            else{
                prev->setLink(curr->getLink());
            }
            
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->getLink();
    }

}

// Removes all the nodes in the list
void IntList::removeAll()
{
    if (head == NULL){
        return;
    }
    
    NodePtr curr = head;
    NodePtr temp;
    while (curr != head) {
        temp = curr;
        curr = curr->getLink();
        delete curr;
    }
    head = NULL;
}

// Reverses the order of the nodes in the list
void IntList::reverse()
{
    NodePtr current = head;
    NodePtr prev = NULL; // geymir previous null
    NodePtr next;       // geymir addressuna a naesta
    
    while(current!= NULL){
        next = current -> getLink();
		current -> setLink(prev);
		prev = current;
		current = next;
	}
    
	head = prev;

}

// A friend function for writing the contents of the list to an output stream
ostream& operator <<(ostream& outs, const IntList& lis)
{
    NodePtr curr = lis.head;
    while (curr != NULL) {
        cout << curr->getData() << " ";
        curr = curr->getLink();
    }
    return outs;
}