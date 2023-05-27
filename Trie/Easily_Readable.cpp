#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class Trie
{
public:
    Trie* next[200];
    ll endMark; 
    Trie()
    {
        endMark = 0; 
        for(int i=0;i<200; i++) next[i] = NULL; 
    }

    void Insert(Trie* root, string &s)
    {
        Trie* temp = root; 
        if(s.size()>2) sort(s.begin()+1, s.end()-1); 

        for(int i=0;i<(int)s.size(); i++)
        {
            ll ix = s[i] - 'a'; 
            if(temp->next[ix]==NULL) temp->next[ix] = new Trie();
            temp = temp->next[ix];
        }
        temp->endMark += 1; 
    }

    ll search(Trie* root, string &s)
    {
        Trie* temp = root; 
        if(s.size()>2) sort(s.begin()+1, s.end()-1); 
        for(int i=0;i<(int)s.size(); i++)
        {
            if(temp->next[s[i]-'a']==NULL) return 0; 
            else temp =  temp->next[s[i]-'a'] ; 
        }
        return temp->endMark; 
    }

    void Delete(Trie* root)
    {
        for(int i=0;i<200; i++) if(root->next[i]) Delete(root->next[i]); 
        delete(root);
    }
};

void solve()
{
    ll n; 
    cin >> n; 
    Trie* tr = new Trie();
    for(int i = 0; i<n; i++)
    {
        string s; 
        cin >> s; 
        tr->Insert(tr, s);
    }

    ll m; 
    cin >> m; 
    for(int i=0;i<m; i++)
    {
        string p; 
        char ch; 
        cin >> ch; 
        getline(cin, p);
        p = ch + p; 
        string s; 
        ll ans = 1; 
        for(int j=0;j <(int)p.size(); j++)
        {
            if(p[j]==' ')
            {
                ans *= tr->search(tr, s);
                s.clear();
            }
            else s += p[j];
        }

        ans *= tr->search(tr, s);
        cout << ans << endl; 
    }

    tr->Delete(tr);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        cout << "Case " << t << ":\n";
        solve();
    }
    return 0;
}