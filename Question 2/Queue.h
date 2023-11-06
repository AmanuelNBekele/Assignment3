#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

class Queue {
private:
    struct Node {
        int data;
        Node* next;
    };
    Node* front;
    Node* rear;
    int size;

public:
    Queue();            // Constructor
    ~Queue();           // Destructor
    void enqueue(int);  // Inserts a new element at the rear of the queue
    int dequeue();      // Removes the front element of the queue and returns it
    int peek();         // Returns the front element without removing it
    bool isEmpty();     // Checks if the queue is empty
    int getSize();      // Returns the total number of elements in the queue
};

#endif
