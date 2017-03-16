#include<bits/stdc++.h>
using namespace std;

// Create a Node

struct Node
{
    int key;
    Node *left , *right;
};

// A utility function to create a new BST node

Node *newNode(int item)
{
    Node *temp = (struct Node *)malloc(sizeof(struct Node));

    temp->key = item;
    temp->left = temp->right = NULL;

    return temp;
}

Node *insert(Node* root , int data)
{
    if(root == NULL) return newNode(data);

    if(data < root->key)
    {
        root->left = insert(root->left , data);
    }

    else if(data > root->key)
    {
        root->right = insert(root->right , data);
    }

    return root;
}

// Traversal inorder

void preorder(Node *node)
{
    if(node)
    {
        cout << node->key << "; ";

        preorder(node->left);

        preorder(node->right);
    }
}

int main()
{
    freopen("in.txt" , "r" , stdin);
    int n , x;

    while(cin >> n)
    {
        //cout << "hello";

        struct Node *root = NULL;

        cin >> x;

        root = insert(root , x);

        for(int i=1; i<n; i++)
        {
            x;
            cin >> x;

            insert(root , x);
        }

        //preorder(root);
    }

    return 0;
}

/*

input:
6
10 2 5 6 8 3

Result hoyar kotha:
10 2 6 5 8 3

But hoy
10; 2; 5; 3; 6; 8;


*/
