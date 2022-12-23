#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> a, b, c; 
ll n; 

ll point[100005][4]; 

ll dp(ll pos, ll prv)
{
    if(pos == n) return 0; 
    if(point[pos][prv] != -1) return point[pos][prv]; 

    if(prv == 0) 
    {
        ll val1 = a[pos ]+ dp(pos+1, 1) ; 
        ll val2 = b[pos] + dp(pos+1, 2) ; 
        ll val3 = c[pos] + dp(pos+1, 3) ; 
        return point[pos][prv] = max(val1, max(val2, val3)); 
    }
    else if(prv == 1)
    {
        ll val1 = b[pos] + dp(pos+1, 2); 
        ll val2 = c[pos] + dp(pos+1, 3); 
        return point[pos][prv] = max(val1, val2); 
    }
    else if(prv == 2)
    {
        ll val1 = a[pos] + dp(pos+1, 1); 
        ll val2 = c[pos] + dp(pos+1, 3); 
        return point[pos][prv] = max(val1, val2); 
    }
    else 
    {
        ll val1 = a[pos] + dp(pos+1, 1); 
        ll val2 = b[pos] + dp(pos+1, 2); 
        return point[pos][prv] = max(val1, val2); 
    }
}

void solve()
{
    cin >> n; 
    a.resize(n), b.resize(n), c.resize(n); 
    memset(point, -1, sizeof point); 

    for(int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i] ; 
    cout << dp(0, 0) << endl; 
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