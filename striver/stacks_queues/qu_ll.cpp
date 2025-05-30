#include <bits/stdc++.h>
using namespace std;

// Node class for the queue
class QueueNode {
public:
    int val;
    QueueNode* next;
    QueueNode(int dat) {
        val = dat;
        next = nullptr;
    }
};

// Queue class to manage queue operations
class Queue {
public:
    QueueNode* front;
    QueueNode* rear;
    int size;

    // Default constructor
    Queue() {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }

    // Push an element to the queue
    void push(int n) {
        QueueNode* tmp = new QueueNode(n);
        if (front == nullptr) {
            front = tmp;
            rear = tmp;
        } else {
            rear->next = tmp;
            rear = tmp;
        }
        size++;
    }

    // Pop an element from the queue
    void pop() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
        } else {
            cout << front->val << " deleted" << endl;
            QueueNode* tmp = front;
            front = front->next;
            delete tmp;
            size--;
            if (front == nullptr) { // If queue becomes empty, reset rear
                rear = nullptr;
            }
        }
    }

    // Return the front element of the queue
    int top() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->val;
    }

    // Return the size of the queue
    int getSize() {
        if (front == nullptr && rear == nullptr) {
            cout << "Queue is empty" << endl;
            return 0;
        }
        return size;
    }
};

int main() {
    Queue q; // Create a Queue object
    q.push(10);
    q.push(20);
    cout << "Front element: " << q.top() << endl;
    cout << "Size: " << q.getSize() << endl;
    q.pop();
    cout << "Front element: " << q.top() << endl;
    cout << "Size: " << q.getSize() << endl;
    q.pop();
    q.pop(); // Test empty queue
    return 0;
}