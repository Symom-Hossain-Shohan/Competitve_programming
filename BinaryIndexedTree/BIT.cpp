#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 1e5 + 5; 
ll ar[N], BIT[N] = {0}; 

void update(int i, int inc, int n)
{
    while(i<=n)
    {
        BIT[i] += inc; 
        i += (i & (-i)); 
    }
    return; 
}

int query(int i)
{
    ll ans = 0; 
    while(i>=0)
    {
        ans += BIT[i]; 
        i -= (i & (-i)); 
    }
    return ans; 
}

void solve()
{
    ll n; 
    cin >> n; 
    for(int i=1;i<=n; i++) 
    {
        cin >> ar[i]; 
        update(i, ar[i], n); 
    }




}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    //cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}