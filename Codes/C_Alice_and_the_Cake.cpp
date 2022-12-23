#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    map<ll,ll> f;
    ll sum=0;

    for(auto &i: v) 
    {
        cin >> i;
        f[i]++;
        sum+=i;
    }

    priority_queue<ll> pq;

    if(n==1) 
    {
        cout << "YES\n";
        return;
    }

    pq.push(sum);
    bool ok=true;

    while(!pq.empty())
    {
        ll u=pq.top();
        pq.pop();

        ll x=u/2;
        ll y=u-x;

        if(f[x]>0) f[x]--;
        else if(f[x]==0 and x>1) pq.push(x);

        if(f[y]>0) f[y]--;
        else if(f[y]==0 and y>1) pq.push(y);

        if(pq.size()>n+2)
        {
            ok=false;
            break;;
        }
    }

    for(auto i: v)
    {
        if(f[i]>0) ok=false;
    }
    if(ok) cout << "YES\n";
    else cout << "NO\n";
}

int main()
{
    ll tc=1;
    cin >> tc;
    for(ll t=1;t<=tc;t++)
    {
        solve();
    }
    return 0;
}