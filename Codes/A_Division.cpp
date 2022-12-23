#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll r ;
    cin >> r ; 
    if(r<=1399) cout << "Division 4\n";
    else if(r<=1599) cout << "Division 3\n";
    else if(r<=1899) cout << "Division 2\n"; 
    else cout << "Division 1\n" ;
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