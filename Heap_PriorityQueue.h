/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Heap_PriorityQueue.h
 * Author: Bailey Jones
 *
 * Created on May 17, 2022, 5:29 AM
 */

// given statements
#ifndef HEAP_PRIORITYQUEUE_H
#define HEAP_PRIORITYQUEUE_H

//include statements
#include "ArrayMaxHeap.h"
#include "PriorityQueueInt.h"

// header file statements
template<class T>
class Heap_PriorityQueue : public PriorityQueueInt<T>,
        private ArrayMaxHeap<T>

{
    public:
        // def constructor
        Heap_PriorityQueue();
        // isEmpty checks for items in the queue
        bool isEmpty() const;
        // add allows us to append new items onto the queue
        bool add(const T &newItem);
        // remove gets rid of the item at the top of the queue
        bool remove();
        
        // peek allows us to see the top of the queue
        T peek() const;
        
};

#endif /* HEAP_PRIORITYQUEUE_H */

