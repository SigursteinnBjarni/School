#include "TrieNode.h"

#include <cctype>
#include <cstddef>
#include <cassert>

int get_index(char c)
{
    int ind = tolower(c) - '0';
    assert(0 <= ind && ind < ALPHABET_SIZE);
    return ind;
}

TrieNode::TrieNode(bool present)
{
    this->present = present;
    for(int i = 0; i < ALPHABET_SIZE; i++) {
        children[i] = NULL;
    }
}

bool TrieNode::is_leaf()
{
    for(int i = 0; i < ALPHABET_SIZE; i++) {
        if(children[i] != NULL) {
            return false;
        }
    }
    return true;
}
