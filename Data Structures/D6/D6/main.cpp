#include <iostream>
#include "AlienFamilyTree.h"

using namespace std;

void in_family_query(AlienFamilyTree& ft, string name)
{
    cout << name << " is ";
    if(!ft.is_descendant(name)) {
        cout << "not ";
    }
    cout << "in the family" << endl;
}

void descendant_query(AlienFamilyTree& ft, string ancestor, string descendant)
{
    cout << descendant << " is ";
    if(!ft.is_descendant(ancestor, descendant)) {
        cout << "not ";
    }
    cout << "the descendant of " << ancestor << endl;
}


void generation_query(AlienFamilyTree& ft, string name)
{
    int gen = ft.generation(name);
    if(gen < 0) {
        cout << name << " is not in the family" << endl;
    } else {
        cout << name << " is of generation " << gen << endl;
    }

}

void answer_query(AlienFamilyTree& ft)
{
    string query_string;
    string name1, name2;

    cin >> query_string;
    if(query_string == "in_family") {
        cin >> name1;
        in_family_query(ft, name1);
    } else if (query_string == "descendant") {
        cin >> name1 >> name2;
        descendant_query(ft, name1, name2);
    } else if (query_string == "generation") {
        cin >> name1;
        generation_query(ft, name1);
    }
}

int main()
{
    freopen("input", "r", stdin);
    AlienFamilyTree ft;
    cin >> ft;

    int queries;

    cin >> queries;
    for(int i = 0; i < queries; i++) {
        answer_query(ft);
    }

    return 0;
}
