#include "IntQueue.h"

IntQueue::IntQueue()
{
    head = NULL;
    tail = NULL;
}

// Destructor
IntQueue::~IntQueue()
{
    NodePtr curr = head;
    NodePtr temp = NULL;
    while (curr != NULL){
        temp = curr->link;
        delete curr;
        curr = temp;
    }
    delete temp;
    head = NULL;
}

// Returns true if and only if the queue is empty
bool IntQueue::empty() const
{
    return (head == NULL);
}

// Inserts 'item' at the back of the queue.
void IntQueue::enqueue(int item)
{
    NodePtr new_node = new IntNode(item, NULL);
    
    if (head == NULL) {
        head = new_node;
        tail = new_node;
        return;
    }
    
    NodePtr prev = tail;
    prev->link = new_node;
    tail = new_node;

}

// Removes and returns the front of the queue (i.e. the element that
// was enqueued earliest).
// If the queue is empty, EmptyQueueException is thrown.
int IntQueue::dequeue()
{
    if (!empty()) {
        NodePtr temp = head->link;
        int value = head->data;
        delete head;
        head = temp;
        return value;
    }
    throw EmptyQueueException();
}

// Returns the front of the queue (i.e. the element that
// was enqueued earliest).
// If the queue is empty, EmptyQueueException is thrown.
int IntQueue::front() const
{
    if (!empty()) {
        return head->data;
    }
    throw EmptyQueueException();
}

// Prints the elements of the queue to the stream 'outs', from front to
// back, separated by a single space.
ostream& operator<< (ostream& outs, const IntQueue& queue)
{
    NodePtr curr = queue.head;
    while (curr != NULL) {
        outs << curr->data << " ";
        curr = curr->link;
    }
    return outs;
}
