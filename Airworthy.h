/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Airworthy.h
 * Author: Bailey
 *
 * Created on May 17, 2022, 3:36 AM
 */

#ifndef AIRWORTHY_H


#include "Heap_PriorityQueue.h"
#include "Passenger.h"
#include <string>

using namespace std;

class Airworthy
{
private:
    // Queue running the previous boarding method
    Heap_PriorityQueue<Passenger> previous;
    // queue running a random boarding method
    Heap_PriorityQueue<Passenger> random;
    
    // simple int for seconds of boarding time
    int boardTime;
    
    // methods
    void loadHeaps(const string &file, const string &output);
    void boarding(Heap_PriorityQueue<Passenger> &queue, const string& output);
    
    double displayTime();
    
public:
    // def constructor
    Airworthy();
    // overloaded constructor
    Airworthy(const string &file, const string &output);
    // simulation control
    void runSim(const string &output);
    
};

#define AIRWORTHY_H
#endif /* AIRWORTHY_H */

