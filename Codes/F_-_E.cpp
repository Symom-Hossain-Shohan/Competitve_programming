#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    double n, R; 
    cin >> n >> R; 
    double r , theta = 2*acos(0.0)/n; 
    r = (R*sin(theta))/(1-sin(theta)); 
    cout << setprecision(20) << r << endl; 
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