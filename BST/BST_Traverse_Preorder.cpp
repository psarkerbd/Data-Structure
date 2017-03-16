#include<bits/stdc++.h>
using namespace std;

#define psb push_back

const int high = 100;
typedef vector<int>vii;
typedef map<int , int>mpii;

vii adj[high] , storeu , storev;
int visited[high];
mpii mp;

struct Node
{
    int key;
    Node *left , *right;
};

Node *newNode(int data)
{
    Node *temp = new Node;

    temp->key = data;
    temp->left = temp->right = NULL;

    return temp;
}

Node *insert(Node *root , int data)
{
    if(root == NULL) return newNode(data);

    if(root->key <= data)
    {
        root->right = insert(root->right , data);
    }

    else if(root->key >= data)
    {
        root->left = insert(root->left , data);
    }

    return root;
}

// Preorder Traverse

void Preorder(Node *root)
{
    if(root)
    {
        cout << root->key << "; ";

        Preorder(root->left);

        Preorder(root->right);
    }
}

int main()
{
    freopen("in.txt" , "r" , stdin);
    int n , x;
    while(cin >> n)
    {
        Node *root = new Node;

        root = NULL;

        cin >> x;

        root = insert(root , x);

        for(int i=1; i<n; i++)
        {
            cin >> x;

            insert(root , x);
        }

        cout << "Preorder Traverse:\n";

        Preorder(root);
    }

    return 0;
}

/*

input:

6
10 2 5 6 8 3

*/
