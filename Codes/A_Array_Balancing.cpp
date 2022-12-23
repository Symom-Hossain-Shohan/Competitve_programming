#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n),b(n);
    for(auto &i: a) cin >> i;
    for(auto &i: b) cin >> i;
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>b[i]) swap(a[i],b[i]);
    }   
    for(int i=1;i<n;i++)
    {
        sum+=abs(a[i]-a[i-1])+abs(b[i]-b[i-1]);
    }
    cout << sum << endl;
}

int main()
{
    ll tc=1;
    cin >> tc;
    for(ll t=1;t<=tc;t++)
    {
        solve();
    }
    return 0;
}