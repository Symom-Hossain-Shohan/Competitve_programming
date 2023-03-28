#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    vector<ll> v(3);
    cin >> v[0] >> v[1] >>v[2]; 
    sort(v.begin(), v.end()); 

    ll mx = max(v[2]-v[1]-1, v[1]-v[0]-1);
    ll mn  = 2;
    if(v[2]-v[0]==2) mn = 0;  
    else if(v[1]-v[0]-1==0)
    {
        mn = 2; 
    } 
    else if(v[2]-v[1]-1==0) mn = 2; 
    else mn  = min(v[2]-v[1], v[1]-v[0])-1;
    cout << min(2ll, mn) << endl << mx << endl;  
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    ll tc = 1;
    //cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}