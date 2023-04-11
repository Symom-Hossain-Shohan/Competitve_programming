#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

string s; 
ll memo[10][2][100];

ll dp(ll pos, bool is_last, ll sum)
{
    if(pos == s.length()) return sum; 
    if(memo[pos][is_last][sum]!=-1) return memo[pos][is_last][sum]; 


    ll till = is_last ? (s[pos] - '0') : 9; 
    ll ans = 0; 
    for(int i = 0; i<=till; i++)
    {
        ans += dp(pos+1, is_last && (i==till), sum + i); 
    }
    return memo[pos][is_last][sum] = ans;  
}


ll digitDp(ll n)
{
    s = to_string(n);
    memset(memo, -1, sizeof(memo)); 

    return dp(0, true, 0); 
}

void solve()
{
    while(1)
    {
        ll a, b; 
        cin >> a >> b; 
        if(a==b and a==-1) return; 

        cout << digitDp(b) - digitDp(a-1) << endl; 
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