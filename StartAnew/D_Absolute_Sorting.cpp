//https://codeforces.com/contest/1772/problem/D
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >>  n; 
    vector<ll> v(n);
    for(auto &i: v) cin >>i; 
    ll x = -1, l = 0, r = 1e9; 
    ll cnt = 0; 
    while(l<=r)
    {
        ll mid = (l+r)/2; 
        ll f = 0; 
        cnt++; 
        for(int i=0;i+1<n;i++)
        {
            if(v[i]<=v[i+1] and abs(v[i]-mid)>abs(v[i+1]-mid))
            {
                f = 1; 
                break;
            }
            else if(v[i]>=v[i+1] and abs(v[i]-mid)>abs(v[i+1]-mid))
            {
                f = 2; 
                break;
            }
        }
        if(f==0) 
        {
            x = mid; 
            break;
        }
        else if(f == 1)
        {
            r = mid - 1; 
        }
        else if( f == 2)
        {
            l = mid + 1; 
        }
    }
    //cout << cnt; 
    cout << x << endl; 
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