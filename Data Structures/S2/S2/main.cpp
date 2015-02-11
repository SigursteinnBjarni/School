#include <iostream>
#include <string>
#include <assert.h>
#include "HuffmanNode.h"
#include "HuffmanPriorityQueue.h"

using namespace std;

const int INDENT_SIZE = 2;

// Prints the Huffman tree 'root' to the standard output, indented by 'indent' spaces.
// The printed tree is labeled (i.e., prefixed) by the string 'prefix'.
void print_tree(NodePtr root, int indent = 0, string prefix = "")
{
    // External nodes are not printed.
    if(root == NULL) {
        return;
    }

    char letter = ' ';
    if(root->is_leaf()) {
        letter = root->letter;
    }

    cout << string(indent, ' ') << prefix << "(" << letter << " [" << root->frequency << "]";
    if(root->is_leaf()) {
        cout << ")" << endl;
    } else {
        cout << endl;
        // Print left and right subtrees with the appropriate prefix, and
        // increased indent (by INDENT_SIZE).
        print_tree(root->left, indent + INDENT_SIZE, "0");
        print_tree(root->right, indent + INDENT_SIZE, "1");
        cout << string(indent, ' ') << ")" << endl;
    }
}

// Reads a frequency table from standard input, builds the Huffman tree for that frequency table and
// returns (a pointer to the root of) the tree.
NodePtr build_tree()
{
    HuffmanPriorityQueue myQueue;
    int freq, input_lenght;
    char letter;
    cin >> input_lenght;
    for (int i = 0; i < input_lenght; i++) {
        cin >> letter >> freq;
        NodePtr new_node = new HuffmanNode(freq, letter); // create the new node
        myQueue.push(new_node);                           // push the newly created node to the stack
    }
    
    NodePtr HuffmanTree = NULL;
    for (int i = 0; i < input_lenght -1; i++) {
        NodePtr a = myQueue.top();
        myQueue.pop();
        NodePtr b = myQueue.top();
        myQueue.pop();
        HuffmanTree = new HuffmanNode(a->frequency + b->frequency, '\0');
        HuffmanTree->left = a;  // left children
        HuffmanTree->right = b; // right children
        myQueue.push(HuffmanTree);
    }
    
    return HuffmanTree;
}

// Returns the string obtained by decoding 'encoded_str' with the Huffman tree 'root' (or more
// specifically, the Huffman tree whose root is 'root').
string decode(NodePtr root, string encoded_str)
{
    string decoded_string;
    char filter;
    NodePtr temp = root;
    
    for (size_t i = 0; i < encoded_str.size(); i++) {
        filter = encoded_str[i];

        // if the first char is '0' we to the left and if we hit leaf we add the letter to the string
        if (filter == '0') {
            temp = temp->left;
        }
        // if the first char is '1' we to the right and if we hit leaf we add the letter to the string
        else{
            temp = temp->right;
        }
        // if we reach a leaf it means we are at the bottom and we have found our letter
        if (temp->is_leaf()){
            decoded_string += temp->letter;
            temp = root;
        }
    }
    return decoded_string;
}

// * Optional, but recommended *
// Returns true if and only if the tree 'root', contains the node with the letter 'letter'.
bool contains(NodePtr root, char letter)
{
    if (root == NULL) {
        return false;
    }
    if (root->letter == letter) {
        return true;
    }
    else if(contains(root->left, letter)){
        return true;
    }
    else{
        return contains(root->right, letter);
    }

}

// Returns the binary code obtained by encoding 'letter' with the Huffman tree 'root' (or more
// specifically, the Huffman tree whose root is 'root').
string encode(NodePtr root, char letter)
{
    string encoded_string;
    NodePtr temp = root;
    
    // we continue down the tree until we hit a leaf
    while (! temp -> is_leaf()){
        if (contains(temp -> left, letter)){      // adds 0 to the string if we go to the left
            temp = temp -> left;
            encoded_string += "0";
        }
        else if (contains(temp -> right, letter)){ // adds 1 to the string if we go the right
            temp = temp -> right;
            encoded_string += "1";
        }
    }
    return encoded_string;
}

// Frees (deallocates) the memory allocated for the Huffman tree 'root' (or more
// specifically, the Huffman tree whose root is 'root').
void free_memory(NodePtr root)
{
    if (root != NULL) {
        free_memory(root->left);
        free_memory(root->right);
        delete root;
    }
}

int main()
{
    // Read frequency table and build Huffman tree.
    NodePtr huffman = build_tree();
    //print_tree(huffman);
  /*
    int lenght;
    cin >> lenght;
    for (int i = 0; i < lenght; i++) {
        string string_to_decode;
        cin >> string_to_decode;
        cout << decode(huffman, string_to_decode) << endl;
    }
   */
    int lenght2;
    cin >> lenght2;
    for (int i = 0; i < lenght2; i++)
    {
        string str;
        cin >> str;
        for (size_t j = 0; j < str.size(); j++)
        {
            cout << encode(huffman, str[j]);
        }
        cout << endl;
        
    }
    // Free the allocated memory.
    free_memory(huffman);

    return 0;
}

