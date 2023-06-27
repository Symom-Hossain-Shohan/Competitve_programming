#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 1e5 + 5; 

ll ar[N];
ll tree[4*N + 5];
ll lazy[4*N + 5];


void buildTree(ll start, ll end, ll index)
{
    if(start == end)
    {
        tree[index] = ar[start]; 
        return; 
    }

    ll mid = (start + end)/2; 

    buildTree(start, mid, 2*index); 
    buildTree(mid+1, end, 2*index+1); 

    tree[index] = min(tree[2*index], tree[2*index+1]); 
    return; 
}


void lazyUpdate(ll s, ll e, ll l,ll r, ll inc, ll index)
{
    if(lazy[index])
    {
        tree[index] += lazy[index]; 
        if(s!=e)
        {
            lazy[2*index] += lazy[index]; 
            lazy[2*index+1] += lazy[index]; 
        }

        lazy[index] = 0; 
    }


    if(e<l or s>r) return; 
    if(s>=l and e<=r)
    {
        tree[index] += inc; 
        if(s!=e)
        {
            lazy[2*index] += inc; 
            lazy[2*index+1] += inc; 
        }
        return; 
    }

    ll mid = (s+e)/2; 
    lazyUpdate(s, mid, l, r, inc, 2*index);
    lazyUpdate(mid+1, e, l, r, inc, 2*index+1);

    tree[index]  = min(tree[2*index], tree[2*index+1]); 
    return; 
}


ll lazyQuery(ll s, ll e, ll l, ll r, ll index)
{
    if(lazy[index])
    {
        tree[index] += lazy[index]; 

        if(s!=e)
        {
            lazy[2*index] += lazy[index]; 
            lazy[2*index+1] += lazy[index]; 
        }

        lazy[index] = 0; 
    }

    if(s>r or e<l) return INT_MAX; 

    if(s>=l or e<=r) return tree[index];

    ll mid = (s+e)/2; 

    ll left = lazyQuery(s, mid, l, r, 2*index); 
    ll right = lazyQuery(mid+1, e, l, r, 2*index+1); 

    return tree[index] = min(left, right); 
}


void solve()
{
    ll n; 
    cin >> n; 
    for(int i = 0;i<n; i++) cin >> ar[i]; 
    buildTree(0, n-1, 1);
    




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
