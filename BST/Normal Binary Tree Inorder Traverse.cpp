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

int ar[high] , N;

void Inorder(int root)
{
    int left = root << 1;
    int right = left + 1;

    if(left <= N) Inorder(left);
    cout << ar[root] << "; ";
    if(right <= N) Inorder(right);
}

//void Post(int root)
//{
//    int left = root << 1;
//    int right = left + 1;
//
//    if(left <= N) Post(left);
//    if(right <= N) Post(right);
//    cout << ar[root] << "; ";
//}

int main()
{
    fast;
    //int x = 1 << 1;
    //outn(x);
    cin >> N;
    for(int i=1; i<=N; i++)
    {
        cin >> ar[i];
    }

    //Inorder(1); // send to first index
    //Post(1);

    return 0;
}
