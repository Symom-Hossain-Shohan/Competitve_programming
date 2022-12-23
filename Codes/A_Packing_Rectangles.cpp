#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll w,h,n;

bool good(ll x)
{
    return (x/w)*(x/h)>=n;
}

void solve()
{
    
    cin >> w >> h >> n;
    ll l=0,r=1;
    while(!good(r)) r*=2;
    while(r>l+1)
    {
        ll m=(l+r)/2;
        if(good(m)) r=m;
        else l=m;
    }
    cout << r << endl;
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