## A doubly-linked list is a (dynamically allocated) list where the nodes feature two relationships: 
successor and predecessor
LAB TASK 1
CODE
Node structure for Doubly Linked List
struct Node {
 int data;
 Node* next;
 Node* prev;
};
// Head and Tail
Node* head = NULL;
Node* tail = NULL;
// Insert at END
void insertEnd(int value) {
 Node* newNode = new Node;
 newNode->data = value;
 newNode->next = NULL;
 newNode->prev = NULL;
 if (head == NULL) {
 head = newNode;
 tail = newNode;
 return;
 }
 tail->next = newNode;
 newNode->prev = tail;
 tail = newNode;
}
// Display forward
void display() {
 Node* temp = head;
 while (temp != NULL) {
 cout << temp->data << " <-> ";
 temp = temp->next;
 }
 cout << "NULL" << endl;
}
// ==================== REVERSE FUNCTION ====================
void reverseList() {
 
 if (head == NULL || head == tail) {
 return;
 }
 Node* current = head;
 Node* temp = NULL;
 // Traverse the list and swap next and prev of each node
 while (current != NULL) {
 // Swap next and prev
 temp = current->prev;
 current->prev = current->next;
 current->next = temp;
 // Move to the next node (which is now prev)
 current = current->prev;
 }
 // Swap head and tail
 temp = head;
 head = tail;
 tail = temp;
}
// ==================== MAIN FUNCTION ====================
int main() {
 insertEnd(10);
 insertEnd(20);
 insertEnd(30);
 insertEnd(40);
 cout << "Original List: ";
 display();
 reverseList();
 cout << "Reversed List: ";
 display();
 return 0; }

Lab task 02

CODE
#include <iostream>
using namespace std;
// Node structure for Doubly Linked List
struct Node {
 int data;
 Node* next;
 Node* prev;
};
// Head and Tail
Node* head = NULL;
Node* tail = NULL;
// ==================== INSERT AT END ====================
void insertEnd(int value) {
 Node* newNode = new Node;
 newNode->data = value;
 newNode->next = NULL;
 newNode->prev = NULL;
 if (head == NULL) {
 head = newNode;
 tail = newNode;
 return;
 }
 tail->next = newNode;
 newNode->prev = tail;
 tail = newNode;
}
// ==================== DISPLAY ====================
void display() {
 Node* temp = head;
 while (temp != NULL) {
 cout << temp->data << " <-> ";
 temp = temp->next;
 }
 cout << "NULL" << endl;
}
// ==================== SEARCH FUNCTION ====================
// Find a node with a specific value
Node* findNode(int value) {
 Node* temp = head;
 while (temp != NULL) {
 if (temp->data == value) {
 return temp;
 }
 temp = temp->next;
 }
 return NULL; // Not found
}
// ==================== SWAP NODES FUNCTION ====================
void swapNodes(int value1, int value2) {
 // Step 1: Find both nodes
 Node* node1 = findNode(value1);
 Node* node2 = findNode(value2);
 // Step 2: Check if both nodes exist
 if (node1 == NULL || node2 == NULL) {
 cout << "One or both values not found in the list." << endl;
 return;
 }
 // Step 3: If both values are the same
 if (node1 == node2) {
 cout << "Both values are the same. Nothing to swap." << endl;
 return;
 }
 // Step 4: Swap the nodes
 // We need to swap their positions in the list by adjusting pointers
 // ---------- Handle head ----------
 // If node1 is head, node2 becomes head (and vice versa)
 if (head == node1) {
 head = node2;
 } else if (head == node2) {
 head = node1;
 }
 // ---------- Handle tail ----------
 if (tail == node1) {
 tail = node2;
 } else if (tail == node2) {
 tail = node1;
 }
 // ---------- Swap prev pointers ----------
 Node* temp = node1->prev;
 node1->prev = node2->prev;
 node2->prev = temp;
 // ---------- Swap next pointers ----------
 temp = node1->next;
 node1->next = node2->next;
 node2->next = temp;
 // ---------- Fix the neighbors' pointers ----------
 // If node1's prev is not NULL, update its next to node1
 if (node1->prev != NULL) {
 node1->prev->next = node1;
 }
 // If node1's next is not NULL, update its prev to node1
 if (node1->next != NULL) {
 node1->next->prev = node1;
 }
 // If node2's prev is not NULL, update its next to node2
 if (node2->prev != NULL) {
 node2->prev->next = node2;
 }
 // If node2's next is not NULL, update its prev to node2
 if (node2->next != NULL) {
 node2->next->prev = node2;
 }
 cout << "Nodes swapped successfully!" << endl;
}
// ==================== MAIN FUNCTION ====================
int main() {
 // Create a list: 10 <-> 20 <-> 30 <-> 40 <-> 50
 insertEnd(10);
 insertEnd(20);
 insertEnd(30);
 insertEnd(40);
 insertEnd(50);
 cout << "Original List: ";
 display();
 int value1, value2;
 cout << "\nEnter first value to swap: ";
 cin >> value1;
 cout << "Enter second value to swap: ";
 cin >> value2;
 swapNodes(value1, value2);
 cout << "List after swapping: ";
 display();
 return 0;
}

LAB TASK 03

CODE
#include <iostream>
using namespace std;
// Node structure for Singly Linked List
struct SinglyNode {
 int data;
 SinglyNode* next;
};
// Node structure for Doubly Linked List
struct DoublyNode {
 int data;
 DoublyNode* next;
 DoublyNode* prev;
};
// Head pointers
SinglyNode* singlyHead = NULL;
DoublyNode* doublyHead = NULL;
DoublyNode* doublyTail = NULL;
// Insert at end of Singly Linked List
void insertSingly(int value) {
 SinglyNode* newNode = new SinglyNode;
 newNode->data = value;
 newNode->next = NULL;
 if (singlyHead == NULL) {
 singlyHead = newNode;
 return;
 }
 SinglyNode* temp = singlyHead;
 while (temp->next != NULL) {
 temp = temp->next;
 }
 temp->next = newNode;
}
// Display Singly Linked List
void displaySingly() {
 SinglyNode* temp = singlyHead;
 cout << "Singly List: ";
 while (temp != NULL) {
 cout << temp->data << " -> ";
 temp = temp->next;
 }
 cout << "NULL" << endl;
}
// Insert at end of Doubly Linked List
void insertDoubly(int value) {
 DoublyNode* newNode = new DoublyNode;
 newNode->data = value;
 newNode->next = NULL;
 newNode->prev = NULL;
 if (doublyHead == NULL) {
 doublyHead = newNode;
 doublyTail = newNode;
 return;
 }
 doublyTail->next = newNode;
 newNode->prev = doublyTail;
 doublyTail = newNode;
}
// Display Doubly Linked List
void displayDoubly() {
 DoublyNode* temp = doublyHead;
 cout << "Doubly List: NULL <- ";
 while (temp != NULL) {
 cout << temp->data << " <-> ";
 temp = temp->next;
 }
 cout << "NULL" << endl;
}
// LAB TASK 3: Convert Singly to Doubly
void convertToDoubly(SinglyNode* sHead) {
 SinglyNode* temp = sHead;
 while (temp != NULL) {
 insertDoubly(temp->data);
 temp = temp->next;
 }
}
// Main function
int main() {
 insertSingly(10);
 insertSingly(20);
 insertSingly(30);
 insertSingly(40);
 insertSingly(50);
 cout << "=== Original Singly Linked List ===" << endl;
 displaySingly();
 convertToDoubly(singlyHead);
cout << "\n=== Converted Doubly Linked List =="<< endl;
displayDoubly();
return 0;
}
}
