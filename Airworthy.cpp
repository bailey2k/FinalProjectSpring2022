/*
 @author Bailey Jones
 @date 5/17/2022
 * This is the class for Airworthy.
 */

// our list of include statements
#include "Airworthy.h"
#include "Heap_PriorityQueue.cpp"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

// std namespace to make code readable
using namespace std;

//def constructor
Airworthy::Airworthy()
{
    
}
/*
 @param file is the name of the input file
 @param output is the name of the output file
 this is an overloaded constructor for an Airworthy object
 */
Airworthy::Airworthy(const string &file, const string &output)
{
    loadHeaps(file, output);
}

/*
 @param file is the name of the input file
 @param output is the name of the output file
 loadHeaps essentially takes the data from the file and puts it into a queue, while also writing on the output file
 */
void Airworthy::loadHeaps(const string &file, const string &output)
{
    // our objects and a string for writing
    string input;
    ifstream inputFile(file);
    ofstream outputFile(output);
    
    // error check
    if (!inputFile)
    {
        cout << "Error while opening file: " << file << endl << "Queues not filled" << endl;      
    }
    // another error check
    else if (!outputFile)
    {
        cout << "Error while opening file: " << file << endl << "File data not stored" << endl;
    }
    // if both pass without errors, this runs
    else
    {
        // just a header
        outputFile << "Passengers" << endl << "Name    Type Row" << endl << "-------------------" << endl;
        
        // runs until EOF
        while(!inputFile.eof())
        {
            // gets one line
            getline(inputFile, input);
            
            // this allows the program to ignore empty lines if they exist
            if(!input.empty())
            {
                // create passenger objects based on the different scenarios
                Passenger general(input, true);
                Passenger priority(input, false);
                previous.add(general);
                random.add(priority);
                
                // write to the file
                outputFile << left << setw(12) << general.getLastName() << general.getType()
                        << right << setw(5) << general.getRow() << endl;
            }
            
        }
        // close both files
        inputFile.close();
        outputFile.close();
        
    }
    
}
/*
 @param output is the name of the output file
 runSim opens the output file back up, and runs the simulation for both scenarios, passing to the boarding method
 */
void Airworthy::runSim(const string& output)
{
    // reopens the outputFile, the app call lets us do this (it opens the file and moves to the end position so we can append onto it)
    ofstream outputFile(output, ios_base::app);
    
    // error check, checks for file existence
    if(!outputFile)
    {
        cout << "Error opening file: " << output << endl << "Sim not saved" << endl;
    }
    //basically just glorified method calls but with headers
    else
    {
        outputFile << endl << "General Boarding (Previous)"  
           << endl  << "Name    Type Row" << endl << "-------------------" << endl;
        boarding(previous, output);
        
        outputFile << "General Boarding (Randomized)" 
           << endl  << "Name    Type Row" << endl << "-------------------" << endl;
        boarding(random, output);
        
     
    }
    // close file again
    outputFile.close();
}
/*
 @param queue is the data structure we use to perform operations on
 @param output is the output file which is back up again
 * boarding is a method that 
 */
void Airworthy::boarding(Heap_PriorityQueue<Passenger> &queue, const string& output)
{
    // reopen file
    ofstream outputFile(output, ios_base::app);
    
    // checks for file existence
    if(!outputFile)
    {
        cout << "Error opening file: " << output << endl << "Sim not saved" << endl;
    }
    else
    {   
        // allows doubles to be formatted to two decimal places
        outputFile << fixed << setprecision(2);
        // initialize the boardTime to zero for clarity
        boardTime = 0;
        // there are only 26 rows, so we use this value of 27 to compare
        int previousRow = 27;
        
        // each iteration should remove an item, so this runs until empty
        while(!queue.isEmpty())
        {
            // pull ref to a passenger object
            Passenger flyer = queue.peek();
            // pull ref to the row number
            int boardingRow = flyer.getRow();
            // compare to the last iteration's row number and if blocked, add 25 seconds
            if(previousRow <= boardingRow)
            {
                boardTime += 25;
            }
            // non blocked boarders take 1 second to board
            else
            {
                boardTime++;
            }
            // allows the loop to run
            previousRow = boardingRow;
            
            // writes to the output file
            outputFile << left << setw(14) << flyer.getLastName()
            << flyer.getType() << right << setw(5) << flyer.getRow() << endl;
            
            // IMPORTANT!!!!! this removes the items from the queue and without it, nothing will work
            queue.remove();
        }
        // our total boarding time, divided from seconds into minutes
        outputFile << "Total boarding time was: " << displayTime() << " minutes." << endl << endl;
    }
    // close file
    outputFile.close();
}

/*
 displayTime only divides the number of seconds from the boarding method into minutes, self explanatory
 */
double Airworthy::displayTime()
{
    double minutes = boardTime / 60;
    return minutes;
}