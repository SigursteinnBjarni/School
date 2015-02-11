#include <iostream>
#include "CharStack.h"
using namespace std;

bool matching_brackets(char closing, char opening)
{
    // in this function we check if we have matching brackets
    if (opening == '(' && closing == ')') {
        return true;
    }
    else if (opening == '{' && closing == '}') {
        return true;
    }
    else if (opening == '[' && closing == ']') {
        return true;

    }
    return false;
}


bool safe_to_publish(string book)
{
    CharStack myBook;
    char opening, closing;
    
    for (size_t i = 0; i < book.size(); i++) {
        opening = book[i];
        // if the bracet is opening we push it onto the stack
        if (opening == '(' || opening == '[' || opening == '{') {
            myBook.push(opening);
        }
        
        else{
            // if our stack is empty it means we have no opening bracets
            if (myBook.empty()) {
                return false;
            }
            // if the brackets do not match we return false
            closing = myBook.top();
            if(!matching_brackets(opening, closing)){
                return false;
            }
            // we take the closing bracet and we pop it out of the stack
            else{
                myBook.pop();
            }
        }
        
    }
    // if the stack is empty we have balanced brackets or the stack is not empty
    return myBook.empty();
}

int main(int argc, const char * argv[])
{
    string brackets;
    cin >> brackets;
    if (safe_to_publish(brackets)){
        cout << "Publish!" << endl;
    }
    else{
        cout << "Fix brackets" << endl;
    }
    
    return 0;
}

