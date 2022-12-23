#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MX = 100001 ; 
ll ar[MX] ;
ll tree[4*MX] , prop[4*MX] ;

void build_tree(ll node, ll b, ll e)
{
    if(b==e)
    {
        tree[node] = ar[b] ;
        return ;
    }

    ll left = 2*node ;
    ll right = 2*node + 1 ;
    ll mid = (b+e)/2 ;
    build_tree(left, b, mid) ;
    build_tree(right, mid+1, e) ;
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
            prop[2*node+1] += p ; 
        }
    }

    if(i>e or j<b) return 0 ;
    if(i<=b and j>=e) 
    {
        return tree[node] ;
    }

    ll left = 2*node ; 
    ll right = 2*node  + 1 ;
    ll mid = (b+e)/2 ;
    return query(left, b, mid, i, j) + query(right, mid+1, e, i, j) ;
}


void update(ll node, ll b, ll e, ll i, ll j, ll v)
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
    ll mid = (b+e)/2  ;
    update(left, b, mid, i, j, v) ;
    update(right, mid+1, e, i, j, v) ;
    tree[node] = tree[left] + tree[right] ;
}

void solve()
{
    ll n, q ; 
    cin >> n >> q ;
    for(int i=1; i<=n; i++) cin >> ar[i] ;
    build_tree(1, 1, n) ;

    //1 -> update and 2 -> query
    while(q--)
    {
        ll t ; 
        cin >> t ;
        if(t==1)
        {
            //update
            ll l, r, v ;
            cin >> l >> r >> v ;
            update(1, 1, n, l, r, v) ;
        }
        else
        {
            //query
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
    //cin >> tc;
    for(ll t=1;t<=tc;t++)
    {
        solve();
    }
    return 0;
}