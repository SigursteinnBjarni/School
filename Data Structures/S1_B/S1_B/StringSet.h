#ifndef STRINGSET_H
#define STRINGSET_H
#include <iostream>
#include <string>
#include "StringNode.h"
using namespace std;

class StringSet
{
	public:
		// Constructor: creates an empty set.
		StringSet();

		// Destructor.
		~StringSet();

		// Returns the number of elements in the set.
		int size();

		// Inserts 'element' into the set. If 'element' is contained in the
		// set, this operation has no effect.
		void insert(string element);

		// Removes 'element' from the set. If 'element' is not in the set, this
		// operation has no effect.
		void remove(string element);

		// Returns true if and only if 'element' is a member of the set.
		bool contains(string element);

		// A friend function for writing the contents of the set to an output stream.
		friend ostream& operator <<(ostream& outs, const StringSet& set);

	private:
		void removeAll();
		NodePtr head; // pointer to the head of the linked list
};

#endif // STRINGSET_H
