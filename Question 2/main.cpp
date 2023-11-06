#include "Queue.h"
#include <iostream>

int main() {
  Queue myQueue;

  std::cout << "Is the queue empty? " << (myQueue.isEmpty() ? "Yes" : "No") // if the queue is empty, print "Yes"
            << std::endl;

  myQueue.enqueue(10); 
  myQueue.enqueue(20);
  myQueue.enqueue(30);

  std::cout << "Front element: " << myQueue.peek() << std::endl; // Print the front element
  std::cout << "Is the queue empty? " << (myQueue.isEmpty() ? "Yes" : "No") // if the queue is empty, print "Yes"
            << std::endl;
  std::cout << "Queue size: " << myQueue.getSize() << std::endl; // Print the size of the queue

  std::cout << "Dequeue: " << myQueue.dequeue() << std::endl; // Print the dequeued element

  std::cout << "Front element: " << myQueue.peek() << std::endl;
  std::cout << "Is the queue empty? " << (myQueue.isEmpty() ? "Yes" : "No") // if the queue is empty, print "Yes"
    << std::endl;
  std::cout << "Queue size: " << myQueue.getSize() << std::endl; // Print the size of the queue

  return 0;
}
