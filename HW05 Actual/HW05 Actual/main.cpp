//
//  main.cpp
//  HW05 Actual
//
//  Created by Steven Mumford on 10/27/16.
//  Copyright © 2016 Steven Mumford. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

template <typename T>
int linearSearch(const T list[], T key, int arraysize)
{
    for(int i=0; i < arraysize; i++)
        if(key == list[i])
            return i;
    return -1;
}

template <typename T>
bool isSorted(const T list[], int size)
{
    bool sorted = true;
    for(int i=0; i < size; i++)
    {
        if(list[i] > list[i+1])
        {
            sorted = false;
            break;
        }
    }
    
    return sorted;
}

int main() {
    
    int intList[] = { 1, 2, 4, 5, 6, 9};
    double doubleList[] = {1.1, 5.4, 6.0, 7.8, 9.0, 3.3};
    string stringList[] = {"Hi", "Hello", "Hey", "Greetings", "Bonjour", "Hola"};
    
    cout << "The index of the element is " << linearSearch(intList, 5, 6) << endl;
    cout << "The index of the element is " << linearSearch(doubleList, 1.1, 6) << endl;
    cout << "The index of the element is " << linearSearch(stringList, string("Hello"), 6) << endl;
    cout << endl;
    
    if(isSorted(intList, 6) == true)
        cout << "The list of integers is sorted" << endl;
    else
        cout << "The list of integers is not sorted" << endl;
    
    if(isSorted(doubleList, 6)== true)
        cout << "The list of doubles is sorted" << endl;
    else
        cout << "The list of doubles is not sorted" << endl;
    
    if(isSorted(stringList, 6) == true)
        cout << "The list of strings is sorted" << endl;
    else
        cout << "The list of strings is not sorted" << endl;
    
    
    return 0;
    
}

