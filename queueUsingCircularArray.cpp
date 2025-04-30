#include <iostream>
using namespace std;

// Define the queue structure
struct Queue {
    int* arr;
    int front, rear, size, capacity;
};

// Function to initialize the queue
void initializeQueue(Queue& q, int cap) {
    q.capacity = cap;
    q.arr = new int[cap];
    q.front = q.rear = -1;
    q.size = 0;
}

// Enqueue operation: Add an element to the queue
void enqueue(Queue& q, int value) {
    if (q.size == q.capacity) {
        cout << "Queue is full!" << endl;
        return;
    }

    if (q.front == -1) {
        // If the queue is empty, both front and rear will point to index 0
        q.front = q.rear = 0;
    } else {
        q.rear = (q.rear + 1) % q.capacity;
    }

    q.arr[q.rear] = value;
    q.size++;
    cout << "Enqueued: " << value << endl;
}

// Dequeue operation: Remove an element from the front of the queue
void dequeue(Queue& q) {
    if (q.size == 0) {
        cout << "Queue is empty!" << endl;
        return;
    }

    cout << "Dequeued: " << q.arr[q.front] << endl;
    q.front = (q.front + 1) % q.capacity;
    q.size--;
}

// Peek operation: Get the front element without removing it
int peek(Queue& q) {
    if (q.size == 0) {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    return q.arr[q.front];
}

// Check if the queue is empty
bool isEmpty(Queue& q) {
    return q.size == 0;
}

// Check if the queue is full
bool isFull(Queue& q) {
    return q.size == q.capacity;
}

// Destructor: Clean up dynamically allocated memory
void destroyQueue(Queue& q) {
    delete[] q.arr;
}

int main() {
    Queue q;
    initializeQueue(q, 5);  // Create a queue with capacity 5

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    cout << "Front of the queue: " << peek(q) << endl;

    dequeue(q);
    dequeue(q);

    cout << "Front of the queue: " << peek(q) << endl;

    enqueue(q, 60);  // Add more elements after some dequeue

    cout << "Front of the queue: " << peek(q) << endl;

    // Empty the queue
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);

    destroyQueue(q);  // Cleanup memory
    return 0;
}
