#include <iostream>
#include <stack>
using namespace std;

// Node Structure
struct Node
{
    int data;
    Node *next;
};

// Head Pointer
Node *head = NULL;

// Insert at End
void insertEnd(int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Count Total Nodes
int countNodes()
{
    int count = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

// Insert at nth Position
void insertNthPosition(int value, int n)
{
    int totalNodes = countNodes();

    // If list has fewer than n nodes
    if (totalNodes < n)
    {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;

        // Odd value -> Insert at Beginning
        if (value % 2 != 0)
        {
            newNode->next = head;
            head = newNode;
            cout << "\nList has less than " << n
                 << " nodes. Odd value inserted at beginning.\n";
        }
        // Even value -> Insert at End
        else
        {
            if (head == NULL)
            {
                head = newNode;
            }
            else
            {
                Node *temp = head;

                while (temp->next != NULL)
                    temp = temp->next;

                temp->next = newNode;
            }

            cout << "\nList has less than " << n
                 << " nodes. Even value inserted at end.\n";
        }

        return;
    }

    // Insert at Beginning if n == 1
    if (n == 1)
    {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        return;
    }

    // Traverse to (n-1)th node
    Node *temp = head;

    for (int i = 1; i < n - 1; i++)
        temp = temp->next;

    Node *newNode = new Node;
    newNode->data = value;

    newNode->next = temp->next;
    temp->next = newNode;

    cout << "\nInserted at Position " << n << endl;
}

// Display List
void display()
{
    Node *temp = head;

    cout << "\nLinked List : ";

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

// Reverse Display Using Iteration
void reverseDisplay()
{
    stack<int> st;

    Node *temp = head;

    while (temp != NULL)
    {
        st.push(temp->data);
        temp = temp->next;
    }

    cout << "\nReverse Display : ";

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    cout << endl;
}

int main()
{
    int n, value, position;

    cout << "Enter Number of Nodes: ";
    cin >> n;

    cout << "Enter Node Values:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> value;
        insertEnd(value);
    }

    display();

    // Example:
    // Student ID = 767
    // Last Digit = 7
    position = 7;

    cout << "\nEnter Value to Insert: ";
    cin >> value;

    insertNthPosition(value, position);

    display();

    reverseDisplay();

    return 0;
}