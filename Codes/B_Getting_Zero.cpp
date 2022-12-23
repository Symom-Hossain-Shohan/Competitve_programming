#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod=32768;

void solve()
{
    ll n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        ll x;
        cin >> x;
        ll res=1e18;
        for(ll j=0;j<=15;j++)
        {
            ll a=x*(ll)pow(2,j);
            a%=mod;
            if(a==0) 
            {
                res=min(res,j);
                continue;;
            }
            a=mod-a;
            ll r=j+(a/(ll)(pow(2,j)));
            res=min(res,r);

        }
        cout << res << ' ';
    }
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