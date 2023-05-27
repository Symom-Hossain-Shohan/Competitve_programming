#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


class Trie
{
public:
    Trie* next[2];

    Trie()
    {
        next[0] = NULL, next[1] = NULL; 
    }

    void Insert(Trie* root, ll n)
    {
        Trie* temp = root; 
        for(int i=31; i>=0; i--)
        {
            ll x = (n>>i) & 1; 
            //cout << x; 
            if(temp->next[x]!=NULL) temp = temp->next[x];
            else 
            {
                temp->next[x] = new Trie();
                temp = temp->next[x];
            }
        }
    }

    ll findMax(Trie* root, ll n)
    {
        Trie* temp = root; 
        ll res = 0; 
        for(int i=31; i>=0; i--)
        {
            ll x = (n>>i) & 1; 
            if(temp->next[(x^1)]!= NULL)
            {
                temp = temp->next[(x^1)]; 
                res += (x^1) * ((1ll)<<i);
            }
            else 
            {
                temp = temp->next[x];
                res += (x) * ((1ll)<<i);
            }
        }
        //cout << res; 
        return res; 
    }

    ll findMin(Trie* root, ll n)
    {
        Trie* temp = root; 
        ll res = 0; 
        for(int i=31; i>=0; i--)
        {
            ll x = (n>>i)&1; 
            if(temp->next[x]!=NULL)
            {
                temp = temp->next[x]; 
                res += (x)*((1ll)<<i); 
            }
            else 
            {
                temp = temp->next[(x^1)]; 
                res += (x^1) * ((1ll)<<i);
            }
        }
        return res;
    }

    void Delete(Trie* root)
    {
        for(int i=0; i<2; i++)
        {
            if(root->next[i]!=NULL) Delete(root->next[i]); 
        }
        delete(root);
    }


};

void solve()
{
    ll n; 
    cin >> n; 
    vector<ll> v(n);
    for(auto &i: v) cin >> i; 
    Trie* tr = new Trie();
    tr->Insert(tr, v[0]);
   
    ll xr = v[0], mxAns = v[0], mnAns = v[0];
    for(int i=1;i<n; i++)
    {
        xr = xr ^ v[i];
        ll y = tr->findMax(tr, xr);
        mxAns = max({mxAns, xr, (xr^y)});
        y = tr->findMin(tr, xr);
        mnAns = min({mnAns, xr, (xr^y)});  
        tr->Insert(tr, xr);
    }

    cout << mxAns << ' ' << mnAns << endl; 

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