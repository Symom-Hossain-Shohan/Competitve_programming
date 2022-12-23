#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MX = 100001 ; 
ll tree[4*MX] ;
ll prop[4*MX] ;

void update(ll node, ll b, ll e,ll i, ll j, ll v)
{
    if(prop[node]!=0)
    {
        ll p = prop[node] ;
        prop[node] = 0 ;
        tree[node] += p*(e-b+1) ; 
        if(b!=e) 
        {
            prop[2*node] += p ;
            prop[2*node+1] += p ; 
        }
    }

    if(i>e or j<b) return ;
    if(i<=b and j>=e) 
    {
        ll p = v ; 
        tree[node] += p*(e-b+1) ;
        if(b!=e)
        {
            prop[2*node] += p ; 
            prop[2*node+1] += p ; 
        }
        return ;
    }

    ll left = 2*node ; 
    ll right = 2*node + 1 ; 
    ll mid = (b+e)/2 ; 
    update(left, b, mid, i, j, v) ;
    update(right, mid+1, e, i, j, v) ;
    tree[node] = tree[left] + tree[right] ;
}

ll query(ll node, ll b, ll e, ll i, ll j)
{
    if(prop[node]!=0)
    {
        ll p = prop[node] ;
        prop[node] = 0 ; 
        tree[node] += p*(e-b+1) ;
        if(b!=e)
        {
            prop[2*node] += p ; 
            prop[2*node+1] += p; 
        }
    }

    if(i>e or j<b ) return 0;
    if(i<=b and j>=e) 
    {
        return tree[node] ;
    }

    ll left = 2*node ; 
    ll right = 2*node  + 1 ; 
    ll mid = (b+e)/2 ; 
    return query(left, b, mid, i, j) + query(right, mid+1, e, i, j) ;
}

void solve()
{
    memset(tree, 0, sizeof(tree)) ;
    memset(prop, 0, sizeof(prop)) ;
    ll n, q ; 
    cin >> n >> q ; 
    while(q--)
    {
        ll t ; 
        cin >> t ; 
        if(t==0)
        {
            ll l, r, v ;
            cin >> l >> r >> v ;
            update(1, 1, n, l, r, v) ;
        }
        else 
        {
            ll l, r ;
            cin >> l >> r ;
            cout << query(1, 1, n, l, r) << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc=1;
    cin >> tc;
    for(ll t=1;t<=tc;t++)
    {
        solve();
    }
    return 0;
}