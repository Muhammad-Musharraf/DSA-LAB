#include <iostream>
using namespace std;

//======================
// Node Structure
//======================
struct Node
{
    int data;
    Node *left;
    Node *right;
};

//======================
// Create New Node
//======================
Node* createNode(int value)
{
    Node* temp = new Node;

    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

//======================
// BST Insert
//======================
Node* insert(Node* root, int value)
{
    if(root == NULL)
        return createNode(value);

    if(value < root->data)
        root->left = insert(root->left, value);

    else
        root->right = insert(root->right, value);

    return root;
}

//======================
// Convert BST to Array
// (Preorder Traversal)
//======================
void preorderToArray(Node* root, int arr[], int &index)
{
    if(root == NULL)
        return;

    arr[index++] = root->data;

    preorderToArray(root->left, arr, index);
    preorderToArray(root->right, arr, index);
}

//======================
// Display Array
//======================
void displayArray(int arr[], int size)
{
    cout << "\nArray (Preorder): ";

    for(int i=0;i<size;i++)
        cout << arr[i] << " ";
}

//======================
// BST Search
//======================
bool searchBST(Node* root, int key)
{
    if(root == NULL)
        return false;

    if(root->data == key)
        return true;

    if(key < root->data)
        return searchBST(root->left, key);

    return searchBST(root->right, key);
}

//======================
// Main Function
//======================
int main()
{
    Node* root = NULL;

    int n;

    cout << "Enter Number of Nodes: ";
    cin >> n;

    cout << "Enter Values (Zero and Negative Allowed):\n";

    for(int i=0;i<n;i++)
    {
        int value;
        cin >> value;

        root = insert(root,value);
    }

    //--------------------------
    // Convert BST to Array
    //--------------------------
    int arr[100];
    int index = 0;

    preorderToArray(root,arr,index);

    //--------------------------
    // Display Array
    //--------------------------
    displayArray(arr,index);

    //--------------------------
    // Build BST Again
    //--------------------------
    Node* arrayBST = NULL;

    for(int i=0;i<index;i++)
        arrayBST = insert(arrayBST,arr[i]);

    //--------------------------
    // Search
    //--------------------------
    int key;

    cout << "\n\nEnter Value to Search: ";
    cin >> key;

    if(searchBST(arrayBST,key))
        cout << key << " Found.";

    else
        cout << key << " Not Found.";

    return 0;
}