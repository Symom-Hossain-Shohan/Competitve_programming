#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> fib(50);

bool good(ll n, ll x, ll y)
{
    if(n==1) return true; 
    if(min(y, fib[n+1]-y+1)>fib[n-1]) return false; 
    y = min(y, fib[n+1]-y+1); 
    return good(n-1, y, x); 
}

void solve()
{
    ll n, x, y; 
    cin >> n >> x >> y; 
    if(good(n, x, y)) cout << "YES\n";
    else cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    fib[0]= fib[1] = 1; 
    for(int i=2;i<50;i++) fib[i] = fib[i-1] + fib[i-2];
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}