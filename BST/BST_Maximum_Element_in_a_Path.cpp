/*

->> BST finding maximum node from x to y;
->> Complexity O(BST Height)
->> Process:

        -> find Longest Common Ancestor LCA for x and y;
        -> then, mx1 = max(LCA , x);
        ->       mx2 = max(LCA , y);

    -> Finally, maximum node = max(mx1 , mx2)


*/

#include<bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0)
#define bfast cin.tie(0)
#define outs(x) cout << x << " "
#define outn(x) cout << x << "\n"
#define sf scanf
#define pf printf
#define nl puts("")
#define psb push_back
#define mset(c,v) memset(c , v , sizeof c)
#define loop0(n) for(int i=0; i<n; i++)
#define loop1(n) for(int i=1; i<=n; i++)
#define mpair(x , y) make_pair(x , y)
#define all(x) x.begin(), x.end()
#define pi acos(-1.0)
#define psb push_back
#define clr clear

typedef unsigned long long ull;
typedef long long LL;
typedef vector<int>vii;
typedef vector<LL>vll;
typedef vector<string>vs;
typedef map<int, int>mpii;
typedef map<string, int>mpsi;
typedef map<char, int>mpci;
typedef map<LL, LL>mpll;

const int mod = 1000007;
const int high = 1002;

struct Node
{
    int key;
    Node *left , *right;
};

Node *newNode(int data)
{
    Node *tmp = new Node;

    tmp->key = data;
    tmp->left = tmp->right = NULL;

    return tmp;
}

Node *insert(Node *root , int data)
{
    if(root == NULL) return newNode(data);

    if(root->key >= data) root->left = insert(root->left , data);
    else root->right = insert(root->right , data);

    return root;
}

int max_element_in_path(Node *root , int var)
{
    Node *curr = root;

    int maxi = 0;

    while(curr->key != var)
    {
        if(curr->key > var)
        {
            maxi = max(maxi , curr->key);
            curr = curr->left;
        }

        else if(curr->key < var)
        {
            maxi = max(maxi , curr->key);
            curr = curr->right;
        }
    }

    return max(maxi , var);
}

int find_maximum(Node *root , int x , int y)
{
    Node *curr = root;

    // finding Longest Common Ancestor

    while((x > curr->key && y > curr->key) || (x < curr->key && y < curr->key))
    {
        if(curr->key > x && curr->key > y) curr = curr->left;
        else if(curr->key < x && curr->key < y) curr = curr->right;
    }

    return max(max_element_in_path(curr , x) , max_element_in_path(curr , y));
}

int main()
{
    fast;
    Node *root = new Node;
    root = NULL;
    int N;
    cin >> N;
    int x;
    cin >> x;
    root = insert(root , x);
    for(int i=1; i<N; i++)
    {
        cin >> x;
        insert(root , x);
    }

    int y;
    cin >> x >> y;
    //cout << "Maximum Node is " << find_maximum(root , x , y) << "\n";
    cout << find_maximum(root , x , y) << "\n";

    return 0;
}
