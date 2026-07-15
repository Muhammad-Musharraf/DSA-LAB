#include<iostream>
using namespace std;

// Structure of a Doubly Linked List Node
struct Node
{
    int index;      // Stores the position (index) of the node
    float data;     // Stores the data value
    Node* prev;     // Pointer to the previous node
    Node* next;     // Pointer to the next node
};

// Head points to the first node
Node *head = NULL;

// Tail points to the last node
Node *tail = NULL;

// Keeps track of total inserted nodes
int nodeCount = 0;

//----------------------------------------------------------
// Function: insert()
// Purpose : Insert a new node at the end of the linked list
//----------------------------------------------------------
void insert(float value)
{
    // Create a new node
    Node* temp = new Node;

    // Store data in the node
    temp->data = value;

    // Assign index to the node
    temp->index = nodeCount++;

    // Initially previous and next are NULL
    temp->next = NULL;
    temp->prev = NULL;

    // If list is empty
    if(head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }

    // Attach new node after tail
    tail->next = temp;

    // Set previous pointer of new node
    temp->prev = tail;

    // Move tail to the last node
    tail = temp;
}

//----------------------------------------------------------
// Function: print()
// Purpose : Print all nodes with index and data
//----------------------------------------------------------
void print()
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout << "Index : " << temp->index
             << "   Data : " << temp->data << endl;

        temp = temp->next;
    }
}

//----------------------------------------------------------
// Function: swap()
// Purpose : Swap data of two nodes
//----------------------------------------------------------
void swap(Node* a, Node* b)
{
    float t = a->data;
    a->data = b->data;
    b->data = t;
}

//----------------------------------------------------------
// Function: partition()
// Purpose : Partition function used in Quick Sort
//----------------------------------------------------------
Node* partition(Node* low, Node* high)
{
    // Last node is selected as Pivot
    float pivot = high->data;

    // Pointer before low node
    Node* i = low->prev;

    // Traverse from low to one node before high
    for(Node* j = low; j != high; j = j->next)
    {
        // If current value is smaller than pivot
        if(j->data < pivot)
        {
            // Move i forward
            if(i == NULL)
                i = low;
            else
                i = i->next;

            // Swap data
            swap(i, j);
        }
    }

    // Place pivot at its correct position
    if(i == NULL)
        i = low;
    else
        i = i->next;

    swap(i, high);

    // Return pivot position
    return i;
}

//----------------------------------------------------------
// Function: quickSort()
// Purpose : Sort the linked list using Quick Sort
//----------------------------------------------------------
void quickSort(Node* low, Node* high)
{
    // Base Condition
    if(high != NULL &&
       low != high &&
       low != high->next)
    {
        // Find partition point
        Node* p = partition(low, high);

        // Sort left part
        quickSort(low, p->prev);

        // Sort right part
        quickSort(p->next, high);
    }
}

//----------------------------------------------------------
// Main Function
//----------------------------------------------------------
int main()
{
    int n;
    float value;

    // Input number of nodes
    cout << "Enter Number of Nodes : ";
    cin >> n;

    // Input node values
    for(int i = 0; i < n; i++)
    {
        cout << "Enter Value " << i + 1 << " : ";
        cin >> value;

        // Insert node
        insert(value);
    }

    // Display original linked list
    cout << "\nOriginal Doubly Linked List\n";
    print();

    // Sort the linked list
    quickSort(head, tail);

    // Display sorted linked list
    cout << "\nSorted Doubly Linked List\n";
    print();

    return 0;
}