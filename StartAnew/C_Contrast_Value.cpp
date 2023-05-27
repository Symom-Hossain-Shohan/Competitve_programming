#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto &i : v)
        cin >> i;
    if (n <= 1)
    {
        cout << n << endl;
    }
    else
    {
        vector<ll> ans;
        ans.push_back(v[0]);
        for (int i = 0; i < n; i++)
        {
            if (v[i] != ans.back())
                ans.push_back(v[i]);
        }

        n = ans.size();
        ll res = n; 
        for(int i=0;i+2<n; i++) 
        {
            if(ans[i]<ans[i+1] and ans[i+1]<ans[i+2]) res--; 
            else if(ans[i]>ans[i+1] and ans[i+1]>ans[i+2]) res--;  
        }

        cout << res << endl; 
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}