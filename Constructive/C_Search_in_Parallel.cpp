#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, s1, s2; 
    cin >> n >> s1 >> s2; 
    vector<pair<ll,ll>> vp; 
    vector<ll> a, b; 
    for(int i=1;i<=n; i++)
    {
        ll x; 
        cin >> x; 
        vp.push_back({x, i}); 
    }

    sort(vp.rbegin(), vp.rend()); 

    int i=1, j=1; 
    for(int k=0; k<n; k++)
    {
        if(s1*i <=s2*j)
        {
            a.push_back(vp[k].second); 
            i++; 
        }
        else 
        {
            b.push_back(vp[k].second); 
            j++; 
        }
    }

    cout << (int)a.size() << ' '; 
    for(auto i: a) cout << i << ' '; 
    cout << endl; 
    cout << (int)b.size() << ' '; 
    for(auto i: b) cout << i << ' '; 
    cout << endl; 
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