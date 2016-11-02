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

// Function of variable type that finds a specified item in an array of variable type
template <typename T>
int linearSearch(const T list[], T key, int arraysize)
{
    for(int i=0; i < arraysize; i++)
        if(key == list[i])
            return i;
    return -1;
}

// Function of variable type that checks to see if an array of variable type is sorted or not
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

// Class that defines a vector
// Unable to complete, for the rest of the assignment, the built in vector class is used
/*
template <typename T>
class vector{
private:
    int vSize;
    int nums;
    T* elements;
    
public:
    vector<T>()
    {
        T *vec = new T[vSize];
        for(int i=0;i < vSize; i++)
            vec[i]=0;
    }
    
    vector<T> (int size)
    {
        T *vec = new T[size];
        for(int i=0; i < vSize; i++)
            vec[i]=0;
    }
    
    vector<T> (int size, T defaultVal)
    {
        vSize = size;
        for(int i=0; i < vSize; i++)
            elements[i] = defaultVal;
    }
    
    void ensureCapacity()
    {
        if(nums >= vSize)
        {
            T *old = elements;
            vSize = 2 * nums;
            elements = new T[vSize];
            for (int i = 0; i < nums; i++)
                elements[i] = old[i];
            delete [] old;
    }

    }
    void push_back(T element)
    {
        ensureCapacity();
        elements[nums] = element;
        nums++;
    }
    
    void pop_back()
    {
        return elements[nums-1];
    }
    
    unsigned const size()
    {
        return vSize;
    }
    
    const T at(int index)
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
};
*/

// Function of variable type that shuffles a vector
template <typename T>
void shuffle(vector<T>& v)
{
    srand((unsigned int)time(NULL));
    for(int i=0; i<v.size(); i++)
    {
        int index = rand() % v.size();
        T temp = v[index];
        v[index]=v[i];
        v[i]=temp;
    }
}

// Class that defines a date
class Date
{
private:
    int year;
    int month;
    int day;
public:
    // No arg constructor for date
    Date()
    {
        year = 2000;
        month = 1;
        day = 1;
    }
    // Constructor for date
    Date(int YEAR, int MONTH, int DAY)
    {
        year = YEAR;
        month = MONTH;
        day = DAY;
    }
};

// Transaction class that allows for a deposit or withdrawel to be made from an account
class Transaction
{
private:
    Date date;
    char type;
    double amount;
    double balance;
    string description;
    
public:
    // Constructor for a transaction
    Transaction(char TYPE, double AMOUNT, double BALANCE, string DESCRIPTION)
    {
        type = TYPE;
        amount = AMOUNT;
        balance = BALANCE;
        description = DESCRIPTION;
    }
    // Function that outputs the type of the transaction
    void printType() const
    {
        cout << type << " ";
    }
    // Function that outputs the amount of the transaction
    void printAmount() const
    {
        cout << amount << " ";
    }
    // Function that outputs the balance of the account after the transaction
    void printBalance() const
    {
        cout << balance << " ";
    }
    // Function that outputs the description of the transaction
    void printDescription() const
    {
        cout << description << " ";
    }
};

class Account
{
private:
    vector<Transaction> transactions;
    int id;
    double balance;
    double annualInterestRate;
    string name;
    int numOfTransactions;
    
public:
    // Constructor for an account
    Account(int ID, double startBalance, double startInterestRate)
    {
        id = ID;
        balance = startBalance;
        annualInterestRate = startInterestRate;
        numOfTransactions =0;
    }
    // Constructor for an account that has a name
    Account(string NAME, int ID, double startBalance, double startInterestRate)
    {
        name = NAME;
        id = ID;
        balance = startBalance;
        annualInterestRate = startInterestRate;
        numOfTransactions =0;
    }
    // Getter function for the name
    string getName()
    {
        return name;
    }
    // Getter function for the ID of the account
    int getID()
    {
        return id;
    }
    // Getter function for the balance of the account
    double getBalance()
    {
        return balance;
    }
    // Getter function for the interest rate of the account
    double getInterestRate()
    {
        return annualInterestRate;
    }
    // Getter funciton for the number of transaction that the account has had
    int getNumOfTransactions()
    {
        return numOfTransactions;
    }
    // Setter function for the ID of the account
    void setID(int newID)
    {
        id = newID;
    }
    // Setter function for the balance of the account
    void setBalance(double newBalance)
    {
        balance = newBalance;
    }
    // Setter function for the interest rate of the account
    void setInterestRate(double newInterestRate)
    {
        annualInterestRate = newInterestRate;
    }
    // Getter function for the monthly interest of the account
    double getMonthlyInterestRate()
    {
        double monthlyRate = annualInterestRate/12;
        return monthlyRate;
    }
    // Function that allows for a withdrawel to be made from the account
    void withdraw(double withdrawalAmount)
    {
        //double change = balance - amount;
        balance -= withdrawalAmount;
        numOfTransactions++;
        transactions.push_back(Transaction('W', withdrawalAmount, balance, "Withdraw"));
    }
    // Function that allows for a deposit to be made into the account
    void deposit(double depositAmount)
    {
        balance += depositAmount;
        numOfTransactions++;
        transactions.push_back(Transaction('D', depositAmount, balance, "Deposit"));
    }
    // Function that outputs the transaction history of the account
    void printTransactions()
    {
        for(int i=0; i<numOfTransactions; i++)
        {
            cout << "Transaction number " << i+1 << endl;
            cout << "Transaction type: ";
            transactions.at(i).printType();
            cout << "\nTransaction amount: ";
            transactions.at(i).printAmount();
            cout << "\nAccount balance: ";
            transactions.at(i).printBalance();
            cout <<"\nTransaction Description ";
            transactions.at(i).printDescription();
            cout << "\n\n";
        }
    }
};
    
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
    vector<int> nums(10);
    //cout << "Enter 10 integers: ";
    for(int i=0; i < nums.size(); i++)
        nums[i] = i;
    for(int i=0; i < nums.size(); i++)
        cout << nums[i] << " ";
    cout << endl;
    shuffle(nums);
    for(int i=0; i < nums.size(); i++)
        cout<< nums[i] << " ";
    cout << "\n\n";

//Problem 11.25
    Account Acc1("George", 1122, 1000.00, 1.5);
    Acc1.deposit(30.00);
    Acc1.deposit(40.00);
    Acc1.deposit(50.00);
    Acc1.withdraw(5.00);
    Acc1.withdraw(4.00);
    Acc1.withdraw(2.00);
    
    cout << "Name: " << Acc1.getName() << endl;
    cout << "Interest Rate: " << Acc1.getInterestRate() << endl;
    cout << "Balance: " << Acc1.getBalance() << "\n\n";
    Acc1.printTransactions();
    cout << endl;
    
    return 0;
}
