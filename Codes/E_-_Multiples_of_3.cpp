#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MX = 100001 ;
ll tree[4*MX][3] ;
ll prop[4*MX] ;

void build_tree(ll node, ll b, ll e)
{
    if(b==e)
    {
        tree[node][0] = 1 ;
        tree[node][1] = 0 ;
        tree[node][2] = 0 ;
        return ;
    }
    ll left = 2*node ; 
    ll right = 2*node +  1 ;
    ll mid = (b+e)/2 ; 
    build_tree(left, b, mid) ;
    build_tree(right, mid+1, e) ;
    tree[node][0] = tree[left][0] + tree[right][0] ;
    tree[node][1] = tree[left][1] + tree[right][1] ;
    tree[node][2] = tree[left][2] + tree[right][2] ;
}

ll query(ll node, ll b, ll e, ll i, ll j)
{
    if(prop[node]!=0)
    {
        ll p = prop[node] ;
        prop[node] = 0 ;
        
        if(b!=e)
        {
            prop[2*node] += p ; 
            prop[2*node+1] +=p ; 
        }

        p%=3 ; 
        for(int i=0;i<p; i++)
        {
            ll tmp = tree[node][2] ;
            tree[node][2]= tree[node][1] ; 
            tree[node][1] = tree[node][0] ;
            tree[node][0] = tmp ;
        }

    }

    if(i>e or j<b) return 0 ;
    if(i<=b and j>=e)
    {
        return tree[node][0] ;
    }

    ll left = 2*node ; 
    ll right = 2*node + 1 ; 
    ll mid = (b+e)/2 ; 
    return query(left, b, mid, i, j) + query(right, mid+1, e, i, j) ;
}

void update(ll node, ll b, ll e, ll i, ll j)
{
    if(prop[node]!=0)
    {
        ll p = prop[node] ;
        prop[node]  = 0 ;
        if(b!=e)
        {
            prop[2*node] += p ; 
            prop[2*node+1] += p ; 
        }

        p%=3 ; 
        for(int i=0 ; i<p ; i++) 
        {
            ll tmp = tree[node][2] ;
            tree[node][2]= tree[node][1] ; 
            tree[node][1] = tree[node][0] ;
            tree[node][0] = tmp ;
        }
    }

    if(i>e or j<b) return ; 
    if(i<=b and j>=e) 
    {
        ll tmp = tree[node][2] ;
        tree[node][2]= tree[node][1] ; 
        tree[node][1] = tree[node][0] ;
        tree[node][0] = tmp ;

        if(b!=e)
        {
            prop[2*node]++; 
            prop[2*node+1]++; 
        }

        return ;
    }

    ll left = 2*node ; 
    ll right = 2*node + 1 ; 
    ll mid = (b+e)/2 ; 
    update(left, b, mid, i, j) ;
    update(right, mid+1, e, i, j) ;
    tree[node][0] = tree[left][0] + tree[right][0] ;
    tree[node][1] = tree[left][1] + tree[right][1] ;
    tree[node][2] = tree[left][2] + tree[right][2] ;
}

void solve()
{
    ll n, q ; 
    cin >> n >> q ; 
    build_tree(1, 1, n) ;

    while(q--)
    {
        ll t, l, r ; 
        cin >> t >> l >> r ; 
        l++, r++ ;
        if(t==0)
        {
            update(1, 1, n, l, r) ;
        }
        else 
        {
            
            cout << query(1, 1, n, l, r) << endl ;
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