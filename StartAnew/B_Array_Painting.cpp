#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n; 
    vector<ll> v(n);
    for(auto &i: v) cin >> i; 
    vector<bool> visited(n, false); 
    ll ans = 0; 
    for(int i=0;i<n; i++)
    {
        if(visited[i])
        {
            if(i+1<n and v[i]) visited[i+1] = true; 
            continue;
        }

        if(v[i])
        {
            visited[i] = true; 
            ans++; 
            if(i+1<n) visited[i+1] = true; 
            continue;
        }

        if(i<n-1 and v[i+1])
        {
            visited[i] = true; 
            v[i+1]--; 
            continue;
        }
        ans++; 
    }

    cout << ans << "\n"; 
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    //cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}