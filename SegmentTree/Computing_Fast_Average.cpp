#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 1e5 + 5; 
ll ar[N];
ll tree[4*N + 5];
ll lazy[4*N + 5];

void update(ll s, ll e, ll l, ll r, ll val, ll index)
{
    if(lazy[index]!=-1)
    {
        tree[index] = (e-s+1) * lazy[index]; 
        if(s!=e)
        {
            lazy[2*index] = lazy[index]; 
            lazy[2*index+1] = lazy[index];
        }
        lazy[index] = -1; 
    }

    if(e<l or s>r) return; 
    if(s>=l and e<=r)
    {
        tree[index] = (e-s+1) * (val); 
        if(s!=e)
        {
            lazy[2*index] = val; 
            lazy[2*index+1] = val; 
        }
        return; 
    }

    ll mid = (s+e)/2; 
    update(s, mid, l, r, val, 2*index); 
    update(mid+1, e, l, r, val, 2*index+1); 

    tree[index] = tree[2*index] + tree[2*index+1]; 
    return; 
}

ll query(ll s, ll e, ll l, ll r, ll index)
{
    if(lazy[index]!=-1)
    {
        tree[index] = (e-s+1) * lazy[index]; 
        if(s!=e)
        {
            lazy[2*index] = lazy[index]; 
            lazy[2*index+1] = lazy[index];
        }
        lazy[index] = -1; 
    }

    if(e<l or s>r) return 0; 

    if(s>=l and e<=r) return tree[index]; 

    ll mid = (s+e)/2; 
    ll left = query(s, mid, l, r, 2*index); 
    ll right = query(mid+1, e, l, r, 2*index+1); 

    return left + right; 
}

void solve()
{
    ll n, q; 
    cin >> n >> q; 
    memset(tree, 0, sizeof(tree)); 
    memset(lazy, -1, sizeof(lazy)); 


    while(q--)
    {
        ll  ch; 
        cin >> ch; 
        if(ch==1)
        {
            ll i, j, v; 
            cin >> i >> j >> v; 
            update(1, n, i+1, j+1, v, 1); 
        }
        else 
        {
            ll i, j; 
            cin >> i >> j; 
            ll nom = query(1, n, i+1, j+1, 1);
            ll denom = j-i+1; 
            ll gcd = __gcd(nom, denom); 
            nom /= gcd; 
            denom /= gcd; 
            if(denom==1) cout << nom << endl; 
            else cout << nom << "/" << denom << endl; 
        }
    }
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