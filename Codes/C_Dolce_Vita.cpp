#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n , k ;
    cin >> n >> k;
    vector<ll> v(n) ; 
    for(auto &i: v) cin >> i ;
    sort(v.begin(),v.end()) ; 

    ll ans = 0; 
    for(int i=1;i<n;i++) v[i]+=v[i-1] ; 

    for(int i=0;i<n;i++)
    {
        if(k>=v[i])
        {
            ans+=(k-v[i])/(i+1)+1;
        }
    }
    

    cout << ans << endl; 
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