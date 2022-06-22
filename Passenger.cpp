/*
 @author Bailey Jones
 @date 5/17/2022
 * 
 * This is the class file for Passenger, which includes the bulk of the operations done for this project.
 */

// include statement vomit
#include "Passenger.h"
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>

// namespace std for clarity
using namespace std;

// def constructor
Passenger::Passenger()
{
    
}

/*
 overloaded constructor
 */
Passenger::Passenger(string input, bool sorter)
{
    // stringstream allows us to perform several calculations on our given line of text
    stringstream ss(input);
    
    // puts in the last name
    ss >> lastName;
    // puts in the type
    ss >> type;
    // puts in the row number
    ss >> row; 
    key = 1;
    
    // checks for people who need help
    if (type == 'H')
    {
        priority = true;
        key = 7;
    }
    // checks for first class members
    else if(row <= 4)
    {
        priority = true;
        key = 6;
    }
    // checks for VIP flyers and people in exit seats
    else if(row == 10 || row == 11 || type == 'E')
    {
        priority = true;
        key = 5;
    }
    // any other condition is a general boarder
    else
    {
        priority = false;
    }
    
    // this short section allows us to sort by row once there are no more special cases, descending order
    if(sorter && !priority)
    {
        // row 23-26 checked
        if(row <= 26 && row >= 23)
        {
            key = 4;
        }
        // row 17-22 check
        else if(row <= 22 && row >=17)
        {
            key = 3;
        }
        // row 11-16 check
        else if(row <= 16 && row >= 11)
        {
            key = 2;
        }
        // row 5-10 check
        else if(row <= 10 && row >=5)
        {
            key = 1;
        }
    }
}

// accessor for key
int Passenger::getKey()
{
    return key;
}

// accessor for lastName
string Passenger::getLastName()
{
    return lastName;
}

// accessor for type
char Passenger::getType()
{
    return type;
}

// accessor for row
int Passenger::getRow()
{
    return row;
}

// mutator for key
void Passenger::setKey(int newKey)
{
    key = newKey;
}

// mutator for lastName
void Passenger::setLastName(string newSurname)
{
    lastName = newSurname;
}

// mutator for type
void Passenger::setType(char newType)
{
    type = newType;
}

// mutator for row number
void Passenger::setRow(int newRow)
{
    row = newRow;
}

// overloading the greater than operator to compare passenger objects by key
bool Passenger::operator>(const Passenger &compare)
{
    return(key > compare.key);
}
// overloading the less than operator to compare passenger objects by key
bool Passenger::operator<(const Passenger &compare)
{
    return(key < compare.key);
}
// overloading the double equals operator to compare passenger objects by key
bool Passenger::operator==(const Passenger &compare)
{
    return(key == compare.key);
}

