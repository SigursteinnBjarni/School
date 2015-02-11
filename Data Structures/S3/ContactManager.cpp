#include "ContactManager.h"

void ContactManager::add(Contact contact)
{
    phone_map.add(contact.phone, contact);
    name_map.add(contact.name, contact);
}

void ContactManager::remove(string name)
{
    if (!name_exists(name)) {
        return;
    }
    Contact c = name_map.get(name);
    name_map.remove(name);
    phone_map.remove(c.phone);
    
}

void ContactManager::update_phone(string name, string new_number)
{
    // got this wierd error here, i had to use !name_exists to get it to work,
    // if(name_exists) - this did not work, don't know why
	if (! name_exists(name)) {
        throw ContactMissingException();
    }
    // get the contacts name
    Contact c = name_map.get(name);
    //remove the name from the phone map
    phone_map.remove(c.phone);
    // input the new number
    c.phone = new_number;
    // update the phone in the name map
    name_map.add(name, c);
    // update the phone in the phone map
    phone_map.add(c.phone, c);
}

void ContactManager::update_email(string name, string new_email)
{
    // got this wierd error here, i had to use !name_exists to get it to work,
    // if(name_exists) - this did not work, don't know why
    if (!name_exists(name)) {
        throw ContactMissingException();
    }
    // get the contacts name
    Contact c = name_map.get(name);
    // update the email
    c.email = new_email;
    // update the email in the name map
    name_map.add(c.name, c);
    // update the email in the phone map
    phone_map.add(c.phone, c);
    
}

bool ContactManager::name_exists(string name)
{
    return name_map.contains(name);
}

bool ContactManager::phone_exists(string phone)
{
    return phone_map.contains(phone);
}

Contact ContactManager::get_contact_by_name(string name)
{
    if (name_map.contains(name)){
        return name_map.get(name);
    }
    throw ContactMissingException();
}

Contact ContactManager::get_contact_by_phone(string phone)
{
    if (phone_map.contains(phone)){
        return phone_map.get(phone);
    }
    
    throw ContactMissingException();
}

vector<Contact> ContactManager::get_contacts_by_name_prefix(string name_prefix)
{
    return name_map.prefix_search(name_prefix);
}

vector<Contact> ContactManager::get_contacts_by_phone_prefix(string phone_prefix)
{
    return phone_map.prefix_search(phone_prefix);
}

ostream& operator<< (ostream& out, ContactManager& manager)
{
	out << manager.name_map << endl << endl;
	out << manager.phone_map;
	return out;
}
