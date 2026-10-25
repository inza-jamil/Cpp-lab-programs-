Lab Task 1: Delete Nodes with Even/Odd Values
#include <iostream>
using namespace std;

// Node structure for Singly Linked List
struct Node {
    int data;       // Stores the number
    Node* next;     // Pointer to the next node
};

Node* head = NULL;

// Function to add a node at the end
void insertEnd(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// ⭐ MAIN LOGIC: Delete nodes with EVEN values
// (Agar ODD values delete karni hon, to % 2 != 0 kar dein)
void deleteEvenValues() {
    // Step 1: Handle head nodes (Agar pehla node hi even hai)
    while (head != NULL && head->data % 2 == 0) {
        Node* temp = head;      // Store current head
        head = head->next;      // Move head to next node
        delete temp;            // Delete old head
    }

    if (head == NULL) return;   // Agar list khali ho gayi

    // Step 2: Handle rest of the list
    Node* current = head;
    while (current->next != NULL) {
        // If the next node has an even value
        if (current->next->data % 2 == 0) {
            Node* temp = current->next;   // Store the even node
            current->next = temp->next;   // Skip the even node
            delete temp;                  // Delete it from memory
        } else {
            current = current->next;      // Move forward
        }
    }
}

// Display function
void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    insertEnd(10);
    insertEnd(7);
    insertEnd(20);
    insertEnd(15);
    insertEnd(30);
    insertEnd(25);

    cout << "Original List: ";
    display();

    deleteEvenValues();

    cout << "After deleting Even values: ";
    display();

    return 0;
}

Output:
Original List: 10 -> 7 -> 20 -> 15 -> 30 -> 25 -> NULL
After deleting Even values: 7 -> 15 -> 25 -> NULL

Lab Task 2: Josephus Problem
#include <iostream>
using namespace std;

// Node structure for Circular Linked List
struct Node {
    int data;       // Person's number
    Node* next;     // Pointer to next person
};

// Function to create a circular list with 'n' people
Node* createCircle(int n) {
    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 1; i <= n; i++) {
        Node* newNode = new Node;
        newNode->data = i;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
            newNode->next = head; // Point to itself (circle complete)
        } else {
            tail->next = newNode;
            newNode->next = head;
            tail = newNode;
        }
    }
    return head;
}

// ⭐ MAIN LOGIC: Solve Josephus Problem
int josephus(int n, int m) {
    Node* head = createCircle(n); // Create the circle

    Node* current = head;
    Node* prev = head;

    // Find the node just before head (last node)
    while (prev->next != head) {
        prev = prev->next;
    }

    // Eliminate until only one person remains
    while (current->next != current) {
        // Skip m-1 persons
        for (int count = 1; count < m; count++) {
            prev = current;
            current = current->next;
        }

        // Eliminate the m-th person
        prev->next = current->next; // Skip the node
        delete current;             // Free memory
        current = prev->next;       // Move to next person
    }

    int survivor = current->data;
    delete current;
    return survivor;
}

int main() {
    int n, m;
    cout << "Enter number of people (n): ";
    cin >> n;
    cout << "Enter step count (m): ";
    cin >> m;

    int survivor = josephus(n, m);
    cout << "Survivor is: " << survivor << endl;

    return 0;
}

Output:
Enter number of people (n): 5
Enter step count (m): 2
Survivor is: 3

Lab Task 3: Delete All Even Positioned Nodes
#include <iostream>
using namespace std;

// Node structure for Singly Linked List
struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Function to add node at end
void insertEnd(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// ⭐ MAIN LOGIC: Delete nodes at even positions (2nd, 4th, 6th...)
// Note: 1-based indexing is used (1st node = position 1)
void deleteEvenPositions() {
    // If list is empty or has only one node, nothing to delete
    if (head == NULL || head->next == NULL) {
        return;
    }

    Node* current = head;   // Start from first node (position 1)
    Node* prev = NULL;

    int position = 1;       // Track current position

    while (current != NULL) {
        // If position is even, delete this node
        if (position % 2 == 0) {
            prev->next = current->next; // Skip the current node
            Node* temp = current;       // Store to delete
            current = current->next;    // Move to next
            delete temp;                // Delete even node
        } else {
            // If position is odd, just move forward
            prev = current;
            current = current->next;
        }
        position++; // Move to next position
    }
}

// Display function
void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    insertEnd(10); // Position 1 (Odd)
    insertEnd(20); // Position 2 (Even) - Delete
    insertEnd(30); // Position 3 (Odd)
    insertEnd(40); // Position 4 (Even) - Delete
    insertEnd(50); // Position 5 (Odd)

    cout << "Original List: ";
    display();

    deleteEvenPositions();

    cout << "After deleting Even positions: ";
    display();

    return 0;
}
Output:
Original List: 10 -> 20 -> 30 -> 40 -> 50 -> NULL
After deleting Even positions: 10 -> 30 -> 50 -> NULL
