#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, m; 
    cin >> n >> m; 
    vector<ll> v(n*m);

    for(auto &i: v) cin >> i; 
    sort(v.begin(), v.end()); 

    if(n>m) swap(n, m);
    if(n==1) cout << (m-1) * (v[n*m-1]-v[0]) << endl; 
    else 
    {
        ll ans1=(n*m-1)*(v[n*m-1])-v[0]*(n*(m-1))-v[1]*(n-1);
		ll ans2=v[n*m-1]*(n*(m-1))+v[n*m-2]*(n-1)-v[0]*(n*m-1);
		cout<<max(ans1,ans2)<<'\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}