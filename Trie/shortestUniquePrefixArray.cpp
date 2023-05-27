#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class Node{
public:  
    char data; 
    int cnt;  
    unordered_map<char, Node*> children;  
    bool terminal; 
    Node(char d)
    {
        data = d; 
        cnt = 1; 
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
            if(temp->children.count(s[i])) 
            {
                temp = temp->children[s[i]]; 
                temp->cnt++; 
            }
            else 
            {
                Node* n = new Node(s[i]); 
                temp->children[s[i]] = n; 
                temp = n;  
            }
        }
        temp->terminal = true; 
    }

    void find(string &s)
    {
        Node* temp = root; 
        string ans; 
        bool ok = false; 
        for(int i=0; i<(int)s.size(); i++)
        {
            temp = temp->children[s[i]]; 
            ans.push_back(s[i]); 
            if(temp->cnt==1) 
            {
                ok = true; 
                break;
            }
        }
        if(ok) cout << ans << endl; 
        else cout << -1 << endl; 
         
    }

};

void solve()
{
    ll n; 
    cin >> n; 
    Trie tr; 
    vector<string> v(n);
    for(auto &i: v) cin >> i, tr.insert(i);

    for(auto i: v) tr.find(i);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}