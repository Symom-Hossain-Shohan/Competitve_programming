#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    vector<ll> v(n);
    ll total_sum = 0; 
    for(auto &i: v) cin >> i, total_sum += i;

    if(total_sum==0) 
    {
        cout << 0 << endl; 
        return; 
    }
    for(int i=1;i<=total_sum;i++)
    {
        if(total_sum%i==0)
        {
            ll x = 0 ; 
            bool ok = true; 
            for(int j=0;j<n;j++)
            {
                x += v[j]; 
                if(x>i) 
                {
                    ok = false; 
                    break;
                }
                if(x==i) x = 0; 
            }
            if(ok) 
            {
                cout << n- total_sum/i << endl; 
                return; 
            }
        }
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