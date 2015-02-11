#include "StringSet.h"

// Constructor: creates an empty set.
StringSet::StringSet()
{
    head = NULL;
}

// Destructor.
StringSet::~StringSet()
{
    removeAll();
}

// Returns the number of elements in the set.
int StringSet::size()
{
    NodePtr curr = head;
    int count = 0;
    while (curr != NULL) {
        count++;
        curr = curr->getLink();
    }
    return count;
}

// Inserts 'element' into the set. If 'element' is contained in the
// set, this operation has no effect.
void StringSet::insert(string element)
{
    if (contains(element)){
        return;
    }
    NodePtr prev = NULL;
    NodePtr curr = head;
    
    if (head == NULL) {
        head = new StringNode(element, head);
    }
    
    while (curr != NULL){   // if the element is lesser than our data
        if (curr->getData() > element){
            // new node created with a pointer to current
            NodePtr new_node = new StringNode(element, curr);
            if(prev == NULL){
                head = new_node;
            }
            else{
                prev->setLink(new_node);
            }
            return;
        }
        else if (curr->getData() < element && curr->getLink() == NULL){
            NodePtr new_node = new StringNode(element, NULL);
            curr->setLink(new_node);
        }
        prev = curr;
        curr = curr->getLink();
    }
    /*
    // if we get through the loop we instert at head
    NodePtr new_node = new StringNode(element, NULL);
    if (prev == NULL){
        head = new_node;
    }
    else{
        prev->setLink(new_node);
    }
     */
}

// Removes 'element' from the set. If 'element' is not in the set, this
// operation has no effect.
void StringSet::remove(string element)
{
    if(head == NULL){
        return;
    }
        NodePtr curr = head;
        NodePtr prev = NULL;
        while (curr != NULL)
        {
            if (curr->getData() == element){
                if (prev == NULL){
                    head = curr->getLink();
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

// Returns true if and only if 'element' is a member of the set.
bool StringSet::contains(string element)
{
    if(head == NULL){
        return false;
    }
    NodePtr node = head;
    while (node != NULL) {
        if (node->getData() == element) {
            return true;
        }
        node = node->getLink();
    }
    return false;
}

void StringSet::removeAll()
{
    if (head == NULL) {
        return;
    }
    
    NodePtr node = head;
    NodePtr temp;
    while (node != NULL) {
        temp = node->getLink();
        delete node;
        node = temp;
    }
    head = NULL;
    
}

// A friend function for writing the contents of the set to an output stream.
ostream& operator <<(ostream& outs, const StringSet& set)
{
    NodePtr curr = set.head;
    while (curr != NULL) {
        outs << curr->getData() << endl;
        curr = curr->getLink();
    }
    return outs;
}