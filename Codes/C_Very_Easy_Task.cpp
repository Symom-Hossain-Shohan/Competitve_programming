#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n,x,y;
bool good(ll t)
{
    return ((t/x)+(t/y))>=(n-1);
}


void solve()
{
    cin >> n >> x >> y;
    ll l=0,r=max(x,y)*(n-1);
    while(r>l+1)
    {
        ll m=(l+r)/2;
        if(good(m)) r=m;
        else l=m;
    }
    
    cout << r+min(x,y) << endl;
}

int main()
{
    ll tc=1;
    //cin >> tc;
    for(ll t=1;t<=tc;t++)
    {
        solve();
    }
    return 0;
}