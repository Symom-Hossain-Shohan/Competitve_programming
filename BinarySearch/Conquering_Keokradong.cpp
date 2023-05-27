#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> v;
ll n, k;

ll good(ll mid)
{
    ll cnt = 0, x = 0;
    for (int i = 0; i < n+1; i++)
    {
        if (x + v[i] <= mid)
            x += v[i];
        else
        {
            x = v[i];
            cnt++;
        }
    }
    cnt++;

    return cnt;
}

void solve()
{
    cin >> n >> k;
    v.resize(n+1);
    ll l = 0, r = 0;
    for (auto &i : v)
        cin >> i, r += i;
    ll ans = -1;

    while (l <= r)
    {
        ll mid = (l+r)/2; 
        if (good(mid) <= k+1)
        {
            r = mid - 1;
            if (good(mid) == k+1)
            {
                ans = mid;
                break;
            }
        }
        else
            l = mid + 1;
    }

    vector<ll> res; 
    ll x = 0; 
    for(int i = 0;i<n+1; i++)
    {
       // cout << x << ' '; 
        //cout << v[i] << ' ';
        if(x+v[i]<=ans) x += v[i]; 
        else 
        {
            res.push_back(x); 
            x = v[i];
        }
    }
    //cout << endl; 

    res.push_back(x);
    cout << *max_element(res.begin(), res.end()) << endl; 
    for(auto i: res) cout << i << endl; 
     
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        cout << "Case " << t << ": ";
        solve();
    }
    return 0;
}