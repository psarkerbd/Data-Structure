/*

-> At first find the In-order traversing of complete Binary Tree then store the values into an array
->> Finally that array sorting process is the answer

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
const int high = 1e5 + 5;

int arr[high] , brr[high] , sorted[high], unsorted[high] , N , blen=1;

void Inorder(int root)
{
    int Left = root << 1;
    int Right = Left + 1;

    if(Left <= N) Inorder(Left);
    brr[blen++] = arr[root];
    if(Right <= N) Inorder(Right);
}

int main()
{
    fast;
    int i;
    cin >> N;

    for(i=1; i<=N; i++)
    {
        cin >> arr[i];
    }

    Inorder(1);

    sort(arr, arr+N+1);

    for(i=1; i<=N; i++)
    {
        sorted[arr[i]] = i;
    }

    for(i=1; i<=blen; i++)
    {
        unsorted[brr[i]] = i;
    }

    int cnt = 0;

    for(i=1; i<=N; i++)
    {
        if(arr[i] != brr[i])
        {
            int soin = sorted[arr[i]];
            int tmp = unsorted[arr[i]];

            swap(brr[soin] , brr[tmp]);
            unsorted[brr[soin]] = soin;
            unsorted[brr[tmp]] = tmp;

            cnt+=1;

        }
    }

    cout << cnt << "\n";

    return 0;
}
