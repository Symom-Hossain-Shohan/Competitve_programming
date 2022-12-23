#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> v;

bool good(ll m)
{
    ll sum=0;
    for(int i=0;i<(int)v.size();i++)
    {
        sum+=max(0ll,v[i]+i-m);
    }
    return sum+v.size()<=m;
}
void solve()
{
    ll n;
    cin >> n;
    map<ll,ll> m;
    for(int i=1;i<n;i++)
    {
        ll a;
        cin >> a;
        m[a]++;
    }

    v.clear();
    for(auto i: m) v.push_back(i.second);
    v.push_back(1);
    sort(v.begin(),v.end(),greater<int>());

    ll l=0,r=n+1;
    while(r>l+1)
    {
        ll m=(l+r)/2;
        if(good(m))r=m;
        else l=m;
    }
    cout << r << endl;
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