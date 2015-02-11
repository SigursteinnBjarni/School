#include "ContactList.h"

using namespace std;

ContactList::ContactList()
{
    head = NULL;
}

ContactList::~ContactList()
{
    remove_all();
}

void ContactList::remove_all()
{
    NodePtr temp;
    while (head != NULL) {
        temp = head;
        head = head->link;
        delete temp;
    }
    head = NULL;
}

bool ContactList::add(string key, Contact value)
{
    /*
    NodePtr prev = NULL;
    NodePtr node = head;
	while (node != NULL){
        if (node->data.key == key){
            node->data.value = value;
            return false;
        }
        prev = node;
        node = node->link;
    }
    if (prev == NULL){
        head = new ContactNode(key, value, NULL);
    }
    else{
        prev->link = new ContactNode(key, value, NULL);
    }
    return true;
     */
    
    if (head == NULL){
        head = new ContactNode(key, value, head);
    }
    
    NodePtr curr = head;
    while (curr->link != NULL) {
        if (curr->data.key == key) {
            curr->data.value = value;
            return false;
        }
        curr = curr->link;
    }
    
    NodePtr new_node = new ContactNode(key, value, NULL);
    curr->link = new_node;
    return true;
}

bool ContactList::remove(string key)
{
    if(head == NULL){
        return false;
    }
    NodePtr temp;
    // if the key is the first item in the list
    if(head->data.key == key){
        temp = head;
        head = head -> link;
        delete temp;
        return true;
    }
    else{
        NodePtr current = head;
        //traverse the list
        while (current != NULL){
			temp = current->link;
            if(temp -> data.key == key){
                current->link = temp->link;
                delete temp;
                return true;
            }
			current = current -> link;
        }
    }
    return false;
}

bool ContactList::contains(string key)
{
	NodePtr node = head;
    while (node != NULL) {
        if (node->data.key == key) {
            return true;
        }
        node = node->link;
    }
    return false;
}

Contact ContactList::get(string key)
{
    NodePtr curr = head;
    while (curr != NULL) {
        if (curr->data.key == key) {
            return curr->data.value;
        }
        curr = curr->link;
    }
    throw KeyException();
}

void ContactList::get_contacts(vector<Contact>& contacts)
{
    NodePtr curr = head;
    while (curr != NULL) {
        contacts.push_back(curr->data.value);
        curr = curr->link;
    }
}

void ContactList::get_contacts_by_prefix(string prefix, vector<Contact>& contacts)
{
    NodePtr curr = head;
    while (curr != NULL) {
        if (!curr->data.key.find(prefix)) {
            contacts.push_back(curr->data.value);
        }
        curr = curr->link;
    }
}

vector<StringContactPair> ContactList::to_vector()
{
	vector<StringContactPair> v;
    NodePtr curr = head;
    while (curr != NULL) {
        v.push_back(curr->data);
        curr = curr->link;
    }
    
    return v;
}

ostream& operator <<(ostream& outs, const ContactList& lis)
{
	NodePtr curr = lis.head;
    while (curr != NULL) {
        outs << curr->data.value << " " << endl;
        curr = curr->link;
    }
    return outs;
    
}
