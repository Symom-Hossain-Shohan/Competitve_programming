#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll N = 3e4 + 5; 

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

ll query(ll s, ll e, ll val, ll index)
{
    if(s==e) 
    {
        if(tree[index]>=val) return val; 
        else return 0; 
    }
    if(tree[index]>=val) return (e-s+1)*val;
    else {
        ll mid = (s+e)/2; 
         return query(s, mid, val, 2*index) + query(mid+1, e, val, 2*index+1); 
    }  

    
}

void solve()
{
    ll n; 
    cin >> n; 
    for(int i=0;i<n;i++) cin >> ar[i];

    buildTree(0, n-1, 1); 

    ll ans = 0; 
    for(int i=1;i<=n; i++)
    {
        ans = max(ans, query(0, n-1, i, 1)); 
    }

    cout << ans << endl; 
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