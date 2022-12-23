#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n;
    cin >> n; 
    map<ll,ll> mp ;
    for(int i =0;i<n;i++)
    {
        ll x;
        cin >> x ; 
        mp[x]++;
    }
    ll one =0, two =0; 
    for(auto i: mp)
    {
        if(i.second>=2) two++;
        else one++;
    }

    cout << two + (one+1)/2 << endl; 
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