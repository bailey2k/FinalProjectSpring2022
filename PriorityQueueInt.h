

/* 
 * File:   PriorityQueueInt.h
 * Author: Bailey
 *
 * Created on May 17, 2022, 6:11 AM
 * 
 * This exists just as an interface for the PriorityQueue class.
 */

#ifndef PRIORITYQUEUEINT_H
#define PRIORITYQUEUEINT_H

// class begins 
template<class T>
class PriorityQueueInt

{
    public:
        
        virtual bool isEmpty() const = 0;
        virtual bool add(const T &newItem) = 0;
        virtual bool remove() = 0;
        virtual T peek() const = 0;
};

#endif /* PRIORITYQUEUEINT_H */

