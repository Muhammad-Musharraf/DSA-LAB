#include <iostream>
#include <queue>
using namespace std;

// Node Structure
struct Node
{
    float data;
    Node *left;
    Node *right;
};

// Create New Node
Node* createNode(float value)
{
    Node* temp = new Node;
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Insert in Level Order (Heap Style)
Node* insert(Node* root, float value)
{
    Node* newNode = createNode(value);

    if (root == NULL)
        return newNode;

    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if (temp->left == NULL)
        {
            temp->left = newNode;
            return root;
        }
        else
            q.push(temp->left);

        if (temp->right == NULL)
        {
            temp->right = newNode;
            return root;
        }
        else
            q.push(temp->right);
    }

    return root;
}

// Mirror Image Function
void mirror(Node* root)
{
    if (root == NULL)
        return;

    // Swap left and right child
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}

// Level Order Traversal
void levelOrder(Node* root)
{
    if (root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if (temp->left)
            q.push(temp->left);

        if (temp->right)
            q.push(temp->right);
    }
}

int main()
{
    Node* root = NULL;
    int n;
    float value;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter node values:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        root = insert(root, value);
    }

    cout << "\nOriginal Tree (Level Order): ";
    levelOrder(root);

    mirror(root);

    cout << "\nMirror Tree (Level Order): ";
    levelOrder(root);

    cout << endl;

    return 0;
}