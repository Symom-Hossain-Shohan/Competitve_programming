#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll x; 
    cin >> x; 
    ll ans1 = 1, ans2 = 2, ans3 = 3, v1 = 0, v2 = 0, v3 = 0; 
    while(x--)
    {
        ll a, b , g; 
        cin >> a >> b >> g; 
        //first
        if(a==ans1) ans1 = b; 
        else if(b==ans1) ans1 = a; 
        if(ans1==g) v1++; 
        //second
        if(a==ans2) ans2 = b; 
        else if(b==ans2) ans2 = a; 
        if(ans2==g) v2++; 

        //third
        if(a==ans3) ans3 = b; 
        else if(b==ans3)  ans3 = a; 
        if(ans3==g) v3++; 
    }

    cout << max({v1, v2, v3}) << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);
    ll tc = 1;
    //cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}