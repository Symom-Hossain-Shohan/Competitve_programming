#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MX = 100001 ; 

ll tree[4*MX] ; 
ll prop[4*MX] ;

void update(ll node, ll b, ll e, ll i, ll j, ll v)
{
    if(prop[node]!=-1)
    {
        ll p = prop[node] ;
        prop[node] = -1 ;
        tree[node] = p*(e-b+1) ;
        if(b!=e)
        {
            prop[2*node] = p ; 
            prop[2*node+1] = p ; 
        }
    }

    if(i>e or j<b) return ; 
    if(i<=b and j>=e)
    {
        ll p = v ;
        tree[node] = p*(e-b+1) ;
        if(b!=e)
        {
            prop[2*node] = p ; 
            prop[2*node+1] = p ; 
        }
        return ;
    }

    ll left = 2*node ; 
    ll right = 2*node  + 1 ; 
    ll mid =  (b+e)/2 ; 
    update(left, b, mid, i, j, v) ;
    update(right, mid+1, e, i, j, v) ;
    tree[node] = tree[left] + tree[right] ;
}

ll query(ll node, ll b, ll e, ll i, ll j)
{
    if(prop[node]!=-1)
    {
        ll p = prop[node] ; 
        prop[node] = -1 ; 
        tree[node] = p*(e-b+1) ; 
        if(b!=e)
        {
            prop[2*node] = p ; 
            prop[2*node+1] = p ; 
        }

    }

    if(i>e or j<b) return 0 ; 
    if(i<=b and j>=e)
    {
        return tree[node] ;
    }
    ll left = 2*node ; 
    ll right = 2*node + 1 ; 
    ll mid = (b+e)/2 ; 
    return query(left, b, mid, i, j) + query(right, mid+1, e, i, j) ;
}

void solve()
{
    memset(tree, 0, sizeof(tree)) ;
    memset(prop, -1, sizeof(prop)) ;

    ll n, q ; 
    cin >> n >> q ; 
    while(q--)
    {
        ll choice ;
        cin >> choice ; 
        if(choice==1)
        {
            ll i, j, v ; 
            cin >> i >> j >> v ; 
            i++, j++ ; 
            update(1, 1, n, i, j, v) ;
        }
        else 
        {
            ll i, j ; 
            cin >> i >> j ; 
            i++, j++ ; 
            ll ans = query(1, 1, n, i, j) ;
            ll x = (j-i+1) ;
            if(ans%x==0) cout << ans/x << endl ;
            else cout<< ans/__gcd(ans,x) << "/" << x/__gcd(ans,x) << endl ;
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
        cout << "Case " << t << ":\n";
        solve();
    }
    return 0;
}