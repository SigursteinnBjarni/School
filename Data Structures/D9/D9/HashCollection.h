#ifndef HASHCOLLECTION_H
#define HASHCOLLECTION_H

#include <string>

using namespace std;

class Hash
{
    public:
        Hash(int seed);
        unsigned int hash(string s);

    private:
        int seed;
};


typedef Hash* HashPtr;

// A collection of hash functions
class HashCollection
{
    public:
		// Initializes a colletion of hash fuction of the specified size.
        HashCollection(int size);
        ~HashCollection();

		// Returns the size of the collection.
        int size();

		// Returns the hash of the specified string for the n-th hash function
		// in the collection.
        unsigned int get_hash(int n, string s);

    private:
        int count;
        HashPtr *list;
};

#endif
