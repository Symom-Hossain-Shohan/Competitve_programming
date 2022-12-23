#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    vector<ll> a(n);
    ll sum = 0; 
    bool ok = true; 
    for(auto &i: a)
    {
        cin >> i; 
        
    }
    sum = a[0];
    for(int i=1;i<n;i++)
    {
        if(sum==0 and a[i]!=0)
        {
            ok =false; 
            break;
        }
        if(sum<0)
        {
            ok =false; 
            break;
        }
        sum += a[i];
    }

    if(ok and sum==0) cout << "Yes\n"; 
    else cout << "No\n";

    
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc=1;
    cin >> tc;
    for(ll t=1;t<=tc;t++)
    {
        solve();
    }
    return 0;
}