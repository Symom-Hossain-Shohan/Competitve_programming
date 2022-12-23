#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n,k;
vector<ll> v;

bool good(double x)
{
    ll cnt=0;
    for(int i=0;i<n;i++)
    {
        cnt+=(v[i]/x);
    }
    return cnt>=k;
}

void solve()
{
    cin >> n >> k;
    v.resize(n);
    for(auto &i: v) cin >> i;

    double l=0,r=1e8;
    for(int i=0;i<100;i++)
    {
        double m=(l+r)/2;
        if(good(m)) l=m;
        else r=m;
    }
    cout << setprecision(20) << l << endl;
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