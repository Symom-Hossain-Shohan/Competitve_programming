#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll calc(ll i,ll j)
{
    return (i*i*i+i*i*j+i*j*j+j*j*j);
}

void solve()
{
    ll n;
    cin >> n;
    ll ans=2e18;
    for(ll i=0,j=1000000;i<=1000000 and j>=0;j--)
    {
        if(calc(i,j)>=n and j>=0) 
        {
            ans=min(ans,calc(i,j));
            
        }
        else i++,j++;
    }
    cout <<ans << endl;
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