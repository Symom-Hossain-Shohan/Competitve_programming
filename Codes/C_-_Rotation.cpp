#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, q ;
    cin >> n >> q; 
    string s; 
    cin >> s; 
    ll cnt = 0; 
    while(q--)
    {
        ll a, b; 
        cin >> a >> b; 
        if(a==1) cnt+= b; 
        else
        {
            cnt %= n; 
            ll x = b-cnt-1; 
            while(x<0) x+= n; 
            //cout << x << endl; 
            cout << s[x] << endl; 
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc=1;
    //cin >> tc;
    for(ll t = 1;t <= tc; t++)
    {
        solve();
    }
    return 0;
}