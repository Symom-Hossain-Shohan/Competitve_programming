#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll MEX(vector<ll> v)
{
    map<ll,ll> mp; 
    for(auto i: v) mp[i]++; 
    for(int i = 0;i<=(int)v.size()+1; i++)
    {
        if(mp[i]==0) return i; 
    }
    return 0; 
}

void solve()
{
    ll n; 
    cin >> n; 
    vector<ll> v(n);
    for(auto &i: v) cin >> i; 
    if(n==1)
    {
        if(v.back()==0) cout << "No\n";
        else cout << "Yes\n"; 
    }
    else 
    {
        ll a = MEX(v);
        ll l = 0; 
        while(v[l]!=a+1 and l<n) l++; 
        ll r = n-1; 
        while(v[r]!=a+1 and r-1>=l and r>=0) r--; 
        //cout << l << ' ' << r << endl; 
        if(a==n)
        {
            cout << "No\n"; 
        }
        else 
        {
            map<ll, ll> mp; 
            for(int i=0;i<l; i++) mp[v[i]]++; 
            for(int j=r+1;j<n;j++) mp[v[j]]++; 
            ll cnt = 0; 
            for(int i=0;i<=a; i++)
            {
                if(mp[i]==0)cnt++; 
            }
            if(cnt>1)
            {
                cout << "No\n"; 
            }
            else 
            {
                //cout << cnt << endl; 

                cout << "Yes\n"; 
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