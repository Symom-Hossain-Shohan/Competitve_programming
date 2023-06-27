#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll N = 15e4 + 5; 
ll tree[4*N + 5];
ll lazy[4*N + 5];


void update(ll s, ll e, ll l, ll r, ll val, ll node)
{
    if(lazy[node])
    {
        tree[node] += lazy[node]; 
        if(s!=e)
        {
            lazy[2*node] += lazy[node]; 
            lazy[2*node+1] += lazy[node]; 
        }

        lazy[node] = 0; 
    }

    if(s>r or e<l) return; 
    if(s>=l and e<=r) 
    {
        tree[node] += val; 
        if(s!=e)
        {
            lazy[2*node] += val; 
            lazy[2*node+1] += val; 
        }
        return; 
    }

    ll mid = (s+e)/2; 
    update(s, mid, l, r, val, 2*node); 
    update(mid+1, e, l, r, val, 2*node+1); 

    tree[node] = tree[2*node] + tree[2*node+1]; 
    return; 
}

ll query(ll s, ll e, ll ix, ll node)
{
    if(lazy[node])
    {
        tree[node] += lazy[node]; 
        if(s!=e)
        {
            lazy[2*node] += lazy[node]; 
            lazy[2*node+1] += lazy[node]; 
        }
        lazy[node] = 0; 
    }

    if(ix<s or ix>e ) return 0; 
    if(s>=ix and e<=ix) return tree[node]; 
    ll mid = (s+e)/2; 
    ll left = query(s, mid, ix, 2*node); 
    ll right = query(mid+1, e, ix, 2*node+1); 
    return left + right; 
}


void solve()
{
    memset(tree, 0, sizeof(tree)); 
    memset(lazy, 0, sizeof(lazy)); 

    ll n, q; 
    cin >> n >> q; 
    vector<ll> v, vq; 
    vector<pair<ll,ll>> vp;

    for(int i=0;i<n;i++)
    {
        ll l, r; 
        cin >> l >> r; 
        if(l>r) swap(l, r); 

        v.push_back(l), v.push_back(r); 
        vp.push_back({l, r}); 
    }

    for(int i=0;i<q; i++) 
    {
        ll x; 
        cin >> x; 
        vq.push_back(x); 
        v.push_back(x); 
    }

    sort(v.begin(), v.end()); 

    unordered_map<ll,ll> mp; 
    for(int i=0;i<v.size(); i++) mp[v[i]] = i+1; 

    for(int i=0;i<n;i++)
    {
        ll l = mp[vp[i].first], r = mp[vp[i].second]; 

        update(1, v.size(), l, r, 1, 1); 
    }

    for(int i = 0;i<q; i++)
    {
        ll x = mp[vq[i]]; 
        cout << query(1, v.size(), x, 1) << endl; 
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