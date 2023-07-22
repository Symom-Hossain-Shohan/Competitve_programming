#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 2e5 + 1; 

vector<ll> v[N], ar;
ll memo[N][2];
ll n; 

ll dp(ll pos, ll flag)
{
    if(pos==n) return 0; 
    if(memo[pos][flag]!=-1) return memo[pos][flag]; 

    ll op1, op2; 

    // option one
    if(flag==0) op1 = 1 + dp(pos+1, 0);
    else op1 = dp(pos+1, 0);

    // option two

    ll up = upper_bound(v[ar[pos]].begin(), v[ar[pos]].end(), pos) - v[ar[pos]].begin();
    if(up==v[ar[pos]].size()) 
    {
        up = pos+1;
        if(flag==0) op2 = 1 + dp(up, 0);
        else op2 = dp(up, 0);
    } 
    else 
    {
        up = v[ar[pos]][up];
        op2 = dp(up, 1);
    }

    return memo[pos][flag] = min(op1, op2); 


}

void solve()
{
    cin >> n; 
    ar.clear();
    for(int i=0;i<=n; i++) v[i].clear(), memo[i][0]=-1, memo[i][1]=-1;

    for(int i=0;i<n;i++)
    {
        ll x; 
        cin >> x; 
        ar.push_back(x);
        v[x].push_back(i);
    }
    memset(memo, -1, sizeof(memo));
    cout << n - dp(0, 0) << endl; 

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