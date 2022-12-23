#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll a, b, c ;
    cin >> a >> b >> c; 
    cout << a+b+c <<  ' ' << b+c << ' ' << c << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc=1;
    cin >> tc;
    for(ll t=1;t<=tc;t++)
    {
        solve();
    }
    return 0;
}