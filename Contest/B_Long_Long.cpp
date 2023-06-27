#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    vector<ll> v(n); 
    for(auto &i: v) cin >> i; 

    ll cnt = 0, ans = 0; 
    for(auto i: v) ans += abs(i); 
    for(int i=0;i<n;i++)
    {
        //ans += abs(v[i]); 
        if(v[i]<0)
        {
            cnt++;
            int j = i+1;  
            for(j=i+1;j<n;j++)
            {
                if(v[j]>0) break;
            }
            i = j-1; 
        }
    }
    cout << ans << ' ' << cnt << endl; 
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