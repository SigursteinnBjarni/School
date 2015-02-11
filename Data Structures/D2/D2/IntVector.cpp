#include <cmath>
#include "IntVector.h"

using namespace std;

// Constructors

IntVector::IntVector()
{
    count = 0;
    capacity = INITIAL_CAPACITY;
    array = new int[capacity];
}

IntVector::IntVector(int size, int value)
{
    count = 0;
    capacity = size;
    array = new int [capacity];
    // Set the items in the array to value
    for (int i = 0; i < capacity; i++) {
        array[i] = value;
        count++;
    }
}

IntVector::IntVector(const IntVector& vec)
    : count(vec.count), capacity(vec.capacity)
{
    array = new int[capacity];

    for(int i = 0; i < count; i++) {
        array[i] = vec.array[i];
    }
}


IntVector::~IntVector()
{
    delete [] array;
}

 void IntVector::expand_array()
{
    capacity = capacity * 2;
    int* new_array = new int[capacity];
    // move old values into the new array
    for (int i = 0; i < count; i++){
        new_array[i] = array[i];
    }
    // free up the memory and assign our array the new values
    delete [] array;
    array = new_array;
}

bool IntVector::size_check()
{
    return (count == capacity);
}

// Public member functions

void IntVector::push_back(int elem)
{
    if(size_check()){
        expand_array();
    }
    array[count] = elem;
    count++;
}

void IntVector::insert(int index, int elem)
{
    // if the array is full, expand the array
    if (size_check()) {
        expand_array();
    }
    if (index > count || index < 0) {
        throw IndexOutOfRangeException();
    }
    // start from the end of the array and work our way down
    for (int i = count; i != index; i--){
        array[i] = array[i - 1];
    }

    array[index] = elem;
    count++;
}

int IntVector::at(int index) const
{
    if (index >= count || index < 0) {
        throw IndexOutOfRangeException();
    }
    
    return array[index];
}

void IntVector::set_value_at(int index, int elem) const
{
    if (index >= count || index < 0) {
        throw IndexOutOfRangeException();
    }
    
    array[index] = elem;
}

int IntVector::size() const
{
    return count;
}

bool IntVector::empty() const
{
    return (count == 0);
}

void IntVector::remove_at(int index)
{
    if (index >= count || index < 0) {
        throw IndexOutOfRangeException();
    }
    // move items in the array
    for (int i = index; i < count-1; i++){
        array[i] = array[i + 1];
    }
    count--;
}

int IntVector::pop_back()
{
    if (count == 0) {
        throw EmptyException();
    }
    count--;
    return array[count];
}

void IntVector::clear()
{
    count = 0;
    delete [] array;
    array = new int [capacity];
}

// Overloaded operators

void IntVector::operator=(const IntVector& vec)
{
    if(capacity < vec.capacity) {
        delete [] array;
        array = new int[vec.capacity];
    }

    capacity = vec.capacity;
    count = vec.count;

    for(int i = 0; i != count; i++) {
        array[i] = vec.array[i];
    }
}

int& IntVector::operator[] (int index) const
{
    if (index >= count || index < 0) {
        throw IndexOutOfRangeException();
    }
    return array[index];
}

ostream& operator<< (ostream& out, const IntVector& rhs)
{
    for(int i = 0; i < rhs.size(); i++) {
        out << rhs[i] << " ";
    }
    return out;
}
