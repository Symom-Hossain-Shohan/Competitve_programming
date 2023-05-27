#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
map<char, ll> mp = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}}; 

class Trie{
public:
    Trie* next[4];
    ll cnt; 
    bool endMark;  
    Trie()
    {
        for(int i = 0; i<4; i++) next[i] = NULL; 
        endMark = false; 
        cnt = 0; 
    }

    void Insert(Trie* root, string &s)
    {
        Trie* temp = root; 
        for(int i=0;i<(int)s.size(); i++)
        {
            if(temp->next[mp[s[i]]] == NULL) temp->next[mp[s[i]]] = new Trie();
            temp = temp->next[mp[s[i]]]; 
            temp->cnt++; 
        }
        temp->endMark = true; 
    }
    void Delete(Trie* root)
    {
        for(int i=0;i<4; i++) if(root->next[i])Delete(root->next[i]); 
        delete(root);
    }

    ll query(Trie* root, string &s)
    {
        ll ans = 0; 
        Trie* temp = root; 
        for(int i=0;i<(int)s.size(); i++)
        {
            temp = temp->next[mp[s[i]]]; 
            ans = max(ans, (i+1)*temp->cnt); 
        }

        return ans; 
    }
};

void solve()
{
    ll n; 
    cin >> n;
    vector<string> v(n);
    Trie* tr = new Trie(); 
    for(auto &i: v) cin >> i, tr->Insert(tr, i); 

    ll ans = 0; 
    for(auto i: v)
    {
        ans = max(ans, tr->query(tr, i)); 
    }

    cout << ans << endl; 
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