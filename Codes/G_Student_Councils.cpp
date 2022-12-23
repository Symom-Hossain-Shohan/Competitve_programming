#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,k;
vector<ll> v;

bool good(ll m)
{
    ll tm=m*k;
    for(int i=0;i<n;i++)
    {
        tm-=min(v[i],m);
    }
    return tm<=0;
}


void solve()
{
    cin >> k >> n;
    v.resize(n);
    for(auto &i: v) cin >> i;

    ll l=0,r=1e15;
    while(r>l+1)
    {
        ll m=(l+r)/2;
        if(good(m)) l=m;
        else r=m;
    }
    cout << l << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc=1;
    //cin >> tc;
    for(ll t=1;t<=tc;t++)
    {
        solve();
    }
    return 0;
}