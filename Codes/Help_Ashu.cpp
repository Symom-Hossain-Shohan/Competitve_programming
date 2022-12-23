#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MX = 100001 ;

ll ar[MX] ;
ll EVEN[4*MX] ;
ll ODD[4*MX] ;

void build_tree(ll node, ll b, ll e)
{
    if(b==e) 
    {
        if(ar[b]%2==1)
        {
            ODD[node] = 1 ;
            EVEN[node] = 0 ;
        }
        else 
        {
            ODD[node] = 0 ;
            EVEN[node] = 1 ;
            return ;
        }

        return ;
    }

    ll left = 2*node ;
    ll right = 2*node + 1 ;
    ll mid = (b+e)/2 ;

    build_tree(left, b, mid) ;
    build_tree(right, mid+1, e) ;
    ODD[node] = ODD[left] + ODD[right] ;
    EVEN[node] = EVEN[left] + EVEN[right] ;
}

void update(ll node, ll b, ll e, ll i, ll v)
{
    if(i<b or i>e) return ;
    if(b==e)
    {
        ODD[node] = v%2==1 ;
        EVEN[node] = v%2==0  ;
        return ;
    }

    ll left = 2*node ;
    ll right = 2*node + 1 ;
    ll mid = (b+e)/2 ;
    update(left, b, mid, i, v) ;
    update(right, mid+1, e, i, v) ;
    ODD[node] = ODD[left] + ODD[right] ;
    EVEN[node] = EVEN[left] + EVEN[right] ;
}

ll count_even(ll node, ll b, ll e, ll i, ll j)
{
    if(i>e or j<b) return 0;
    if(i<=b and j>=e)
    {
        return EVEN[node] ;
    }

    ll left = 2*node ;
    ll right = 2*node + 1 ;
    ll mid = (b+e)/2 ;
    ll q1 = count_even(left, b, mid, i, j) ;
    ll q2 = count_even(right, mid+1, e, i, j) ;
    return q1+q2 ;
}


ll count_odd(ll node, ll b, ll e, ll i, ll j)
{
    if(i>e or j<b) return 0;
    if(i<=b and j>=e)
    {
        return ODD[node] ;
    }

    ll left = 2*node ;
    ll right = 2*node + 1 ;
    ll mid = (b+e)/2 ;
    ll q1 = count_odd(left, b, mid, i, j) ;
    ll q2 = count_odd(right, mid+1, e, i, j) ;
    return q1+q2 ;
}

void solve()
{
    ll n;
    cin >> n;

    for(ll i=1;i<=n;i++) cin >> ar[i] ;
    build_tree(1, 1, n) ;
    
    ll q ;
    cin >> q ;
    while(q--)
    {
        ll t, l, r;
        cin >> t >> l >> r;
        if(t==0)
        {
            update(1, 1, n, l, r) ;
        }
        else if(t==1)
        {
            cout << count_even(1, 1, n, l, r) << endl ;
        }
        else 
        {
            cout << count_odd(1, 1, n, l, r) << endl ; 
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