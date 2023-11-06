#include "Queue.h"

// Constructor
Queue::Queue() {
  front = nullptr;
  rear = nullptr;
  size = 0;
}

// Destructor
Queue::~Queue() {
  while (!isEmpty()) {
    dequeue();
  }
}

// Inserts a new element at the rear of the queue
void Queue::enqueue(int value) {
  Node *newNode = new Node;
  newNode->data = value;
  newNode->next = nullptr;
  if (isEmpty()) {
    front = newNode;
    rear = newNode;
  } else {
    rear->next = newNode;
    rear = newNode;
  }
  size++;
}

// Removes the front element of the queue and returns it
int Queue::dequeue() {
  if (isEmpty()) {
    std::cerr << "Queue is empty. Cannot dequeue." << std::endl;
    return -1; // Placeholder for error
  }
  int value = front->data;
  Node *temp = front;
  front = front->next;
  delete temp;
  size--;
  return value;
}

// Returns the front element without removing it
int Queue::peek() {
  if (isEmpty()) {
    std::cerr << "Queue is empty. Cannot peek." << std::endl;
    return -1; // Placeholder for error
  }
  return front->data;
}

// Checks if the queue is empty
bool Queue::isEmpty() { return size == 0; }

// Returns the total number of elements in the queue
int Queue::getSize() { return size; }
