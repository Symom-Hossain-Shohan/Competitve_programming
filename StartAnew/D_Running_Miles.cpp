#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 1e5 + 1;
ll n;

vector<ll> v(N);
ll memo[N][4]; 


ll dp(ll pos, ll cnt)
{
    if(pos==n)
    {
        if(cnt==3) return 0; 
        else return INT64_MIN; 
    }
    if(cnt==3) return 0; 
    if(memo[pos][cnt]!=-1) return memo[pos][cnt];

    ll v1 = 0, v2 = 0; 
    v1 = v[pos] + (cnt==0)*pos - (cnt==2)*pos + dp(pos+1, cnt+1);
    v2 = dp(pos+1, cnt);
    return memo[pos][cnt] = max(v1, v2);
    
}

void solve()
{
    cin >> n;
    //v.resize(n);
    for(int i=0;i<n; i++) cin >> v[i];
    for(int i=0;i<=n; i++) memo[i][0] = memo[i][1] = memo[i][2] = memo[i][3] = -1; 
    cout << dp(0, 0) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}