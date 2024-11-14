#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node *left, *right;

    Node(int val)
    {
        key = val;
        left = right = nullptr;
    }
};

Node *insert(Node *root, int key)
{
    if (root == nullptr)
    {
        return new Node(key); 
    }
    if (key < root->key)
    {
        root->left = insert(root->left, key);
    }
    else
    {
        root->right = insert(root->right, key);
    }

    return root;
}

void inorder(Node *root)
{
    if (root != nullptr)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

Node *search(Node *root, int key)
{
    if (root == nullptr || root->key == key)
    {
        return root;
    }
    if (key > root->key)
    {
        return search(root->right, key);
    }

    return search(root->left, key);
}

int main()
{
    Node *root = nullptr;
    int n, value, searchKey;

    cout << "Enter the number of values to insert in the BST: ";
    cin >> n;

    cout << "Enter the values to insert: ";
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        root = insert(root, value);
    }

    cout << "In-order traversal of the BST: ";
    inorder(root);
    cout << endl;

    cout << "Enter the value to search in the BST: ";
    cin >> searchKey;

    Node *result = search(root, searchKey);

    if (result != nullptr)
    {
        cout << "Value " << searchKey << " found in the BST" << endl;
    }
    else
    {
        cout << "Value " << searchKey << " not found in the BST" << endl;
    }

    return 0;
}
