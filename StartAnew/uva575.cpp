#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    string s; 
    while(cin >> s)
    {
        int p = 2; 
        if(s=="0") break;

        ll ans = 0; 
        while(!s.empty())
        {
            ll x = s.back() - '0';

            ans += (p-1)*x; 
            s.pop_back();
            p *= 2; 
        }
        cout << ans << endl; 
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