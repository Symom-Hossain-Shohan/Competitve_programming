#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, m; 
    cin >> n >> m; 
    m--; 
    
    vector<ll> v(n);
    for(auto &i: v) cin >> i; 
    
    ll cur = 0; 
    priority_queue<ll> pq; 
    ll ans = 0; 
    for(int i = m; i>=0;i--)
    {
        cur += v[i];
        pq.push(v[i]);
        if(cur>0 and i)
        {
            ll x = pq.top();
            pq.pop();
            cur -= 2*x; 
            pq.push(-x);
            ans++; 
        }
    }

    cur  = 0; 
    pq = priority_queue<ll> ();
    for(int i = m+1;i<n;i++)
    {
        cur += v[i];
        pq.push(-v[i]);
        if(cur<0)
        {
            ll x = pq.top();
            pq.pop();
            cur += 2*x; 
            pq.push(-x);
            ans ++; 
        }
    }
    cout << ans <<endl; 
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