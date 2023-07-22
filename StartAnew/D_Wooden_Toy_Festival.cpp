#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool good(ll dif, vector<ll> &v)
{
    ll tmp = v[0] + 2*dif; 
    ll cnt = 1; 
    for(int i=1;i<(int)v.size(); i++)
    {
        if(v[i]>tmp)
        {
            tmp = v[i] + 2*dif; 
            cnt++; 
        }
    }

    return cnt<=3; 
}

void solve()
{
    ll n; 
    cin >> n; 
    vector<ll> v(n);
    for(auto &i: v) cin >> i; 

    sort(v.begin(), v.end()); 

    ll low = 0, high = v.back(), ans = -1; 
    while(low<=high)
    {
        ll mid = (low + high)/2; 

        if(good(mid, v))
        {
            ans = mid; 
            high = mid - 1; 
        }
        else low = mid + 1; 
    }

    cout << ans << endl; 
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