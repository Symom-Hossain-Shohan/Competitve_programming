#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    vector<ll> a(n), b(n);
    for(auto &i: a) cin >> i; 
    for(auto &i: b) cin >> i; 
    vector<ll> first(2*n+1, 0), second(2*n+1, 0); 

    for(int i=0;i<n;i++)
    {
        ll x = a[i], cnt = 0; 
        while(a[i]==x and i<n)
        {
            cnt++, i++; 
        }
        i--; 
        first[x] = max(first[x], cnt); 
    }

    for(int i = 0;i<n; i++)
    {
        ll x = b[i], cnt=0; 
        while(b[i]==x and i<n)
        {
            cnt++, i++; 
        }
        i--; 
        second[x] = max(second[x], cnt); 
    }
     

    ll ans = 0, cnt = 0; 
    for(int i = 1;i<=2*n; i++)
    {
        if(first[i]+second[i]>cnt) 
        {
            cnt = first[i]+second[i]; 
            ans = i; 
        }
    }
    //cout << ans << ' ' ; 
    cout << cnt << endl; 
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