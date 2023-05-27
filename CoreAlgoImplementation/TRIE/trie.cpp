#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class Node{
public:  
    char data; 
    unordered_map<char, Node*> children; 
    bool terminal; 
    Node(char d)
    {
        data = d; 
        terminal = false; 
    }
};

class Trie{
public : 
    Node* root; 
    int cnt; 
    Trie()
    {
        root = new Node('\0'); 
        cnt = 0; 
    }

    void insert(string &s)
    {
        Node* temp = root; 
        for(int i=0;i<(int)s.size(); i++)
        {
            if(temp->children.count(s[i])) temp = temp->children[s[i]]; 
            else 
            {
                Node* n = new Node(s[i]); 
                temp->children[s[i]] = n; 
                temp = n; 
            }
        }
        temp->terminal = true; 
    }

    bool find(string &s)
    {
        Node* temp = root; 
        for(int i=0; i<(int)s.size(); i++)
        {
            if(temp->children.count(s[i])==0) return false; 
            else temp = temp->children[s[i]]; 
        }
        return temp->terminal; 
    }

};

void solve()
{
    ll n; 
    cin >> n; 
    Trie tr; 
    for(int i=0;i<n; i++)
    {
        string s; 
        cin >> s; 
        tr.insert(s); 
    }
    ll q; 
    cin >> q; 
    while(q--)
    {
        string s; 
        cin >> s; 
        if(tr.find(s)) cout << "Present\n"; 
        else cout << "Not Present\n"; 
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    //cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}