#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> squares; 



void solve()
{
    ll n; 
    cin >> n; 
    vector<ll> v(n);
    for(auto &i: v) cin >> i; 
    sort(v.begin(), v.end()); 
    ll x = (ll)sqrt(v[0]); 
    if(x*x<v[0]) x++; 
    ll ans = 0; 
    for(int i=0;i<10000000; i++)
    {
        ll y = (x+i)*(x+i) - v[0];
        ll cnt = 0; 
        //cout << y << ' ';
        for(int j =0;j<n;j++)
        {
            ll t = v[j] + y; 
            ll rt = ceil(sqrt(t)); 
            if(rt*rt==t) cnt++;  
        }
        ans = max(ans, cnt); 
    }
    //cout << endl; 
    cout << ans << endl; 

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