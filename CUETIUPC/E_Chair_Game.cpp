#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll memo[1001][3][3]; 
ll n; 

ll dp(ll pos, ll prev, ll first)
{
    if(memo[pos][prev][first]!=-1) return memo[pos][prev][first]; 

    ll ans = 0; 
    if(pos==0)
    {
        ans += dp(pos+1, 0, 0);
        ans += dp(pos+1, 1, 1); 
        ans += dp(pos+1, 2, 2); 
    }
    else if(pos==n-1)
    {
        if(first==0)
        {
            if(prev==0)
            {
                ans += dp(pos+1, 0, first); 
            }
            else if(prev==1)
            {
                ans += dp(pos+1, 2, first); 
            }
            else 
            {
                ans += dp(pos+1, 2, first); 
            }
        }
        else if(first==1)
        {
            if(prev==0)
            {
                ans += dp(pos+1, 1, first); 
            }
            else if(prev==1)
            {
                ans += dp(pos+1, 2, first); 
                ans += dp(pos+1, 1, first); 
            }
            else 
            {
                ans += dp(pos+1, 0, first); 
                ans += dp(pos+1, 1, first); 
                ans += dp(pos+1, 2, first); 
            }
        }
        else 
        {
            if(prev==0)
            {
                ans += dp(pos+1, 1, first); 
            }
            else if(prev==1)
            {
                ans += 0; 
            }
            else 
            {
                
            }
        }
        
    }
    else 
    {
        if(prev==0)
        {
            ans += dp(pos+1, 0, first); 
            ans += dp(pos+1, 1, first); 
        }
        else if(prev==1)
        {
            ans += dp(pos+1, 1, first); 
            ans += dp(pos+1, 2, first); 
        }
        else 
        {
            ans += dp(pos+1, 0, first); 
            ans += dp(pos+1, 2, first); 
            ans += dp(pos+1, 1, first); 
        }
    }
}

void solve()
{
    cin >> n; 
    memset(memo, -1, sizeof(memo)); 
    if(n==1)
    {
        cout << n << endl; 
    }
    else if(n==2)
    {
        cout << 2 << endl; 
    }
    else if(n==3)
    {
        cout << 6 << endl; 
    }
    else 
        cout << dp(0, 0, 0) << endl; 
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