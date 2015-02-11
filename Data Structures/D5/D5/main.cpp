#include <iostream>
#include "IntQueue.h"
int main(int argc, const char * argv[])
{
    IntQueue myQueue;
    
    myQueue.enqueue(2);
    myQueue.enqueue(4);
    myQueue.enqueue(8);
    myQueue.enqueue(16);
    myQueue.enqueue(32);
    cout << myQueue << endl;
    cout << myQueue.front() << endl;
    cout << myQueue.empty() << endl;
    cout << myQueue.dequeue() << endl;
    cout << myQueue << endl;
    cout << myQueue.dequeue() << endl;
    cout << myQueue.dequeue() << endl;
    cout << myQueue.dequeue() << endl;
    cout << myQueue.dequeue() << endl;
    cout << myQueue.dequeue() << endl;
    return 0;
}

