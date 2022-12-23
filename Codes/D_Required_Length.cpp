#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

map<ll,ll> op; 
ll n; 




ll number_of_digit(ll x)
{
    ll ans = 0; 
    while(x)
    {
        ans++; 
        x/=10;
    }
    return ans; 
}


ll dp(ll x)
{
    if(number_of_digit(x)==n) return 0 ; 
    if(number_of_digit(x)>n) return 1e18; 
    if(op[x]!=0) return op[x]; 

    ll tm = x; 
    ll val = 1e18; 
    while(tm)
    {
        ll m = tm%10; 
        tm/=10; 
        if(m>1)
        {
            val = min(val, 1+dp(x*m)); 
        }
    }

    return op[x] = val; 
}

void solve()
{
    ll x; 
    cin >> n >> x; 
    if(number_of_digit(x)==n) cout << 0 << endl ;
    else if(number_of_digit(x)>n or (x==1 and n>1)) cout << -1 << endl; 
    else 
    {
        ll ans = dp(x); 
        if(ans==1e18) cout << -1 << endl; 
        else cout << ans << endl; 
    }
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