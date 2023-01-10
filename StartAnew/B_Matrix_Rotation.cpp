#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool ok(ll a, ll b, ll c, ll d)
{
    return (a<b and a<c and c <d and b<d);
}

void solve()
{
    ll a, b, c, d; 
    cin >> a >> b >> c >> d; 
    if(ok(a, b, c, d)) cout << "YES\n";
    else if(ok(c, a, d, b)) cout << "YES\n";
    //c a d b
    else if(ok(d, c, b, a)) cout << "YES\n";

    else if(ok(b, d, a, c)) cout << "YES\n";
    else cout << "NO\n";
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