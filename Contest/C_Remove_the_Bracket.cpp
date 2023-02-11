#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mx = 2e5+1; 
ll memo[mx][2], n, s, ar[mx];

ll dp(ll pos, ll state, ll val)
{
    if(pos==n-1)
    {
        return val*ar[n-1];
    }

    ll &ans = memo[pos][state]; 

    ll mx; 
    if(ar[pos]<=s) mx = ar[pos];
    else if(ar[pos]<=2*s) mx = s; 
    else mx = ar[pos]-s; 

    if(ans==-1)
    {
        ans = min((dp(pos+1, 0, mx)+ val*(ar[pos]-mx)),(dp(pos+1, 1, ar[pos]-mx)+val*(mx))); 
    }
    return ans; 
}

void solve()
{
    cin >> n >> s; 
    for(int i = 0;i<n;i++)
    {
        cin >> ar[i];
        memo[i][0] = memo[i][1] = -1; 
    }

    cout << dp(1, 0, ar[0]) << endl; 

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}