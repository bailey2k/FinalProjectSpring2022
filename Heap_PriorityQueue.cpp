/*
 @author Bailey Jones
 @date 5/17/2022
 This is the cpp file for the Priority Queue heap, this is basically just the ArrayMaxHeap overridden
 */

#include "Heap_PriorityQueue.h"

// def constructor
template<class T>
Heap_PriorityQueue<T>::Heap_PriorityQueue()
{
    ArrayMaxHeap<T>();
}

//checks to see if the queue is empty and returns a boolean
template<class T>
bool Heap_PriorityQueue<T>::isEmpty() const
{
    return ArrayMaxHeap<T>::isEmpty();
}

// adds an item to the queue
template<class T>
bool Heap_PriorityQueue<T>::add(const T &newItem)
{
    return ArrayMaxHeap<T>::add(newItem);
}

// removes the item from the front of the queue
template<class T>
bool Heap_PriorityQueue<T>::remove()
{
    return ArrayMaxHeap<T>::remove();
}

//peeks the front of the queue, which allows us to access the queue's items
template<class T>
T Heap_PriorityQueue<T>::peek() const
{
    return ArrayMaxHeap<T>::peek();
}
