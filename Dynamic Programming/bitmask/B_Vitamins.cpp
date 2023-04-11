#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n;
vector<ll> cost; 
vector<string> juice; 

ll memo[1001][9];


ll dp(ll pos, ll mask)
{
    if(mask==7)
    {
        return 0; 
    }
    if(pos==n)
    {
        if(mask==7) return 0; 
        else return 1e18; 
    }

    ll &ans = memo[pos][mask]; 
    if(ans ==-1)
    {
        ans = 1e18; 
        ll m1 = mask; 
        for(auto i: juice[pos]) 
        {
            m1 = m1 | (1<<(i-'A')); 
        }
        ans = min(cost[pos]+ dp(pos+1, m1), dp(pos+1, mask)); 
    }
    return ans; 
}

void solve()
{
    cin >> n; 
    map<char,ll> mp; 
    cost.resize(n), juice.resize(n);

    
    for(int i=0;i<n;i++) 
    {
        cin >> cost[i] >> juice[i];
        for(auto j: juice[i]) mp[j]++; 
    }

    if(mp.size()<3) 
    {
        cout << -1 << endl; 
        return; 
    }
    memset(memo, -1, sizeof(memo)); 
    cout << dp(0, 0) << endl; 
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