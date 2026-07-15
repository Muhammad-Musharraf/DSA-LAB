#include <iostream>
#include <queue>
#include <string>
using namespace std;

//--------------------------------------------------
// Node Structure
//--------------------------------------------------
struct Node
{
    string data;      // Store string value
    Node *left;       // Left child
    Node *right;      // Right child
};

//--------------------------------------------------
// Create New Node
//--------------------------------------------------
Node* createNode(string value)
{
    Node* temp = new Node;

    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

//--------------------------------------------------
// Insert in Level Order (Heap Style)
//--------------------------------------------------
Node* insert(Node* root, string value)
{
    Node* newNode = createNode(value);

    if(root == NULL)
        return newNode;

    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if(temp->left == NULL)
        {
            temp->left = newNode;
            return root;
        }
        else
            q.push(temp->left);

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

//--------------------------------------------------
// Mirror Image
//--------------------------------------------------
void mirror(Node* root)
{
    if(root == NULL)
        return;

    swap(root->left, root->right);

    mirror(root->left);
    mirror(root->right);
}

//--------------------------------------------------
// Level Order Traversal
//--------------------------------------------------
void levelOrder(Node* root)
{
    if(root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if(temp->left)
            q.push(temp->left);

        if(temp->right)
            q.push(temp->right);
    }

    cout << endl;
}

//--------------------------------------------------
// Find Predecessor and Successor (Level Order)
//--------------------------------------------------
void predecessorSuccessor(Node* root, string key)
{
    if(root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    Node* prev = NULL;

    while(!q.empty())
    {
        Node* current = q.front();
        q.pop();

        if(current->data == key)
        {
            cout << "Predecessor : ";

            if(prev)
                cout << prev->data;
            else
                cout << "None";

            cout << endl;

            cout << "Successor : ";

            if(!q.empty())
                cout << q.front()->data;
            else
                cout << "None";

            cout << endl;

            return;
        }

        prev = current;

        if(current->left)
            q.push(current->left);

        if(current->right)
            q.push(current->right);
    }

    cout << "Element Not Found\n";
}

//--------------------------------------------------
// Find Level
//--------------------------------------------------
int findLevel(Node* root, string key, int level)
{
    if(root == NULL)
        return -1;

    if(root->data == key)
        return level;

    int left = findLevel(root->left, key, level + 1);

    if(left != -1)
        return left;

    return findLevel(root->right, key, level + 1);
}

//--------------------------------------------------
// Find Height of Node
//--------------------------------------------------
int height(Node* root)
{
    if(root == NULL)
        return -1;

    return 1 + max(height(root->left), height(root->right));
}

Node* search(Node* root, string key)
{
    if(root == NULL)
        return NULL;

    if(root->data == key)
        return root;

    Node* left = search(root->left, key);

    if(left)
        return left;

    return search(root->right, key);
}

//--------------------------------------------------
// Main Function
//--------------------------------------------------
int main()
{
    Node* root = NULL;

    int n;
    string value;

    cout << "Enter Number of Nodes: ";
    cin >> n;

    cout << "Enter String Values:\n";

    for(int i = 0; i < n; i++)
    {
        cin >> value;
        root = insert(root, value);
    }

    cout << "\nOriginal Tree (Level Order): ";
    levelOrder(root);

    string x;
    cout << "\nEnter element to search: ";
    cin >> x;

    predecessorSuccessor(root, x);

    int level = findLevel(root, x, 0);

    if(level != -1)
        cout << "Level = " << level << endl;
    else
        cout << "Element Not Found\n";

    Node* temp = search(root, x);

    if(temp)
        cout << "Height = " << height(temp) << endl;

    mirror(root);

    cout << "\nMirror Tree (Level Order): ";
    levelOrder(root);

    return 0;
}