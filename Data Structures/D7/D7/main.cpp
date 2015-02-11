#include <iostream>
#include "PrefixStringSet.h"
#include <cstdio>
using namespace std;

int main(int argc, const char * argv[])
{
    PrefixStringSet set;
    
    //freopen("input1.txt", "r", stdin);
    int numberOfTests;
    cin >> numberOfTests;
    while (numberOfTests != 0) {
    
        int times;
        cin >> times;
        bool bit = false;
        for (int i = 0; i < times; i++)
        {
            string phone_number;
            cin >> phone_number;
            if(set.insert(phone_number))
            {
                bit = true;
                //cout << "NO" << endl;
                //return 0;
            }
        
        }
        if(bit){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
        
        numberOfTests --;
    }
    return 0;
}

