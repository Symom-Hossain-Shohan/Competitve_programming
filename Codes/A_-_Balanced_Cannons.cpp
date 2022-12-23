#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll w, d, a, b ;
    cin >> w >> d >> a >> b ; 
    if(abs(a*w-b*w)<=d) cout << "In balance\n" ;
    else 
    {
        ll s = a+b ; 
        a=s/2 ;
        b=s-a; 
        if(abs(a*w-b*w)<=d) cout << "Move cannons\n" ;
        else cout << "Impossible\n" ;
    }
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