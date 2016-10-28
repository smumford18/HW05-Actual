//
//  main.cpp
//  HW05 Actual
//
//  Created by Steven Mumford on 10/27/16.
//  Copyright © 2016 Steven Mumford. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

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
/*
template <typename T>
class vector{
private:
    int vSize;
    int num;
    T* elements;
public:
    vector<T>()
    {
        vSize = 5;
        for (int i=0; i<vSize; i++) {
            elements[i] = 0;
        }
    }
    
    vector<T> (int size)
    {
        vSize = this->size;
        for(int i=0; i < vSize; i++)
            elements[i]=0;
    }
    
    vector<T> (int size, T defaultVal)
    {
        vSize = this->size;
        for(int i=0; i < vSize; i++)
            elements[i] = defaultVal;
    }
    
    void ensureCapacity()
    {
        if(num >= vSize)
        {
            T *old = elements;
            vSize = 2 * num;
            elements = new T[vSize];
            for (int i = 0; i < num; i++)
                elements[i] = old[i];
            delete [] old;
    }

    }
    void push_back(T element)
    {
        ensureCapacity();
        elements[num] = element;
        num++;
    }
    
    void pop_back()
    {
        return elements[num-1];
    }
    
    unsigned const size()
    {
        return vSize;
    }
    
    T const at(int index)
    {
        for(int i=0; i<vSize; i++)
        {
            if(elements[i] == elements[index])
                return elements[i];
        }
    }
    
    bool const empty()
    {
        bool empty = false;
        for(int i=0; i<vSize;i++)
            if(elements[i]==NULL)
                empty = true;
    }
    
    void clear()
    {
        for(int i=0; i<vSize;i++)
            elements[i]==NULL;
        
    }
    
    void swap(vector &v2)
    {
        vSize= v2.vSize;
        for(int i=0; i<vSize;i++)
            elements[i]== v2.elements[i];
    }
};*/

template <typename T>
void shuffle(vector<T>& v)
{
    srand((unsigned int)time(NULL));
    for(int i=0; i<v.size(); i++)
    {
        int index = rand() % v.size();
        for(int j=0; j<v.size(); j++)
        {
            if(v[index] != v[index+j])
            {
                v[i] = v[index];
            }
        }
    }
}

int main() {
    
// Problem 11.2
    int intList[] = { 1, 2, 4, 5, 6, 9};
    double doubleList[] = {1.1, 5.4, 6.0, 7.8, 9.0, 3.3};
    string stringList[] = {"Hi", "Hello", "Hey", "Greetings", "Bonjour", "Hola"};
    
    cout << "The index of the element is " << linearSearch(intList, 5, 6) << endl;
    cout << "The index of the element is " << linearSearch(doubleList, 1.1, 6) << endl;
    cout << "The index of the element is " << linearSearch(stringList, string("Hello"), 6) << endl;
    cout << endl;
  
// Problem 11.4
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
    cout << endl;
    
//Problem 11.20
    vector<int> nums(6);
    for(int i=0; i<nums.size(); i++)
        nums[i] = i;
    for(int i=0; i<nums.size(); i++)
        cout<< nums[i] << " ";
    cout << endl;
    shuffle(nums);
    for(int i=0; i<nums.size(); i++)
        cout<< nums[i] << " ";
    
    return 0;
    
}

