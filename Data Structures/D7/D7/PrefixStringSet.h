#ifndef STRINGSET_H
#define STRINGSET_H

#include <string>
#include "TrieNode.h"

using namespace std;

// Prefix-aware set of strings.
// An implementation of the ADT set for strings with additional features
// related to prefixes. Implemented using a trie.
class PrefixStringSet
{
    public:
        // Creates an empty prefix string set.
        PrefixStringSet();

        ~PrefixStringSet();

        // Inserts the specified string into the set.
        // Returns true if one of the following holds
        // * 's' is a prefix of a string that was present in the set before the insertion,
        // * a prefix of 's' was present in the set before the insertion.
        bool insert(string s);

        // OPTIONAL (not needed for the assignment)
        // Remove the specified string from the set.
        void remove(string s);

        // OPTIONAL (not needed for the assignment)
        // Returns true if and only if the specified string is contained in the
        // set.
        bool contains(string s);

    private:
        NodePtr root;

        // Deallocates the memory allocated for the trie.
        void remove_all(NodePtr node);
};

#endif
