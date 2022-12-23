#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll>  h; 
ll n; 
ll dp[100005]; 

ll func(ll pos)
{
    if(pos==0) return 0; 
    else if(pos==1) return abs(h[1] - h[0]) ; 
    
    if(dp[pos]!=-1) return dp[pos] ; 

    return dp[pos] = min(func(pos-1)+abs(h[pos]-h[pos-1]), func(pos-2)+abs(h[pos]-h[pos-2])); 
}

void solve()
{
    cin >> n;
    h.resize(n); 
    memset(dp,  -1, sizeof dp); 
    for(auto &i: h) cin >> i;  
    cout << func(n-1) << endl; 
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