#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MX=100001;

ll ar[MX];
ll tree[4*MX] ;

void seg_create(ll node, ll b, ll e)
{
    if(b==e) 
    {
        tree[node]=ar[b];
        return;
    }

    ll left =  2*node ;
    ll right = 2*node + 1 ;
    ll mid = (b+e)/2 ;
    seg_create(left, b, mid) ;
    seg_create(right, mid+1, e) ;
    
    tree[node] = tree[left] + tree[right] ;
}

ll query(ll node, ll b, ll e, ll i, ll j)
{
    if(i>e or j<b ) return 0 ;
    if(b>=i and e<=j ) return tree[node] ;

    ll left = 2*node ;
    ll right = 2*node + 1 ;
    ll mid = (b+e)/2 ;
    ll query1 = query(left, b, mid, i, j) ;
    ll query2 = query(right, mid+1, e, i, j) ;

    return query1 + query2 ;

}

void update(ll node, ll b, ll e, ll i, ll newvalue)
{
    if( i > e || i < b ) return ;
    if(b==e) 
    {
        tree[node] = newvalue;
        return ;
    }

    ll left =  2*node ;
    ll right = 2*node + 1 ;

    ll mid = (b+e)/2;

    update(left, b, mid, i, newvalue) ;
    update(right, mid+1, e, i, newvalue) ;
    tree[node] = tree[left] + tree[right] ;
}




void solve()
{
    ll n;
    cin >> n;
    for(ll i=1;i<=n;i++) cin >> ar[i];
    seg_create(1,1,n);
    
    cout << query(1, 1, n, 1, 4)  << endl ;
    
    update(1,1,n,3,4) ;

    cout << query(1,1,n,1,4) << endl;
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