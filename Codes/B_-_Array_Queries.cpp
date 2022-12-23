#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MX=100001;
ll ar[MX] ;
ll tree[4*MX] ;

void build_tree(ll node, ll b, ll e)
{
    if(b==e)
    {
        tree[node] = ar[b] ;
        return ;
    }

    ll left = 2*node ;
    ll right = left + 1 ; 
    ll mid = (b+e)/2 ;
    build_tree(left, b, mid) ;
    build_tree(right, mid+1, e) ;

    tree[node] = min(tree[left], tree[right]) ;

}

ll query(ll node, ll b, ll e, ll i,ll j)
{
    if(i>e or j<b) return 1e18 ;
    if(i<=b and j>=e)
    {
        return tree[node] ;
    }

    ll left = 2*node ;
    ll right = left + 1 ;
    ll mid = (b+e)/2 ;
    ll q1 = query(left, b, mid, i, j) ;
    ll q2 = query(right, mid+1, e, i, j) ;
    return min(q1, q2) ;
}

void solve()
{
    ll n, q ;
    cin >> n >> q ;
    for(int i=1;i<=n;i++) 
        cin >> ar[i] ;

    build_tree(1, 1, n) ;

    while(q--)
    {
        ll l, r;
        cin >> l >> r ;
        cout << query(1, 1, n, l, r) << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc=1;
    cin >> tc;
    for(ll t=1;t<=tc;t++)
    {
        cout << "Case " << t <<  ":\n";
        solve();
    }
    return 0;
}