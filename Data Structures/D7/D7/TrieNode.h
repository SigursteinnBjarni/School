#ifndef TRIENODE_H
#define TRIENODE_H

// We only need to consider the character from '0'--'9'.
const int ALPHABET_SIZE = 10;

// Returns the index associated with the specified character in the children
// array of the TrieNode class.
int get_index(char c);

struct TrieNode
{
    TrieNode(bool present = false);
    bool is_leaf();

    bool present;
    TrieNode* children[ALPHABET_SIZE];
};

typedef TrieNode* NodePtr;

#endif
