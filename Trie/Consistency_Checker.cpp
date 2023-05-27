#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class Trie{
public:
    Trie* next[10];
    ll cnt; 
    bool endMark;  
    Trie()
    {
        for(int i = 0; i<10; i++) next[i] = NULL; 
        endMark = false; 
        cnt = 0; 
    }

    void Insert(Trie* root, string &s)
    {
        Trie* temp = root; 
        for(int i=0;i<(int)s.size(); i++)
        {
            if(temp->next[s[i]-'0'] == NULL) temp->next[s[i]-'0'] = new Trie();
            temp = temp->next[s[i]-'0']; 
            temp->cnt++; 
        }
        temp->endMark = true; 
    }

    bool query(Trie* root, string &s)
    {
        Trie* temp = root; 
        for(int i = 0; i<(int)s.size(); i++) temp = temp->next[s[i]-'0']; 

        return temp->cnt == 1; 
    }

    void Delete(Trie* root)
    {
        for(int i=0;i<10; i++) if(root->next[i])Delete(root->next[i]); 
        delete(root);
    }
};

void solve()
{
    ll n; 
    cin >> n; 
    vector<string> v(n);
    Trie* tr = new Trie();
    for(auto &i: v)
    {
        cin >> i; 
        tr->Insert(tr, i);
    }

    bool ok = true; 
    for(auto i: v)
    {
        ok = ok & (tr->query(tr, i)); 
    }
    if(ok) cout << "YES\n"; 
    else cout << "NO\n"; 

    tr->Delete(tr);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        cout << "Case " << t << ": ";
        solve();
    }
    return 0;
}