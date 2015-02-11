#include "StringContactMap.h"
#include "Hash.h"

#include <algorithm>

using namespace std;

StringContactMap::StringContactMap(int initial_capacity)
{
    map = new ListPtr[initial_capacity];
    count = 0;
    capacity = initial_capacity;
    for (int i = 0; i < capacity; i++) {
        map[i] = new ContactList();
    }
}

StringContactMap::~StringContactMap()
{
    for (int i = 0; i < capacity; i++) {
        delete map[i];
    }
    
    delete [] map;
}

void StringContactMap::load_check()
{
    // 25/50 = 2 and is >= 2 so we need to rebuild
    if ((count / capacity) >= MAX_LOAD) {
        rebuild();
    }
}

void StringContactMap::rebuild()
{
    // copy the old values and reset the variables
    int old_capacity = capacity;
    ListPtr* old_map = map;
    count = 0;
    capacity *= 2;
    
    // create a new map with double the capacity
    map = new ListPtr[capacity];
    for (int i = 0; i < capacity; i++) {
        map[i] = new ContactList();
    }
    // add the old values back in the map
    for (int i = 0; i < old_capacity; i++) {
        // create a vector so we can copy the old values into the new map
        vector<StringContactPair> v;
        v = old_map[i]->to_vector();
        for (size_t j = 0; j < v.size(); j++) {
            add(v[j].key, v[j].value);
        }
            
        delete old_map[i];
    }
    delete [] old_map;
}

int StringContactMap::size() const
{
	return count;
}

bool StringContactMap::empty() const
{
	return (count == 0);
}

vector<Contact> StringContactMap::all_contacts() const
{
	vector<Contact> v;
    for (int i = 0; i < capacity; i++) {
        if (map[i] != NULL) {
            map[i]->get_contacts(v);
        }
    }
    
    return v;
}

void StringContactMap::add(string key, Contact value)
{
    load_check();
    int pos = hash_func(key) % capacity;
    // if the key already is in the map, we update else we add new value and inc size
    if (map[pos]->add(key, value)) {
        count ++;
    }
}

void StringContactMap::remove(string key)
{
    int pos = hash_func(key) % capacity;
    if(map[pos]->remove(key)){
        count --;
    }

}

bool StringContactMap::contains(string key) const
{
	int pos = hash_func(key) % capacity;
    if (map[pos]->contains(key)) {
        return true;
    }
    
    return false;
}

Contact StringContactMap::get(string key) const
{
	int pos = hash_func(key) % capacity;
    return map[pos]->get(key);
}

vector<Contact> StringContactMap::prefix_search(string prefix) const
{
	vector<Contact> v;
    for (int i = 0; i < capacity; i++) {
        map[i]->get_contacts_by_prefix(prefix, v);
    }
    
    return v;
}

// Optionally implement.
ostream& operator <<(ostream& out, const StringContactMap& map)
{
    
	for (int i = 0; i < map.capacity; i++){
        out << map.map[i];
    }
    return out;
}

