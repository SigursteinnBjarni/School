#include <iostream>
#include "HashCollection.h"
#include "BloomFilter.h"
#include <string>
#include <cmath>

using namespace std;
int main(int argc, const char * argv[])
{
    string site = "";
    int number_of_sites = 0;
    
    cin >> number_of_sites;
    
    // vill fa 10 bita fyrir hvert item
    int number_of_hash_functions = 13*0.7;
    int array_size = - ceil((number_of_sites * log(0.01))*10);
    
    BloomFilter bloomy(array_size, number_of_hash_functions);
    for (int i = 0; i < number_of_sites; i++)
    {
        cin >> site;
        bloomy.add(site);
        
    }
    
    int check_sites = 0;
    string sites_to_check = "";
    cin >> check_sites;
    for (int i = 0; i < check_sites; i++)
    {
        cin >> sites_to_check;
        if(bloomy.contains(sites_to_check))
        {
            cout << "Possibly bad" << endl;
        }
        else
        {
            cout << "OK" << endl;
        }
    }
    
    return 0;
}

