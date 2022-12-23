#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mx = 1e5 + 5 ;

ll row[mx], col[mx], row_tree[4*mx], col_tree[4*mx]; 

void update_row(ll node, ll b, ll e, ll i, ll v)
{
    if(b>i or e<i) return; 
    if(b==e and e == i)
    {
        row_tree[node] = v; 
        return; 
    }

    ll left = 2*node; 
    ll right = 2*node + 1; 
    ll mid = (b+e)/2; 

    update_row(left, b, mid, i, v); 
    update_row(right, mid+1, e, i, v); 

    row_tree[node] = row_tree[left] + row_tree[right]; 
}

void update_col(ll node, ll b, ll e, ll i, ll v)
{
    if(b>i or e<i) return; 
    if(b==e and e == i)
    {
        col_tree[node] = v; 
        return; 
    }

    ll left = 2*node; 
    ll right = 2*node + 1; 
    ll mid = (b+e)/2; 

    update_col(left, b, mid, i, v); 
    update_col(right, mid+1, e, i, v); 

    col_tree[node] = col_tree[left] + col_tree[right]; 
}

ll query_row(ll node, ll b, ll e, ll i, ll j)
{
    if(b>j or e<i) return 0 ; 
    if(b>=i and e<=j) return row_tree[node]; 

    ll left = 2*node ; 
    ll right = 2*node + 1; 
    ll mid = (b+e)/2; 

    return query_row(left, b, mid, i, j) + query_row(right, mid+1, e, i, j); 
}

ll query_col(ll node, ll b, ll e, ll i, ll j)
{
    if(b>j or e<i) return 0; 
    if(b>=i and e<=j) return col_tree[node]; 

    ll left = 2*node; 
    ll right = 2*node + 1; 
    ll mid = (b+e)/2; 
    return query_col(left, b, mid, i, j) + query_col(right, mid+1, e, i, j); 
}

void solve()
{
    ll n, q; 
    cin >> n >> q ;
    while(q--)
    {
        ll t ;
        cin >> t ; 
        if(t==1)
        {
            ll x, y; 
            cin >> x >> y ; 
            if(row[x]==0) update_row(1, 1, n, x, 1); 
            if(col[y]==0) update_col(1, 1, n, y, 1); 
            row[x]++; 
            col[y]++; 
        }
        else if(t==2)
        {
            ll x, y; 
            cin >> x >> y; 
            row[x]--; 
            col[y]--; 
            if(row[x]==0) update_row(1, 1, n, x, 0); 
            if(col[y]==0) update_col(1, 1, n, y, 0); 
        }
        else 
        {
            ll x1, y1, x2, y2; 
            cin >> x1 >> y1 >> x2 >> y2; 
            ll r = query_row(1, 1, n, x1, x2); 
            ll c = query_col(1, 1, n, y1, y2); 
            if(r==(x2-x1)+1 or c==(y2-y1+1)) cout << "Yes\n"; 
            else cout << "No\n"; 
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