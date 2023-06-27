#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 1e5 + 5; 

ll ar[N];
ll tree[4*N + 5];


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


int query(ll s, ll e, ll qs, ll qe, ll index)
{
    if(s>=qs and e <=qe)
    {
        return tree[index]; 
    }
    if(s>qe or e<qs) return INT_MAX; 

    ll mid = (s+e)/2; 

    ll left = query(s, mid, qs, qe, 2*index); 
    ll right = query(mid+1, e, qs, qe, 2*index+1); 
    return min(left, right); 
}


void update(ll s, ll e, ll l, ll r, ll inc, ll index)
{
    if(l>e or r<s) return; 

    if(s==e)
    {
        tree[index] += inc; 
        return; 
    }

    ll mid = (s+e)/2; 

    update(s, mid, l, r, inc, 2*index); 
    update(mid+1, e, l, r, inc, 2*index+1); 

    tree[index] = min(tree[2*index], tree[2*index+1]); 
    return; 

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
