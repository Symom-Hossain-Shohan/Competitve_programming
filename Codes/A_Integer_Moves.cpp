#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int x, y ;
    cin >> x >> y ;
    ll a = sqrt(x*x+y*y); 
    if(x==y and x==0) cout << 0 << endl; 
    else if(a*a == x*x + y*y) cout << 1 << '\n' ; 
    else cout << 2 << endl; 
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