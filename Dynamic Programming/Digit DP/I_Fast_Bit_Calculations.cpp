#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
string s; 

ll memo[33][2][2][33];

ll dp(ll pos, bool last, ll prev, ll ans)
{
    if(pos==s.length())
    {
        return ans; 
    }
    if(memo[pos][last][prev][ans] !=-1 ) return memo[pos][last][prev][ans]; 
    ll till = last ? (s[pos]-'0') : 1; 
    ll ret = 0; 
    for(int i = 0;i<=till; i++)
    {
        if(prev and i) ret += dp(pos+1, last && (i==till), i, ans + 1); 
        else ret += dp(pos+1, last && (i==till), i, ans);  
    }
    return memo[pos][last][prev][ans] = ret; 
}

ll fun(ll n)
{
    s.clear();
    while(n)
    {
        if(n%2==0) s.push_back('0'); 
        else s.push_back('1'); 
        n/=2; 

    }
    reverse(s.begin(), s.end()); 
    memset(memo, -1, sizeof(memo)); 
    return dp(0, true, 0, 0);
    //cout << s << endl; 
    //return 1; 
}

void solve()
{
    ll n; 
    cin >> n; 
    cout << fun(n) << endl; 
    
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