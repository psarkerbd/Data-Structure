#include<bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0)

const int high = 10;
const int N = 200000;
const int NILL = -1;

int trielen = 0;

struct node
{
    bool endmark;
    int next[high];
};

node trie[N];

void refresh_node(int n)
{
    trie[n].endmark = false;

    for(int i=0; i<high; i++)
    {
        trie[n].next[i] = NILL;
    }
}

bool tree_insert(string s)
{
    int in = 0 , id = 0 , len = s.length(), i;

    for(i=0; i<len; i++)
    {
        id = s[i] - 48;

        if(trie[in].next[id] == NILL)
        {
            refresh_node(trielen);

            trie[in].next[id] = trielen++;

            //trielen+=1;
        }

        in = trie[in].next[id];

        if(trie[in].endmark) return true;
    }

    for(i=0; i<high; i++)
    {
        if(trie[in].next[i] != NILL) return true;
    }

    trie[in].endmark = true;

    return false;
}

int main()
{
    fast;
    int test;
    bool suffix = false;
    cin >> test;
    while(test--)
    {
        int Q;
        suffix = false;
        refresh_node(0);
        trielen = 1;

        cin >> Q;

        while(Q--)
        {
            string str;
            cin >> str;

            if(!suffix)
            {
                suffix = tree_insert(str);
            }
        }

        if(suffix) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}
