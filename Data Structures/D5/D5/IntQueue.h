#ifndef INTQUEUE_H
#define INTQUEUE_H

#include <iostream>
#include "IntNode.h"

using namespace std;

class EmptyQueueException {};

class IntQueue
{
	public:
		// Initializes an empty queue.
		IntQueue();

		// Destructor
		~IntQueue();

		// Returns true if and only if the queue is empty
		bool empty() const;

		// Inserts 'item' at the back of the queue.
		void enqueue(int item);

		// Removes and returns the front of the queue (i.e. the element that
		// was enqueued earliest).
		// If the queue is empty, EmptyQueueException is thrown.
		int dequeue();

		// Returns the front of the queue (i.e. the element that
		// was enqueued earliest).
		// If the queue is empty, EmptyQueueException is thrown.
		int front() const;

		// Prints the elements of the queue to the stream 'outs', from front to
		// back, separated by a single space.
		friend ostream& operator<< (ostream& outs, const IntQueue& queue);

	private:
		NodePtr head;
		NodePtr tail;
};

#endif
