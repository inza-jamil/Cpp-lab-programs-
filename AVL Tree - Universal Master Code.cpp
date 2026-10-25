#include <iostream>
using namespace std;

// Node structure for AVL Tree
struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
};

// Function to get the height of the tree
int getHeight(Node* n) {
    if (n == NULL) return 0;
    return n->height;
}

// Function to get maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1; // Leaf node height is 1
    return newNode;
}

// Function to calculate Balance Factor
int getBalance(Node* n) {
    if (n == NULL) return 0;
    return getHeight(n->left) - getHeight(n->right);
}

// ---------------------------------------------------------
// ROTATION FUNCTIONS (The Core of AVL Tree)
// ---------------------------------------------------------

// Right Rotation (Used for Left-Left / LL Case)
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x; // x becomes the new root
}

// Left Rotation (Used for Right-Right / RR Case)
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y; // y becomes the new root
}

// ---------------------------------------------------------
// INSERTION FUNCTION
// ---------------------------------------------------------
Node* insert(Node* node, int data) {
    // 1. Normal BST Insertion
    if (node == NULL) return createNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node; // Duplicate keys not allowed

    // 2. Update height of current node
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // 3. Get the Balance Factor
    int balance = getBalance(node);

    // 4. If unbalanced, handle 4 cases:

    // Case 1: Left Left (LL) -> Right Rotation
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    // Case 2: Right Right (RR) -> Left Rotation
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    // Case 3: Left Right (LR) -> Left Rotate then Right Rotate
    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Case 4: Right Left (RL) -> Right Rotate then Left Rotate
    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// ---------------------------------------------------------
// DELETION FUNCTION (If scenario asks to remove a node)
// ---------------------------------------------------------
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != NULL) current = current->left;
    return current;
}

Node* deleteNode(Node* root, int data) {
    if (root == NULL) return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    if (root == NULL) return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0) return rightRotate(root);
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0) return leftRotate(root);
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

// ---------------------------------------------------------
// TRAVERSAL FUNCTIONS (To print the tree)
// ---------------------------------------------------------

// Inorder: Prints in sorted order (Left -> Root -> Right)
void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

// Preorder: (Root -> Left -> Right) - Useful to check tree structure
void preOrder(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

// ---------------------------------------------------------
// MAIN FUNCTION (Scenario Example)
// ---------------------------------------------------------
int main() {
    Node* root = NULL;

    // Exam mein jo bhi values aayen, unhein yahan insert karein
    int values[] = {30, 20, 10, 40, 50, 25, 45, 60};
    int n = sizeof(values) / sizeof(values[0]);

    cout << "Inserting values into AVL Tree: ";
    for (int i = 0; i < n; i++) {
        cout << values[i] << " ";
        root = insert(root, values[i]);
    }
    cout << endl << endl;

    cout << "Inorder Traversal (Sorted): ";
    inOrder(root);
    cout << endl;

    cout << "Preorder Traversal (Tree Structure): ";
    preOrder(root);
    cout << endl << endl;

    // Example: Deleting a value (Agar scenario mein delete karne ko kahe)
    cout << "Deleting 40 from the tree..." << endl;
    root = deleteNode(root, 40);

    cout << "Inorder Traversal after deletion: ";
    inOrder(root);
    cout << endl;

    return 0;
}
