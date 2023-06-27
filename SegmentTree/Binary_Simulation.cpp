#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 5e4 + 5; 

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

    //tree[index] = min(tree[2*index], tree[2*index+1]); 
    tree[index] = tree[2*index] + tree[2*index+1]; 
    return; 
}


void update(ll s, ll e, ll l, ll r, ll index)
{
    if(lazy[index])
    {
        ll x = lazy[index] %2; 
        if(x) tree[index] = !(tree[index]); 

        if(s!=e)
        {
            lazy[2*index] += lazy[index]; 
            lazy[2*index+1] += lazy[index]; 
        }
        lazy[index] = 0; 
    }

    if(s>r or e<l) return; 
    if(s>=l and e<=r)
    {
        tree[index] = !(tree[index]); 
        if(s!=e)
        {
            lazy[2*index] ++; 
            lazy[2*index+1]++; 
        }
        return; 
    }

    ll mid = (s+e)/2; 

    update(s, mid, l, r, 2*index); 
    update(mid+1, e, l, r, 2*index+1); 
    tree[index] = tree[2*index] + tree[2*index+1]; 
    return; 
}


ll query(ll s, ll e, ll i, ll index)
{
    if(lazy[index])
    {
        ll x = lazy[index]; 
        if(x%2) tree[index] = !(tree[index]); 

        if(s!=e)
        {
            lazy[2*index] += x; 
            lazy[2*index+1] += x; 
        }
        lazy[index] = 0; 
    }

    if(i>e or i<s) return 0; 
    if(s==e and s==i) return tree[index]; 

    ll mid = (s+e)/2; 

    ll left = query(s, mid, i, 2*index); 
    ll right = query(mid+1, e, i, 2*index+1); 

    return left+right; 
}


void solve()
{

    memset(lazy, 0, sizeof(lazy)); 
    string num; 
    cin >> num;
    ll n = num.size();  
    for(int i=0;i<(int)num.length(); i++) ar[i] = num[i] - '0'; 

    buildTree(0, n-1, 1); 

    ll q; 
    cin >> q; 
    while(q--)
    {
        char ch; 
        cin >> ch; 
        if(ch=='I')
        {
            ll l, r; 
            cin >> l >> r; 
            l--, r--; 

            update(0, n-1, l, r, 1); 
        }
        else 
        {
            ll x; 
            cin >> x; 
            x--; 
            cout<< query(0, n-1, x, 1) << endl;
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