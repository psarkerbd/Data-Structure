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
    int data;
    Node *left , *right;
};

Node *newNode(int key)
{
    Node *tmp = new Node;

    tmp->data = key;
    tmp->left = tmp->right = NULL;
    return tmp;
}

Node *insert(Node *root , int key)
{
    if(root == NULL) return newNode(key);
    if(root->data >= key) root->left = insert(root->left , key);
    else root->right = insert(root->right , key);
    return root;
}

Node *lca(Node *root , int x , int y)
{
    if(root == NULL) return NULL;

    if(root->data > x && root->data > y) return lca(root->left , x , y);
    if(root->data < x && root->data < y) return lca(root->right , x , y);

    return root;
}

int main()
{
    fast;
    Node *root = new Node;
    root = NULL;
    int N , x;
    cin >> N >> x;
    root = insert(root , x);
    for(int i=1; i<N; i++)
    {
        cin >> x;
        insert(root , x);
    }

    int y;
    cin >> x >> y;
    cout << "Lowest Common Ancestor is : " << lca(root , x , y)->data << "\n";

    return 0;
}
