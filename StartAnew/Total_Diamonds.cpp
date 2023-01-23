#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mx = 3e6 + 1; 

ll num[mx], pre[mx], dp[mx];

ll fun(ll i)
{
    ll even  =0, odd = 0; 
    while(i)
    {
        ll x = i%10; 
        if(x%2) odd += x; 
        else even+= x; 
        i/=10; 
    }

    return abs(even-odd); 
}

void solve()
{
    ll n; 
    cin >> n; 
    cout << dp[n] << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    for(int i=2;i<=3e6; i++)
    {
        num[i] = fun(i);
        pre[i] = num[i] * 2;
    }

    for(int i = 4;i<=3e6; i++)
    {
        pre[i] += pre[i-1];
    }

    memset(dp, 0, sizeof(dp));

    dp[1] = 2; 
    pre[2] = 0; 
    for(int i=2;i<=1e6;i++)
    {
        
        
        dp[i] = dp[i-1] + pre[2*i-1] - pre[i] + num[2*i]; 
    }
    // cout << dp[1] << ' ' << dp[2] << ' ' << dp[3] << endl; 
    // cout << pre[2] << ' ' << num[2] << endl; 


    // for(int i=1;i<=22;i++) cout << dp[i] << ' '; 
    // cout << endl; 
    
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}