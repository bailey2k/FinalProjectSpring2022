/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * @file:   main.cpp
 * @author: cwood
 *
 * Created on April 14, 2019, 6:45 PM
 */

#include <cstdlib>
#include <iostream>
#include "ArrayMaxHeap.h"

using namespace std;

/*
 * 
 */
int main2() {
    ArrayMaxHeap<int> priQ;
    cout << boolalpha << "Empty? " << priQ.isEmpty() << endl;
    
    cout << "Adding 14 " << endl;
    priQ.add(14);
    
    cout << "Adding 18 " << endl;
    priQ.add(18);
    
    cout << "Adding 174 " << endl;
    priQ.add(174);
    
    cout << "Adding 16 " << endl;
    priQ.add(16);
    
    cout << "Adding 154 " << endl;
    priQ.add(154);
    
    cout << "Adding 1000 " << endl;
    priQ.add(1000);
    
    cout << priQ.getItemCount() << " items" << endl;
    cout << "Highest priority: " << priQ.peek() << endl;
    
    priQ.remove();
    cout << "Highest priority: " << priQ.peek() << endl;
    
    priQ.remove();
    cout << "Highest priority: " << priQ.peek() << endl;
    
    return 0;
}

