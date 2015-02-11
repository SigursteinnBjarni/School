#include "PrefixStringSet.h"

PrefixStringSet::PrefixStringSet()
{
    root = new TrieNode();
}

PrefixStringSet::~PrefixStringSet()
{
    remove_all(root);
}

bool PrefixStringSet::insert(string s)
{
    NodePtr node = root;
    bool is_prefix = false;
    for (size_t i = 0; i < s.size(); i++) {
        // if there is a tick we have a prefix
        if (node->present) {
            is_prefix = true;
        }
        // insert the new letter
        int index = get_index(s[i]);
        if (node->children[index] == NULL) {
            node->children[index] = new TrieNode();
        }
        // traverse the index
        node = node->children[index];
    }
    bool has_prefix = contains(s);
    // add the new tick and return if we have prefix or not
    node->present = true;
    // checking if any of the indexes has a tick in it
    return is_prefix || has_prefix;
}

void PrefixStringSet::remove(string s)
{
    NodePtr node = root;
    for (size_t i = 0; i < s.size(); i++) {
        // get the index of the character
        int index = get_index(s[i]);
        // if the position is empty, we do nothing
        if (node->children[index] == NULL) {
            return;
        }
        // move to the next character
        node = node->children[index];
    }
    // remove the tick
    node->present = false;
}

bool PrefixStringSet::contains(string s)
{
    NodePtr node = root;
    for (size_t i = 0; i < s.size(); i++) {
        // get the index of the character
        int index = get_index(s[i]);
        // if there is nothing in the position
        if (node->children[index] == NULL) {
            return false;
            }
        }
    // return true if it is present
    return node->present;
}

void PrefixStringSet::remove_all(NodePtr node)
{
    if (node != NULL) {
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            remove_all(node->children[i]);
        }
    }
    delete node;
}
