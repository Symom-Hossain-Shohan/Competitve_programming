#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, k; 
vector<ll> v; 

ll memo[10][12];

ll dp(ll last, ll pos)
{
    if(pos==k) 
    {
        //cout << ans << endl; 
        return 1;
    } 
    ll val = 0; 

    if(memo[last][pos]!=-1) return memo[last][pos]; 
    for(int i = 0;i<n;i++)
    {
        ll x = v[i];
        if(x> last +2 or x<last-2 and pos!=0) continue;
        else 
        {
            val += dp(x, pos+1); 
        }
        
    }
    return memo[last][pos] = val; 

}

void solve()
{
    cin >> n >> k; 
    v.resize(n);
    for(auto &i: v) cin >> i; 
    sort(v.begin(), v.end()); 
    memset(memo, -1, sizeof(memo)); 
    cout << dp(9, 0) << endl; 
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