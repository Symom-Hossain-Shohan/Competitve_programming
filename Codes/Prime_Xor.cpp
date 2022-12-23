#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll x, y;
    cin >>x>>y;

    ll a, b, c; 
    a = 2;
    b = x^a;
    c = y^b;
    if((b>2 and (b&1)) and (c>2 and (c&1)))
    {
    	cout << a << ' ' << min(b, c) << ' ' << max(b, c) <<endl; 
    	return;
    }

    b = 2;
    a = x ^ b; 
    c = y ^b;
    if((a>2 and (a&1)) and (c>2 and (c&1)))
    {
    	cout << b << ' ' << min(a, c) << ' ' << max(a, c) << endl;
    	return;  
    }

    c = 2;
    b = y^c; 
    a = x ^ b; 
    if((a>2 and (a&1)) and (b>2 and (b&1)))
    {
    	cout << 2 << ' ' << min(a, b) << ' ' << max(a, b) << endl;  
    }

}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for(ll t = 1;t <= tc; t++)
    {
        solve();
    }
    return 0;
}