#ifndef BLOOMFILTER_H
#define BLOOMFILTER_H

#include <string>

#include "HashCollection.h"

using namespace std;

class BloomFilter
{
	public:
		// Initializes a Bloom filter of the specified size, using 'hashes'
		// hash functions.
		BloomFilter(int size, int hashes);

		~BloomFilter();

		// Adds the specified string to the Bloom filter.
		void add(string s);

		// Checks whether the specified string is present.
		// If the function returns false, the string is not present. If the
		// function returns true, the string is possibly present.
		bool contains(string s);


	private:
		bool *filter;
		int size;
		HashCollection *hash_collection;
};

#endif
