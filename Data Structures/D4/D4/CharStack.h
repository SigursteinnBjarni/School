//DISPLAY 13.17 Interface File for a CharStack Class
//This is the header file CharStack.h. This is the interface for the class CharStack,
//which is a class for a CharStack of symbols.
#ifndef CHARSTACK_H
#define CHARSTACK_H
#include<iostream>
using namespace std;

struct CharStackFrame {
    char data;
    CharStackFrame *link;
};

typedef CharStackFrame* CharStackFramePtr;

class EmptyStackException {};

class CharStack {
    public:
        CharStack();
        //Initializes the object to an empty CharStack.

        CharStack(const CharStack& aStack);
        //Copy constructor.

        ~CharStack();
        //Destroys the stack and returns all the memory to the freestore.

        void push(char the_symbol);
        //Postcondition: the_symbol has been added to the stack.

        char pop();
        //Returns the top symbol on the stack and removes it from the stack.
		//If the stack is empty, EmptyStackException is thrown.

        char top() const;
        //Returns the top symbol on the stack
		//If the stack is empty, EmptyStackException is thrown.

		// A friend function for writing the contents of aStack
        friend ostream& operator <<(ostream& outs, const CharStack& aStack);

        bool empty( ) const;
        //Returns true if the stack is empty. Returns false otherwise.
    private:
        CharStackFramePtr topPtr;
};

#endif //STACK_H

