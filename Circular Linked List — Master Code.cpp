#include <iostream>
using namespace std;

// Node structure for Circular Linked List
struct Node {
    int data;
    Node* next;
};

Node* head = NULL; // Global head pointer

// =========================================================
// 1. INSERTION FUNCTIONS
// =========================================================

// Insert at the End
void insertEnd(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    // If list is empty
    if (head == NULL) {
        head = newNode;
        newNode->next = head; // Point to itself
        return;
    }

    // Traverse to the last node
    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    
    // Link the new node
    temp->next = newNode;
    newNode->next = head;
}

// Insert at the Beginning
void insertStart(int value) {
    Node* newNode = new Node;
    newNode->data = value;

    // If list is empty
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    // Traverse to the last node
    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    // Link the new node
    newNode->next = head; // New node points to old head
    temp->next = newNode; // Last node points to new head
    head = newNode;       // Update head
}

// =========================================================
// 2. DELETION FUNCTION
// =========================================================

// Delete a node by its value
void deleteNode(int value) {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    // Case 1: Only one node exists
    if (head->next == head && head->data == value) {
        delete head;
        head = NULL;
        cout << value << " deleted.\n";
        return;
    }

    Node* current = head;
    Node* prev = NULL;

    // Case 2: Head node needs to be deleted
    if (head->data == value) {
        // Find last node
        while (current->next != head) {
            current = current->next;
        }
        current->next = head->next; // Last node points to second node
        Node* temp = head;
        head = head->next;          // Update head
        delete temp;
        cout << value << " deleted.\n";
        return;
    }

    // Case 3: Middle or Last node
    while (current->next != head && current->next->data != value) {
        current = current->next;
    }

    if (current->next->data == value) {
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
        cout << value << " deleted.\n";
    } else {
        cout << "Value " << value << " not found.\n";
    }
}

// =========================================================
// 3. TRAVERSAL & SEARCH
// =========================================================

// Display the Circular List
void display() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    cout << "Circular List: ";
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(back to head)" << endl;
}

// Search for a value
bool search(int value) {
    if (head == NULL) return false;

    Node* temp = head;
    do {
        if (temp->data == value) return true;
        temp = temp->next;
    } while (temp != head);
    
    return false;
}

// =========================================================
// MAIN FUNCTION (Scenario Example)
// =========================================================
int main() {
    cout << "--- Circular Linked List Master Code ---\n\n";

    // 1. Inserting values
    cout << "Inserting at End: 10, 20, 30\n";
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    display();

    cout << "\nInserting at Start: 5\n";
    insertStart(5);
    display();

    // 2. Searching
    cout << "\nSearching for 20: " << (search(20) ? "Found" : "Not Found") << endl;
    cout << "Searching for 99: " << (search(99) ? "Found" : "Not Found") << endl;

    // 3. Deleting
    cout << "\nDeleting 20:\n";
    deleteNode(20);
    display();

    cout << "\nDeleting head node 5:\n";
    deleteNode(5);
    display();

    return 0;
}
