#include<iostream>
using namespace std;

//------------------------------
// Node Structure
//------------------------------
struct Node
{
    float data;      // Store data
    Node *prev;      // Pointer to previous node
    Node *next;      // Pointer to next node
};

// Head and Tail pointers
Node *head = NULL;
Node *tail = NULL;

//----------------------------------------------------
// Insert at End
//----------------------------------------------------
void insert(float value)
{
    // Create a new node
    Node *temp = new Node;

    temp->data = value;
    temp->next = NULL;
    temp->prev = NULL;

    // If list is empty
    if(head == NULL)
    {
        head = tail = temp;
        return;
    }

    // Attach new node at the end
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

//----------------------------------------------------
// Print List
//----------------------------------------------------
void print()
{
    Node *temp = head;

    if(temp == NULL)
    {
        cout<<"List is Empty\n";
        return;
    }

    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    cout<<endl;
}

//----------------------------------------------------
// Reverse Doubly Linked List
//----------------------------------------------------
void reverseList()
{
    Node *current = head;
    Node *temp = NULL;

    // Swap next and prev pointers
    while(current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        current = current->prev;
    }

    // Swap head and tail
    if(temp != NULL)
    {
        temp = temp->prev;

        Node *swap = head;
        head = tail;
        tail = swap;
    }
}

//----------------------------------------------------
// Find Minimum Element
//----------------------------------------------------
void minimum()
{
    if(head == NULL)
    {
        cout<<"List is Empty\n";
        return;
    }

    float min = head->data;

    Node *temp = head->next;

    while(temp != NULL)
    {
        if(temp->data < min)
            min = temp->data;

        temp = temp->next;
    }

    cout<<"Minimum Element = "<<min<<endl;
}

//----------------------------------------------------
// Find Maximum Element
//----------------------------------------------------
void maximum()
{
    if(head == NULL)
    {
        cout<<"List is Empty\n";
        return;
    }

    float max = head->data;

    Node *temp = head->next;

    while(temp != NULL)
    {
        if(temp->data > max)
            max = temp->data;

        temp = temp->next;
    }

    cout<<"Maximum Element = "<<max<<endl;
}

//----------------------------------------------------
// Main Function
//----------------------------------------------------
int main()
{
    int choice;
    float value;

    do
    {
        cout<<"\n====== MENU ======\n";
        cout<<"1. Insert\n";
        cout<<"2. Print\n";
        cout<<"3. Reverse List\n";
        cout<<"4. Find Minimum\n";
        cout<<"5. Find Maximum\n";
        cout<<"6. Exit\n";

        cout<<"Enter Choice : ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                cout<<"Enter Value : ";
                cin>>value;
                insert(value);
                break;

            case 2:
                cout<<"List : ";
                print();
                break;

            case 3:
                reverseList();
                cout<<"List Reversed Successfully.\n";
                break;

            case 4:
                minimum();
                break;

            case 5:
                maximum();
                break;

            case 6:
                cout<<"Program Ended.\n";
                break;

            default:
                cout<<"Invalid Choice.\n";
        }

    }while(choice != 6);

    return 0;
}