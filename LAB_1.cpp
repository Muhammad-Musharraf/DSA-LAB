#include <iostream>     // For input and output
#include <queue>        // For queue used in level-order insertion
using namespace std;

// Structure to represent a tree node
struct Node
{
    float data;         // Stores the value of the node
    Node *left;         // Pointer to left child
    Node *right;        // Pointer to right child
};

// Function to create a new node
Node* createNode(float value)
{
    Node* temp = new Node;   // Dynamically allocate memory
    temp->data = value;      // Store the given value
    temp->left = NULL;       // Initially left child is NULL
    temp->right = NULL;      // Initially right child is NULL
    return temp;             // Return the newly created node
}

// Function to insert a node in Level Order (Heap Style)
Node* insert(Node* root, float value)
{
    // Create a new node
    Node* newNode = createNode(value);

    // If tree is empty, make the new node the root
    if (root == NULL)
        return newNode;

    // Queue is used for level-order traversal
    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        // Get the front node from queue
        Node* current = q.front();
        q.pop();

        // If left child is empty, insert here
        if (current->left == NULL)
        {
            current->left = newNode;
            return root;
        }
        else
            q.push(current->left);

        // If right child is empty, insert here
        if (current->right == NULL)
        {
            current->right = newNode;
            return root;
        }
        else
            q.push(current->right);
    }

    return root;
}

// Function to search an element in the tree
bool search(Node* root, float x)
{
    // If tree is empty
    if (root == NULL)
        return false;

    // Queue for Level Order Traversal
    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        Node* current = q.front();
        q.pop();

        // Check if current node contains x
        if (current->data == x)
            return true;

        // Add left child to queue
        if (current->left != NULL)
            q.push(current->left);

        // Add right child to queue
        if (current->right != NULL)
            q.push(current->right);
    }

    // Element not found
    return false;
}

// Recursive function to count total nodes
int countNodes(Node* root)
{
    // Base case
    if (root == NULL)
        return 0;

    // Count current node + left subtree + right subtree
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Function to find predecessor and successor using Level Order Traversal
void predecessorSuccessor(Node* root, float x)
{
    if (root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    Node* prev = NULL;    // Stores previous node
    bool found = false;   // Checks if x is found

    while (!q.empty())
    {
        Node* current = q.front();
        q.pop();

        // If x was already found, current node is successor
        if (found)
        {
            cout << "Successor = " << current->data << endl;
            return;
        }

        // Check if current node is x
        if (current->data == x)
        {
            found = true;

            // Previous node is predecessor
            if (prev != NULL)
                cout << "Predecessor = " << prev->data << endl;
            else
                cout << "Predecessor = None" << endl;
        }

        // Update previous node
        prev = current;

        // Push left child
        if (current->left != NULL)
            q.push(current->left);

        // Push right child
        if (current->right != NULL)
            q.push(current->right);
    }

    // If x is the last node
    if (found)
        cout << "Successor = None" << endl;
    else
        cout << "Element not found." << endl;
}

// Function to display the tree using Level Order Traversal
void display(Node* root)
{
    if (root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    cout << "\nLevel Order Traversal:\n";

    while (!q.empty())
    {
        Node* current = q.front();
        q.pop();

        // Print current node
        cout << current->data << " ";

        // Add left child
        if (current->left != NULL)
            q.push(current->left);

        // Add right child
        if (current->right != NULL)
            q.push(current->right);
    }

    cout << endl;
}

// Main function
int main()
{
    Node* root = NULL;   // Initially tree is empty

    int n;
    float value, x;

    // Input number of nodes
    cout << "Enter number of nodes: ";
    cin >> n;

    // Input node values
    cout << "Enter elements:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> value;
        root = insert(root, value);   // Insert into tree
    }

    // Display the tree
    display(root);

    // Search an element
    cout << "\nEnter element to search: ";
    cin >> x;

    if (search(root, x))
    {
        cout << "Element Found" << endl;

        // Find predecessor and successor
        predecessorSuccessor(root, x);
    }
    else
    {
        cout << "Element Not Found" << endl;
    }

    // Display total number of nodes
    cout << "Total Nodes = " << countNodes(root);

    return 0;
}