#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    vector<ll> v; 
    cin >> n; 
    for(int i=0;i<n; i++)
    {
        ll x; 
        cin >> x; 
        v.push_back(x);
    }
    sort(v.begin(), v.end()); 
    ll ans = 0; 
    for(int i = 0;i<n-2; i++)
    {
        for(int j=i+1;j<n-1 ;j++)
        {
            ll x = v[i] + v[j];
            //numbers that are less than x
            ll low = j, high = n-1; 
            while(low<=high)
            {
                ll mid=(low+high)/2; 
                if(v[mid]>=x) high = mid-1; 
                else low = mid+1; 
            }
            if(high>=j) ans += (high-j); 
        }
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
        cout << "Case " << t << ": "; 
        solve();
    }
    return 0;
}