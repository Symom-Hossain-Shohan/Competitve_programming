#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll fun(ll x)
{
    ll mn = x%10, mx = x % 10; 
    while(x)
    {
        mn = min(mn, x%10); 
        mx = max(mx, x%10);
        x/=10; 
    }
    return mx - mn; 
}

void solve()
{
    ll a, b; 
    cin >> a >> b; 
    ll x = max(a, b-100); 
    ll ans = -1, num = -1;  
    for(int i=x;i<=b;i++)
    {
        if(ans<fun(i))
        {
            ans = fun(i);
            num = i; 
        }
    }

    cout << num << endl; 
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