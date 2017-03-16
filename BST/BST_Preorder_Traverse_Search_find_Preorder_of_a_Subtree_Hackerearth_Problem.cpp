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
        Node *tmp = new Node;

        tmp -> key = data;
        tmp -> right = tmp -> left = NULL;

        return tmp;
}

Node *insert(Node *root , int data)
{
    if(root == NULL) return newNode(data);

    if(root->key < data) root -> right = insert(root -> right , data);
    else if(root->key > data) root -> left = insert(root -> left , data);

    return root;
}


void Preorder(Node *root , int x)
{
    if(root)
    {
//        if(root->key == x)
//        {
//            f=true;
//        } //cout << root -> key << "\n";

//        if(!f)
//        {
//            cout << root -> key << "\n";
//        }

        cout << root -> key << "\n";

        Preorder(root -> left , x);

        Preorder(root -> right , x);
    }
}

Node *search(Node *ptr , int data)
{
    if(ptr -> key == data || ptr == NULL) return ptr;

    if(ptr -> key < data) return search(ptr -> right , data);

    else return search(ptr -> left , data);
}

int main()
{
    ios_base::sync_with_stdio(false);

    Node *root = NULL , *ptr;

    int n , i;

    cin >> n;

    int x;

    cin >> x;

    root = insert(root , x);

    for(i=1; i<n; i++)
    {
        cin >> x;

        insert(root , x);
    }

    cin >> x;

    ptr = search(root , x);
    //cout << ptr ;

    //root = insert(root , x);

    //root->key = x;

    Preorder(ptr , x);

    return 0;
}
