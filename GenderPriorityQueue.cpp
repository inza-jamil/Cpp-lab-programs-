#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

// Structure to represent a Person
struct Person {
    string name;
    string gender;  // "Female" or "Male"
    int priority;   // 1 for Female (High), 2 for Male (Low)
};

class GenderQueue {
private:
    Person queueArray[MAX];
    int size;

public:
    GenderQueue() {
        size = 0;
    }

    bool isEmpty() {
        return (size == 0);
    }

    // ENQUEUE: Insert a person based on gender priority
    void enqueue(string name, string gender) {
        if (size == MAX) {
            cout << "Queue is full!" << endl;
            return;
        }

        // Set priority based on gender
        int priority;
        if (gender == "Female" || gender == "female") {
            priority = 1; // High Priority
        } else {
            priority = 2; // Low Priority
        }

        // Find the correct position to insert based on priority
        int i = size - 1;
        
        // Shift elements to the right if their priority number is GREATER (lower priority)
        // The while loop stops when it finds a Female (priority 1) or the queue is empty
        while (i >= 0 && queueArray[i].priority > priority) {
            queueArray[i + 1] = queueArray[i];
            i--;
        }

        // Insert the new person at the correct position
        queueArray[i + 1].name = name;
        queueArray[i + 1].gender = gender;
        queueArray[i + 1].priority = priority;
        size++;
        
        cout << name << " (" << gender << ") joined the queue." << endl;
    }

    // DEQUEUE: Remove and return the person with the highest priority
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        // The person at index 0 always has the highest priority (Female)
        cout << "Serving: " << queueArray[0].name 
             << " (" << queueArray[0].gender << ")" << endl;

        // Shift all remaining elements to the left
        for (int i = 0; i < size - 1; i++) {
            queueArray[i] = queueArray[i + 1];
        }
        size--;
    }

    // DISPLAY: Show the current queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "\n--- Current Queue ---" << endl;
        for (int i = 0; i < size; i++) {
            cout << i + 1 << ". " << queueArray[i].name 
                 << " (" << queueArray[i].gender << ")" << endl;
        }
        cout << "---------------------\n";
    }
};

int main() {
    GenderQueue q;

    cout << "--- People Arriving ---" << endl;
    q.enqueue("Ali", "Male");       // Arrives first, but low priority
    q.enqueue("Bilal", "Male");     // Arrives second, low priority
    q.enqueue("Ayesha", "Female");  // Arrives third, but HIGH priority
    q.enqueue("Zara", "Female");    // Arrives fourth, HIGH priority

    // Display the waiting list
    q.display();

    cout << "\n--- Serving People ---" << endl;
    q.dequeue(); // Should serve Ayesha first (Female)
    q.dequeue(); // Should serve Zara next (Female)
    q.dequeue(); // Now serve Ali (Male - First in line among males)
    q.dequeue(); // Serve Bilal (Male)

    return 0;
}

Output (Dry Run)
--- People Arriving ---
Ali (Male) joined the queue.
Bilal (Male) joined the queue.
Ayesha (Female) joined the queue.
Zara (Female) joined the queue.

--- Current Queue ---
1. Ayesha (Female)
2. Zara (Female)
3. Ali (Male)
4. Bilal (Male)
---------------------

--- Serving People ---
Serving: Ayesha (Female)
Serving: Zara (Female)
Serving: Ali (Male)
Serving: Bilal (Male)
