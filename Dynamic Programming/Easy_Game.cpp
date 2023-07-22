#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 107; 

ll ar[N], memo[N][N]; 


ll dp(ll i, ll j)
{
    if(i>j) return 0; 

    if(memo[i][j]!= INTMAX_MAX) return memo[i][j]; 

    memo[i][j] = ar[j] - ar[i-1]; 
    for(int k=i;k<=j; k++)
    {
        memo[i][j] = max(memo[i][j], ar[k]-ar[i-1] - dp(k+1, j)); 
        memo[i][j] = max(memo[i][j], ar[j]-ar[k-1] - dp(i, k-1)); 
    }

    return memo[i][j]; 
}

void solve()
{
    ll n; 
    cin >> n; 
    for(int i=1;i<=n; i++) cin >> ar[i]; 
    for(int i=1;i<=n; i++) ar[i] += ar[i-1]; 

    for(int i=1;i<=n; i++) for(int j=1;j<=n; j++) memo[i][j] = INTMAX_MAX; 

    cout << dp(1, n) << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        cout << "Case " << t << ": "; 
        solve();
    }
    return 0;
}