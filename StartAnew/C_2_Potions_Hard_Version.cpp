#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    vector<ll> v(n);
    for(auto &i: v) cin >> i; 
    //ll sum = 0; 
    priority_queue<ll> pq; 

    ll sum = 0, ans = 0; 
    for(int i=0;i<n; i++)
    {
        if(v[i]<0) pq.push(-v[i]);
        else ans++; 
        sum += v[i];
        while(sum<0)
        {
            sum += pq.top();
            pq.pop();
        }
    }

    cout << ans + pq.size() << endl; 

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