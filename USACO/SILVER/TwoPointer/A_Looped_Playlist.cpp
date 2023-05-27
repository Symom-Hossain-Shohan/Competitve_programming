#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, k; 
    cin >> n >> k; 
    vector<ll> v(n);
    ll sum = 0; 
    for(auto &i: v) cin >> i, sum += i; 

    ll ans = k/sum, res = 1e18; 
    k %= sum; 
    ll ix = 0; 
    for(int i=0; i<n;i++)
    {
        ll sum = 0; 
        for(int j=i;j<n;j++)
        {
            if(sum<k) sum += v[j];
            else 
            { 
                if(res>j-i+1)
                {
                    res = j - i + 1; 
                    ix = i; 
                }
                break;
            }
        }
        if(sum>=k)
        {
            if(res>n-i)
            {
                //cout<< "Yes " << i << endl; ; 
                res = n-i+1; 
                ix = i; 
            }
        }

        for(int j=0;j<i;j++)
        {
            if(sum<k) sum += v[j];
            else 
            {
                if(res>n - i + 1+j)
                {
                    res = n - i + 1+j; 
                    ix = i; 
                }
                break;
            }
        }
    }

    cout << ix+1 << ' ' << ans*n + res-1 << endl;

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