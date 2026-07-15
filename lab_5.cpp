#include <iostream>
#include <vector>
using namespace std;

//-----------------------------------------------------
// Structure of a 4-Way Tree Node
//-----------------------------------------------------
struct Node
{
    int data;           // Stores the node value
    Node* child[4];     // Array of 4 child pointers

    // Constructor to initialize the node
    Node(int value)
    {
        data = value;

        // Initially all child pointers are NULL
        for(int i = 0; i < 4; i++)
            child[i] = NULL;
    }
};

//-----------------------------------------------------
// Function: buildTree()
// Purpose : Recursively builds a 4-way tree
//-----------------------------------------------------
Node* buildTree(vector<int> arr)
{
    // Base Case:
    // If the array is empty, no node can be created.
    if(arr.size() == 0)
        return NULL;

    // Find the middle index (Median)
    int mid = arr.size() / 2;

    // Create a new node using the median value
    Node* root = new Node(arr[mid]);

    // Store the median value
    int M = arr[mid];

    // Create four subsets
    vector<int> S1, S2, S3, S4;

    //-------------------------------------------------
    // Divide the array into four subsets
    //-------------------------------------------------
    for(int x : arr)
    {
        // Skip the median because it is already the root
        if(x == M)
            continue;

        // S1 : Values less than or equal to M/2
        if(x <= M / 2)
            S1.push_back(x);

        // S2 : Values greater than M/2 but less than M
        else if(x > M / 2 && x < M)
            S2.push_back(x);

        // S3 : Values greater than M but less than 3M/2
        else if(x > M && x < 3 * M / 2)
            S3.push_back(x);

        // S4 : Remaining values
        else
            S4.push_back(x);
    }

    //-------------------------------------------------
    // Recursively create child subtrees
    //-------------------------------------------------
    root->child[0] = buildTree(S1);
    root->child[1] = buildTree(S2);
    root->child[2] = buildTree(S3);
    root->child[3] = buildTree(S4);

    // Return the root of this subtree
    return root;
}

//-----------------------------------------------------
// Function: preorder()
// Purpose : Print the tree using Preorder Traversal
//           and display the level of each node.
//-----------------------------------------------------
void preorder(Node* root, int level)
{
    // Base Case
    if(root == NULL)
        return;

    // Print current node and its level
    cout << "Node : " << root->data
         << "   Level : " << level << endl;

    // Recursively visit all four children
    for(int i = 0; i < 4; i++)
        preorder(root->child[i], level + 1);
}

//-----------------------------------------------------
// Main Function
//-----------------------------------------------------
int main()
{
    int n;

    // Input number of elements
    cout << "Enter Number of Elements : ";
    cin >> n;

    // Create a vector to store the sorted input
    vector<int> arr(n);

    cout << "Enter Sorted Elements:\n";

    // Read all elements
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    // Build the 4-way tree recursively
    Node* root = buildTree(arr);

    // Display the tree
    cout << "\nTree (Preorder Traversal)\n";

    preorder(root, 0);

    return 0;
}