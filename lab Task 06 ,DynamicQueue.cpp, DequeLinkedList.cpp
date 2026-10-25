Lab Task 1: Dynamic Queue (Linked Implementation)
#include <iostream>
using namespace std;

// Node structure for Linked Queue
struct Node {
    int data;       // Stores the value
    Node* next;     // Pointer to the next node
};

class LinkedQueue {
private:
    Node* front;    // Points to the front of the queue
    Node* rear;     // Points to the rear of the queue

public:
    // Constructor initializes an empty queue
    LinkedQueue() {
        front = NULL;
        rear = NULL;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return (front == NULL);
    }

    // ENQUEUE: Add an element to the rear of the queue
    void enqueue(int value) {
        Node* newNode = new Node; // Create a new node in memory
        newNode->data = value;
        newNode->next = NULL;

        // If the queue is empty, the new node is both front and rear
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            // Otherwise, link the current rear to the new node, and update rear
            rear->next = newNode;
            rear = newNode;
        }
        cout << value << " enqueued to queue." << endl;
    }

    // DEQUEUE: Remove and return the front element
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Cannot dequeue from an empty queue." << endl;
            return -1; // Return -1 to indicate error
        }

        Node* temp = front;       // Store the current front node
        int dequeuedValue = temp->data; // Get the value
        front = front->next;      // Move front to the next node

        // If front becomes NULL, the queue is now empty, so rear should also be NULL
        if (front == NULL) {
            rear = NULL;
        }

        delete temp;              // Free the memory of the dequeued node
        return dequeuedValue;
    }

    // PEEK: View the front element without removing it
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return front->data;
    }

    // DISPLAY: Print all elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        Node* temp = front;
        cout << "Queue Elements: ";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    // Create a dynamic queue object
    LinkedQueue q;

    // Test enqueue
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    // Display current queue
    q.display();

    // Test dequeue
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;

    // Display after dequeue
    q.display();

    // Test peek
    cout << "Front element is: " << q.peek() << endl;

    return 0;
}

Lab Task 2: Implement Deque in Linked List
#include <iostream>
using namespace std;

// Node structure for the Deque
struct Node {
    int data;
    Node* next;
};

class Deque {
private:
    Node* front;
    Node* rear;

public:
    // Constructor initializes an empty deque
    Deque() {
        front = NULL;
        rear = NULL;
    }

    // Check if deque is empty
    bool isEmpty() {
        return (front == NULL);
    }

    // INSERT AT FRONT: Add element at the beginning
    void insertFront(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        
        if (isEmpty()) {
            front = rear = newNode;
            newNode->next = NULL;
        } else {
            newNode->next = front; // New node points to current front
            front = newNode;       // Update front
        }
        cout << value << " inserted at Front." << endl;
    }

    // INSERT AT REAR: Add element at the end
    void insertRear(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode; // Current rear points to new node
            rear = newNode;       // Update rear
        }
        cout << value << " inserted at Rear." << endl;
    }

    // DELETE FROM FRONT: Remove element from beginning
    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty! Cannot delete from front." << endl;
            return;
        }

        Node* temp = front;
        front = front->next; // Move front to next node

        // If front becomes NULL, deque is empty, so update rear as well
        if (front == NULL) {
            rear = NULL;
        }

        cout << temp->data << " deleted from Front." << endl;
        delete temp;
    }

    // DELETE FROM REAR: Remove element from end
    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty! Cannot delete from rear." << endl;
            return;
        }

        // If there is only one element
        if (front == rear) {
            cout << front->data << " deleted from Rear." << endl;
            delete front;
            front = rear = NULL;
            return;
        }

        // Traverse to find the second-to-last node
        Node* temp = front;
        while (temp->next != rear) {
            temp = temp->next;
        }

        cout << rear->data << " deleted from Rear." << endl;
        delete rear;         // Delete the last node
        rear = temp;         // Update rear to second-to-last node
        rear->next = NULL;   // Set its next to NULL
    }

    // DISPLAY: Show all elements from front to rear
    void display() {
        if (isEmpty()) {
            cout << "Deque is empty." << endl;
            return;
        }
        Node* temp = front;
        cout << "Deque (Front to Rear): ";
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    Deque dq;

    // Test Insertions
    dq.insertFront(10);
    dq.insertRear(20);
    dq.insertFront(5);
    dq.insertRear(25);

    // Display current deque
    dq.display();

    // Test Deletions
    dq.deleteFront(); // Should delete 5
    dq.deleteRear();  // Should delete 25

    // Display after deletions
    dq.display();

    return 0;
}
