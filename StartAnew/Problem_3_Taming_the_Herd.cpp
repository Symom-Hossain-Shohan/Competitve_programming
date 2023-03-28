#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    vector<ll> v(n);
    for(auto &i: v) cin >> i; 
    v[0] = 0; 
    for(int i=0;i<n;i++)
    {
        if(v[i]!=-1)
        {
            ll x = v[i]; 
            ll j = i; 
            while(x>-1)
            {
                v[j] = x; 
                j--, x--; 
            } 
        }
    }
    ll zero = 0, neg_one = 0; 
    for(int i = 0; i<n;i++)
    {
        if(v[i]==0) zero++; 
        else if(v[i]==-1) neg_one++; 
    }

    cout << zero << ' ' << zero+neg_one << endl; 
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