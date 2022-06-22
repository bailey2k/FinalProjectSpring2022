
/* 
 * File:   Passenger.h
 * Author: Bailey
 *
 * Created on May 17, 2022, 3:08 AM
 */

#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>

// std namespace for clarity
using namespace std;

class Passenger
{
private:
    // our private fields
    int key;
    string lastName;
    char type;
    int row;
    bool priority;
    
public:
    // def constructor
    Passenger();
    //overloaded constructor
    Passenger(string input, bool sorter);
    
    // our accessors
    int getKey();
    string getLastName();
    char getType();
    int getRow();
    
    // our mutators
    void setKey(int newKey);
    void setLastName(string newSurname);
    void setType(char newType);
    void setRow(int newRow);
    
    // overloaded operators
    bool operator>(const Passenger &compare);
    bool operator<(const Passenger &compare);
    bool operator==(const Passenger &compare);
    
    
};


#endif /* PASSENGER_H */

