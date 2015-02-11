//DISPLAY 13.19 Implementation of the CharStack Class
//This is the implementation file CharStack.cpp.
//The interface for the class CharStack is in the header file CharStack.h.
#include <iostream>
#include <cstdlib>
#include "CharStack.h"

using namespace std;

CharStack::CharStack( ) : topPtr(NULL) {
        //Body intentionally empty.
}

CharStack::CharStack(const CharStack& aStack) {
    CharStackFramePtr newFramePtr;

    if (aStack.empty()) {
        // Create an empty stack
        topPtr = NULL;
    } else {
    // we have at least one stack frame on the stack; make a copy of it

        topPtr = new CharStackFrame;
        // Copy the data field; the link field will be set below
        topPtr->data = (aStack.topPtr)->data;

        newFramePtr = topPtr;
        for (CharStackFramePtr originalPtr = (aStack.topPtr)->link;
                originalPtr != NULL;
                originalPtr = originalPtr->link)
        {
            // The link of the previous frame now points to the new frame
            newFramePtr->link = new CharStackFrame;
            // Move to the new frame
            newFramePtr = newFramePtr->link;
            // Copy the data file
            newFramePtr->data = originalPtr->data;
        }
        // And finally make sure that the final (bottom) frame points to NULL
        newFramePtr->link = NULL;
    }
}

CharStack::~CharStack( ) {
    while (!empty()) {
        pop( ); //pop calls delete.
    }
}

bool CharStack::empty() const {
    return (topPtr == NULL);
}

void CharStack::push(char the_symbol) {
    CharStackFramePtr newFrame;

    newFrame = new CharStackFrame;
    newFrame->data = the_symbol;
    newFrame->link = topPtr;

    topPtr = newFrame;
}


char CharStack::pop() {
    if (empty()) {
        throw EmptyStackException();
    }

    char result = topPtr->data;

    CharStackFramePtr temp_ptr;
    temp_ptr = topPtr;
    topPtr = topPtr->link;

    delete temp_ptr;
    return result;
}

char CharStack::top() const {
    if (empty()) {
        throw EmptyStackException();
    }
    return topPtr->data;
}

ostream& operator <<(ostream& outs, const CharStack& aStack) {
    for (CharStackFramePtr iter = aStack.topPtr; iter != NULL; iter = iter->link) {
            outs << (iter->data);
    }
    outs << endl;
    return outs;
}
