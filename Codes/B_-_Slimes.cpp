#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll ans=0;
    ll a,b,k;
    cin >> a >> b >> k;
    while(a<b) 
    {
        ans++;
        a*=k;

    }

    cout << ans << endl ;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc=1;
    //cin >> tc;
    for(ll t=1;t<=tc;t++)
    {
        solve();
    }
    return 0;
}