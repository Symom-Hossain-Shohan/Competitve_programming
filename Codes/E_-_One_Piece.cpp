#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll x1,y1, x2 ,y2 ;
    cin >> x1 >> y1 >> x2 >> y2 ; 
    if(x1==x2 or y1==y2) cout << -1 << endl ;
    else cout << abs(x1-x2)*abs(y1-y2) << endl; 
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