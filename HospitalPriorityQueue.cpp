#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

// Structure to represent a Patient
struct Patient {
    string name;    // Patient's name
    int priority;   // 1 = Critical, 2 = Moderate, 3 = Normal
};

class PriorityQueue {
private:
    Patient queueArray[MAX]; // Array to store patients
    int size;                // Current number of patients

public:
    // Constructor initializes an empty queue
    PriorityQueue() {
        size = 0;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return (size == 0);
    }

    // ENQUEUE: Insert a patient based on priority
    // Lower priority number means HIGHER priority (1 is highest)
    void enqueue(string name, int priority) {
        if (size == MAX) {
            cout << "Emergency Room is full! Cannot admit more patients." << endl;
            return;
        }

        // Find the correct position to insert based on priority
        int i = size - 1;
        
        // Shift elements to the right if their priority is LOWER (greater number)
        // or if priority is equal, we want FIFO (so we don't shift equal priorities)
        while (i >= 0 && queueArray[i].priority > priority) {
            queueArray[i + 1] = queueArray[i];
            i--;
        }

        // Insert the new patient at the correct position
        queueArray[i + 1].name = name;
        queueArray[i + 1].priority = priority;
        size++;
        
        cout << "Patient " << name << " admitted with Priority " << priority << "." << endl;
    }

    // DEQUEUE: Remove and return the patient with the highest priority (Front)
    void dequeue() {
        if (isEmpty()) {
            cout << "No patients in the Emergency Room." << endl;
            return;
        }

        // The patient with the highest priority is always at index 0
        cout << "Treating Patient: " << queueArray[0].name 
             << " (Priority: " << queueArray[0].priority << ")" << endl;

        // Shift all remaining elements to the left to remove the front element
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
        cout << "\n--- Current Waiting List ---" << endl;
        for (int i = 0; i < size; i++) {
            cout << "Name: " << queueArray[i].name 
                 << " | Priority: " << queueArray[i].priority << endl;
        }
        cout << "----------------------------\n";
    }
};

int main() {
    PriorityQueue er;

    // Scenario: Patients arriving at the Emergency Room
    cout << "--- Patients Arriving ---" << endl;
    er.enqueue("Ali", 3);      // Normal (Lowest Priority)
    er.enqueue("Ayesha", 1);   // Critical (Highest Priority)
    er.enqueue("Bilal", 2);    // Moderate
    er.enqueue("Zara", 1);     // Critical (Arrived later, but same priority as Ayesha)

    // Display the waiting list
    er.display();

    // Treating patients one by one
    cout << "\n--- Treating Patients ---" << endl;
    er.dequeue(); // Should treat Ayesha first (Priority 1, arrived before Zara)
    er.dequeue(); // Should treat Zara next (Priority 1)
    er.dequeue(); // Should treat Bilal (Priority 2)
    er.dequeue(); // Should treat Ali (Priority 3)

    return 0;
}

Output (Dry Run)

--- Patients Arriving ---
Patient Ali admitted with Priority 3.
Patient Ayesha admitted with Priority 1.
Patient Bilal admitted with Priority 2.
Patient Zara admitted with Priority 1.

--- Current Waiting List ---
Name: Ayesha | Priority: 1
Name: Zara | Priority: 1
Name: Bilal | Priority: 2
Name: Ali | Priority: 3
----------------------------

--- Treating Patients ---
Treating Patient: Ayesha (Priority: 1)
Treating Patient: Zara (Priority: 1)
Treating Patient: Bilal (Priority: 2)
Treating Patient: Ali (Priority: 3)
