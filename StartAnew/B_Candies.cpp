#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    vector<ll> ans; 
    if(n%2==0)
    {
        cout << -1 << endl; 
        return; 
    }
    while(n!=1)
    {
        if(((n+1)/2)%2==1) ans.push_back(1), n = (n+1)/2; 
        else ans.push_back(2), n = (n-1)/2; 
    }
    n = ans.size(); 
    cout << ans.size() << endl; 
    for(int i=n-1;i>=0;i--) cout << ans[i] << ' '; 
    cout << endl; 
    
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