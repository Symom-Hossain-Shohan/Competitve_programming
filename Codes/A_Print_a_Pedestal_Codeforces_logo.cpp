#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    ll a , b , c; 
    a = (n+2)/3; 
    b = n/3; 
    c = n - (a+b); 
    while(b<=c)
    {
        b++; 
        c--; 
    }
    while(a<=b) 
    {
        a++; 
        b--; 
    }
    while(b<=c)
    {
        b++; 
        c--; 
    }

    cout << b<< ' ' << a << ' ' << c << endl; 
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