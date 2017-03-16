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

// a new node or starting node

Node *newNode(int data)
{
    Node *tmp = new Node;

    tmp -> key = data;
    tmp->left = tmp->right=NULL;

    return tmp;
}

Node *insert(Node *root , int data)
{
    if(root == NULL) return newNode(data);

    if(root->key < data) root->right = insert(root->right , data);

    else if(root->key > data) root->left = insert(root->left , data);

    return root;
}

bool search(Node *root , int data)
{
    if(root)
    {
        if(root->key == data) return true;

        if(root->key < data) return search(root->right , data);
        else return search(root->left , data);
    }

    else root = NULL;

    if(root != NULL) return true;
    else return false;
}

int main()
{
    //freopen("in.txt" , "r" , stdin);

    int n;

    Node *root = NULL;

    cin >> n;

    int x;

    cin >> x;

    root = insert(root , x);

    for(int i=1; i<n; i++)
    {
        cin >> x;

        insert(root , x);
    }

    cin >> x;

    if(search(root , x)) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
