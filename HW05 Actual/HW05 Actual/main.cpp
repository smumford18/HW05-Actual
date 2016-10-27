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
T linearSearch(const T list[], T key, int arraysize);

int main() {
    
    int intList[] = { 1, 2, 5, 4, 6, 9};
    double doubleList[] = {1.1, 5.4, 6.0, 7.8, 9.0, 3.3};
    string stringList[] = {"Hi", "Hello", "Hey", "Greetings", "Bonjour", "Hola"};
    
    cout << "The index of the element is" << linearSearch(intList, 5, 6) << endl;
    cout << "The index of the element is" << linearSearch(doubleList, 1.1, 6) << endl;
    cout << linearSearch(stringList, string("Hello"), 6) << endl;
    
    return 0;
}

template <typename T>
T linearSearch(const T list[], T key, int arraysize)
{
    for(int i=0; i < arraysize; i++)
        if(key == list[i])
            return i;
    return -1;
}
