#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n, k ;
    cin >> n>> k;
    ll ans = 0 ; 
    vector<int> v(n) ; 
    for(auto &i: v) cin >> i ;

    int mn = *min_element(v.begin(),v.end()) ; 
    int mx = *max_element(v.begin(),v.end()) ;

    for(int i=1;i<n;i++) ans += abs(v[i]-v[i-1]) ;
    //cout << mx << ' '  << mn << endl; 
    if(1<mn) 
    {
        ans += min(2*(mn-1),min(abs(v[0]-1),abs(v[n-1]-1))) ; 
    }
    if(k>mx)
    {
        ans += min(2*(k-mx),min(abs(v[0]-k),abs(v[n-1]-k))) ;
    }

    cout << ans << endl ; 
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