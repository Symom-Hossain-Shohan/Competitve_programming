#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n ;
    cin >> n;
    vector<int> a(n) ; 
    for(auto &i: a) cin >> i ;
    int gap = 0 ; 
    for(int i=1; i<n;i++) gap+=(a[i]-a[i-1])-1;

    if(gap<=2) cout << "YES\n" ; 
    else cout << "NO\n" ;
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