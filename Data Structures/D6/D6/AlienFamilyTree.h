#ifndef ALIENFAMILYTREE_H
#define ALIENFAMILYTREE_H

#include "BinaryStringNode.h"
#include <iostream>

using namespace std;

// A class that represents the family tree of a single alien.
// The head of the family is (the root of the family tree) is called T.E.
class AlienFamilyTree
{
    public:
        // Initializes an empty queue.
        AlienFamilyTree();

        // Destructor
        ~AlienFamilyTree();

        // Returns true if and only Gotfather has a descendant named 'name'.
        bool is_descendant(string name);

        // Returns true if and only 'ancestor' has a descendant named
        // 'descendant' in the family tree.
        bool is_descendant(string ancestor, string descendant);

        // Returns a number representing of which generation 'name' is.
        // The generation is specified as follows:
        //     * T.E. is of generation 0.
        //     * If A is of generation n, then all the children of A are of
        //       generation n + 1.
        // If 'name' is not in the family tree, then a value of -1 is returned.
        int generation(string name);

        // Prints the family tree to the specified output stream.
        friend ostream& operator<< (ostream& outs, const AlienFamilyTree& tree);

        // Reads a family tree from the specified input stream.
        friend istream& operator>> (istream& outs, AlienFamilyTree& tree);
    private:
        // T.E.
        NodePtr head;

        // Returns the node pointer for the alien 'name'. If no such alien
        // exists in 'root', then NULL is returned.
		//
		// (You can use this function to help in your implementation of
		// is_descendant).
        NodePtr find(NodePtr root, string name);
    
        int generation(NodePtr root, string name);

        // You can use the following function to aid in your implementation
        // of the generation function above.
        //
        // int generation(NodePtr root, string name, int gen = 0);

        // Frees the memory allocated by root and all of its children.
        void delete_tree(NodePtr root);
};

#endif // ALIENFAMILYTREE_H
