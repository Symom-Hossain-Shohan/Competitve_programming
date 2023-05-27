#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    ll l = 1, r = n; 
    while(l<=r)
    {
        ll mid = (l+r)/2; 
        cout << "guess "<<mid << endl; 
        string s; 
        cin >> s; 
        if(s=="correct") break;
        else if(s=="low") l = mid + 1; 
        else r = mid - 1; 
    }
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