/*
 @author Bailey Jones
 @date 5/17/2022
 This is the main application cpp file for Project 2.
 */

// our include statements
#include "Airworthy.h"
#include <cstdlib>
#include <iostream>

using namespace std;

void description();

int main()
{
    // calls the description method
    description();                           
    
    // runs the sim at 70 percent capacity
    cout << "70 percent capacity simulation...." << endl;
    Airworthy test70("Airworthy70.txt","results70.txt");
    cout << "Done!" << endl;
    test70.runSim("results70.txt");
    
    // runs the sim at 85 percent capacity
    cout << "85 percent capacity simulation:" << endl;
    Airworthy test85("Airworthy85.txt","results85.txt");
    cout << "Done!" << endl;
    test85.runSim("results85.txt");
    
    // runs the sim at 100 percent capacity        
    cout << "100 percent capacity simulation:" << endl;
    Airworthy test100("Airworthy100.txt","results100.txt");
    cout << "Done!" << endl;
    test100.runSim("results100.txt");
}

// this method is just a simple description of the program
void description()
{
    cout << "This application takes in passenger information from a data file" << endl <<
            "and simulates several different boarding scenarios." << endl;

}