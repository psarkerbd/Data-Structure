#include<bits/stdc++.h>
using namespace std;

const int high = 30;

// making a node

struct node
{
    node *next[high];
    bool endmark;

    node() // constructor
    {
        endmark = false;

        for(int i=0; i<high; i++)
        {
            next[i] = NULL;
        }
    }
}*root;

void tree_insert(string s , int len)
{
    int id = 0;
    node *curr = root;

    for(int i=0; i<len; i++)
    {
        id = s[i] - 'a'; // compress into integers
        //cout << id+2 << "; ";

        if(curr->next[id] == NULL)
        {
            curr->next[id] = new node();
            curr = curr->next[id];
            //cout << curr->next[id] << "; ";
        }
    }

    curr->endmark = true;
}

bool tree_search(string s, int len)
{
    node *curr = root;
    int id = 0;

    for(int i=0; i<len; i++)
    {
        id = s[i] - 'a'; // compress into integers

        if(curr->next[id] == NULL)
        {
            return false;
        }

        curr = curr->next[id];
    }

    return curr->endmark;
}

void tree_delete(node *curr)
{
    for(int i=0; i<high-4; i++)
    {
        if(curr->next[i])
        {
            tree_delete(curr->next[i]);
        }
    }

    delete(curr);
}

int main()
{
    root = new node(); // called that constructor
    int t;
    cout << "Test Case: ";
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        tree_insert(s , s.length());
    }

    int Q;
    cout << "Query: ";
    cin >> Q;
    while(Q--)
    {
        string s;
        cin >> s;
        if(tree_search(s , s.length())) cout << "Exist on the dictionary\n";
        else cout << "Not exist on the dictionary\n";
    }

    tree_delete(root);

    return 0;
}
