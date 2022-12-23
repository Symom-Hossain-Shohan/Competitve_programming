#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, k; 
    cin >> n>> k; 
    vector<ll> v(n); 
    for(auto &i: v) cin >> i; 
    ll ans = 0; 
    for(int i=0;i<n;i++)
    {
        ans += v[i]/k; 
        v[i] = v[i]%k; 
    }
    //cout << ans << endl; 
    sort(v.begin(), v.end()); 
    
    for(int i = 0, j= n-1;i<j;)
    {
        if(v[i]+v[j]>=k) 
        {
            ans++; 
            i++, j--; 
        }
        else i++; 
    }
    cout << ans << endl;
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