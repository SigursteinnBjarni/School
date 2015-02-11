#include "AlienFamilyTree.h"

AlienFamilyTree::AlienFamilyTree()
{
    head = NULL;
}

AlienFamilyTree::~AlienFamilyTree()
{
    delete_tree(head);
    head = NULL;
}

bool AlienFamilyTree::is_descendant(string name)
{
    // use the find function to find if the name does exist in the tree
    NodePtr descendant_ptr = find(head, name);
    // if the name does not exist we retrun false
    return (descendant_ptr != NULL);
}

bool AlienFamilyTree::is_descendant(string ancestor, string descendant)
{
    // we first search for the ancestor in the tree
    NodePtr ancestor_ptr = find(head, ancestor);
    
    // search for the descendant in the tree, starting from the ancestor
    NodePtr descendant_ptr = find(ancestor_ptr, descendant);
    
    // if the name exists we return true
    return (descendant_ptr != NULL);
}

int AlienFamilyTree::generation(string name)
{
    return generation(head, name);
}

NodePtr AlienFamilyTree::find(NodePtr root, string name)
{
    // if the tree is empty
    if (root == NULL) {
        return NULL;
    }
    // if the root is the name
    if (root->data == name) {
        return root;
    }
    // go to the left of the tree // we have to declare a Nodeptr because of the return value
    NodePtr left = find(root->left, name);
    if (left != NULL) {
        return left;
    }
    // go the right of the tree // we have to declare a Nodeptr because of the return value
    NodePtr right = find(root->right, name);
    return right;
    
}

int AlienFamilyTree::generation(NodePtr root, string name)
{
    // if the root of the tree is the name
    if (root->data == name) {
        return 0;
    }
    // go to the left of the tree // we declare a NodePtr to search for the name
    NodePtr left = find(root->left, name);
    if (left != NULL) {
        // add 1 to the generation // function retrun value is int
        return generation(root->left, name) + 1;
    }
    // go the right of the tree // we declare a NodePtr to search for the name
    NodePtr right = find(root->right, name);
    if (right != NULL){
        // add 1 to the generation // function retrun value is int
        return generation(root->right, name) + 1;
    }
    return -1;
}

void AlienFamilyTree::delete_tree(NodePtr root)
{
    // if the tree is not empty, we delete left tree, right three and then root
    if (root != NULL) {
        delete_tree(root->left);
        delete_tree(root->right);
        delete root;
    }
}

// Helper function that reads a binary tree in from the specified input stream
// and returns the root of the tree.
NodePtr parse_tree(istream& ins)
{
    char c;
    ins >> c; // Read (

    ins >> c; // Read next character

    // If the next character is ), this is the empty tree
    if(c == ')') {
        return NULL;
    }

    // Return the "borrowed" character to the input stream
    ins.putback(c);

    string node_data;
    ins >> node_data;

    NodePtr node = new BinaryStringNode;
    node->data = node_data;
    node->left = parse_tree(ins);
    node->right = parse_tree(ins);

    ins >> c; // Consume the trailing )

    return node;
}

void indent(ostream& outs, int level)
{
    for(int i = 0; i != level * 3; i++) {
        outs << " ";
    }
}

// Helper function that prints the binary tree root to the specified output
// stream.
void print_tree(ostream& outs, NodePtr root, int level = 0)
{
    indent(outs, level);
    if(root == NULL) {
        outs << "()" << endl;
        return;
    }
    outs << "(" << root->data << endl;
    print_tree(outs, root->left, level + 1);
    print_tree(outs, root->right, level + 1);
    indent(outs, level);
    outs << ")" << endl;
}

istream& operator>> (istream& ins, AlienFamilyTree& tree)
{
    tree.head = parse_tree(ins);
    return ins;
}

ostream& operator<< (ostream& outs, const AlienFamilyTree& tree)
{
    print_tree(outs, tree.head);
    return outs;
}

