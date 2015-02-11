#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include "StringSet.h"

using namespace std;
int main(int argc, const char * argv[])
{
    StringSet visited;
    string countries;
    
    cin >> countries;
    while (countries != "#") {
        if (countries == "not") {
            cin >> countries;
            visited.remove(countries);
        }
        else{
            visited.insert(countries);
        }
        cin >> countries;
        
    }
    cout << visited.size() << endl;
    cout << visited << endl;
}