#include <iostream>
#include <queue>
#include <stack>
using namespace std;

//==============================
// Node Structure
//==============================
struct Node
{
    float data;
    Node *left;
    Node *right;
};

//==============================
// Create New Node
//==============================
Node* createNode(float value)
{
    Node* temp = new Node;

    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

//==============================
// Insert in Binary Tree
// (Level Order / Heap Style)
//==============================
Node* insert(Node* root, float value)
{
    Node* newNode = createNode(value);

    // First node
    if(root == NULL)
        return newNode;

    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        // Insert at first empty left child
        if(temp->left == NULL)
        {
            temp->left = newNode;
            return root;
        }
        else
            q.push(temp->left);

        // Insert at first empty right child
        if(temp->right == NULL)
        {
            temp->right = newNode;
            return root;
        }
        else
            q.push(temp->right);
    }

    return root;
}

//==============================
// DFS Search Using Stack
//==============================
bool DFS_Search(Node* root, float x)
{
    if(root == NULL)
        return false;

    stack<Node*> st;
    st.push(root);

    while(!st.empty())
    {
        Node* current = st.top();
        st.pop();

        // Value Found
        if(current->data == x)
            return true;

        // Push Right First
        if(current->right != NULL)
            st.push(current->right);

        // Push Left Second
        if(current->left != NULL)
            st.push(current->left);
    }

    return false;
}

//==============================
// Preorder Traversal
// Without Recursion
//==============================
void preorderIterative(Node* root)
{
    if(root == NULL)
        return;

    stack<Node*> st;
    st.push(root);

    cout << "\nPreorder Traversal : ";

    while(!st.empty())
    {
        Node* current = st.top();
        st.pop();

        cout << current->data << " ";

        // Push Right First
        if(current->right != NULL)
            st.push(current->right);

        // Push Left Second
        if(current->left != NULL)
            st.push(current->left);
    }

    cout << endl;
}

//==============================
// Main Function
//==============================
int main()
{
    Node* root = NULL;

    int n;
    float value, x;

    cout << "Enter Number of Nodes: ";
    cin >> n;

    cout << "Enter Float Values:\n";

    for(int i = 0; i < n; i++)
    {
        cin >> value;
        root = insert(root, value);
    }

    // Display using Preorder (Iterative)
    preorderIterative(root);

    // Search using DFS
    cout << "\nEnter Value to Search: ";
    cin >> x;

    if(DFS_Search(root, x))
        cout << x << " Found in Binary Tree." << endl;
    else
        cout << x << " Not Found in Binary Tree." << endl;

    return 0;
}