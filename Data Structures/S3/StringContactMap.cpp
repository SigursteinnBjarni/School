#include "StringContactMap.h"

using namespace std;

StringContactMap::StringContactMap ()
{
	root = NULL;
}

StringContactMap::~StringContactMap()
{
	free_memory(root);
}

int StringContactMap::size() const
{
	return size_helper(root);
}

bool StringContactMap::empty() const
{
	return root == NULL;
}

vector<Contact> StringContactMap::all_contacts() const
{
    vector<Contact> v;
    all_contacts(root, v);
    return v;
}

void StringContactMap::add(string key, Contact value)
{
	add(root, key, value);
}

void StringContactMap::remove(string key)
{
	remove(root, key);
}

bool StringContactMap::contains(string key) const
{
    return contains(root, key);
}

Contact StringContactMap::get(string key) const
{
    return get(root, key);
}


vector<Contact> StringContactMap::prefix_search(string prefix) const
{
    vector<Contact> c;
    prefix_search(root, prefix, c);
    return c;
}

void StringContactMap::free_memory(NodePtr node)
{
    if(node != NULL){
        free_memory(node->left);
        free_memory(node->right);
        delete node;
    }
}

int StringContactMap::size_helper(NodePtr node) const
{
    if (node == NULL) {
        return 0;
    }
    int count;
    count = size_helper(node->left) + size_helper(node->right) + 1;
    return count;
}

void StringContactMap::all_contacts(NodePtr node, vector<Contact>& v) const
{
    if (node == NULL) {
        return;
    }
    
    all_contacts(node->left, v);
    v.push_back(node->value);
    all_contacts(node->right, v);
}

void StringContactMap::add(NodePtr& node, string key, Contact value)
{
    if (node == NULL){
        node = new ContactNode(key, value);
    }
    else if (key < node->key){
        add(node->left, key, value);
    }
    else if(key > node->key){
        add(node->right, key, value);
    }
    else{
        node->value = value;
    }
}

Contact StringContactMap::get(NodePtr node, string key) const
{
    if (node == NULL) {
        throw KeyException();
    }
    
    if (node->key == key) {
        return node->value;
    }
    else if (key < node->key){
        return get(node->left, key);
    }
    else{
        return get(node->right, key);
    }
}

bool StringContactMap::contains(NodePtr node, string key) const
{
    if (node == NULL) {
        return false;
    }
    
    if (node->key == key) {
        return true;
    }
    
    else if (key < node->key){
        return contains(node->left, key);
    }
    
    return contains(node->right, key);
}

void StringContactMap::remove(NodePtr& node, string key)
{
	if(node == NULL) {
		return;
	} else if(node->key == key) {
		remove_root(node);
	} else if(key < node->key) {
		remove(node->left, key);
	} else {
		remove(node->right, key);
	}
}

void StringContactMap::remove_root(NodePtr& root)
{
	NodePtr succ;
	if(root->is_leaf()) {
		delete root;
		root = NULL;
	} else if(root->left == NULL) {
		succ = root->right;
		delete root;
		root = succ;
	} else if(root->right == NULL) {
		succ = root->left;
		delete root;
		root = succ;
	} else {
		NodePtr new_root = remove_min(root->right);
		new_root->left = root->left;
		new_root->right = root->right;
		delete root;
		root = new_root;
	}
}

NodePtr StringContactMap::remove_min(NodePtr& node)
{
	if(node->left == NULL) {
		NodePtr old_node = node;
		node = node->right;
		return old_node;
	} else {
		return remove_min(node->left);
	}
}

void StringContactMap::prefix_search(NodePtr node, string prefix, vector<Contact>& v) const
{
    if(node == NULL){
        return;
    }
    // use substring to get all the letters in our string // from the first to the last letter
    string node_prefix = node->key.substr(0, prefix.size());
    // inorder prefix traversal
    if (prefix <= node_prefix){
        prefix_search(node->left, prefix, v);
    }
    if(prefix == node_prefix){
        v.push_back(node->value);
    }
    if (prefix >= node_prefix) {
        prefix_search(node->right, prefix, v);
    }
}

ostream& operator <<(ostream& out, const StringContactMap& map)
{
	vector<Contact> contacts = map.all_contacts();

	for(size_t i = 0; i < contacts.size(); i++) {
		out << contacts[i] << endl;
	}
	return out;
}

