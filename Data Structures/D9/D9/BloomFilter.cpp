#include "BloomFilter.h"

BloomFilter::BloomFilter(int size, int hashes)
{
    //initilize the collection with number of hases
    hash_collection = new HashCollection(hashes);
    this->size = size;
    filter = new bool[size];
    // set all pos to false
    for (int i = 0; i < size; i++) {
        filter[i] = false;
    }
    
}

BloomFilter::~BloomFilter()
{
    delete [] filter;
    delete hash_collection;
}

void BloomFilter::add(string s)
{
    for (int i = 0; i < hash_collection->size(); i++) {
        filter[hash_collection->get_hash(i, s) % size] = true;
    }
}

bool BloomFilter::contains(string s)
{
    for (int i = 0; i < hash_collection->size(); i++) {
        if(!filter[hash_collection->get_hash(i, s) % size]){
            return false;
        }
    }
    return true;
}
