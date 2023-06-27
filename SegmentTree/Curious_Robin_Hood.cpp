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

    tree[index] = tree[2*index]+ tree[2*index+1]; 
    return; 
}


ll query(ll s, ll e, ll l, ll r, ll index)
{
    if(s>r or e<l) return 0; 
    if(s>=l and e<=r) return tree[index]; 

    ll mid = (s+e)/2; 
    
    ll left = query(s, mid, l, r, 2*index); 
    ll right = query(mid+1, e, l, r, 2*index+1); 
    return left+right; 
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

    tree[index] = tree[2*index] + tree[2*index+1]; 
    return; 

}



void solve()
{
    ll n, q; 
    cin >> n >> q; 
    for(int i=0;i<n;i++) cin >> ar[i]; 

    buildTree(0, n-1, 1); 

    while(q--)
    {
        ll choice; 
        cin >> choice; 
        if(choice==1)
        {
            ll i; 
            cin >> i; 
            ll x = query(0, n-1, i, i, 1); 
            cout << x << "\n"; 
            update(0, n-1, i, i, -x, 1); 
        }
        else if(choice==2)
        {
            ll i, v; 
            cin >> i >> v; 
            update(0, n-1, i, i, v, 1); 
        }
        else 
        {
            ll i, j; 
            cin >> i >> j; 
            cout << query(0, n-1, i, j, 1) << "\n";
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