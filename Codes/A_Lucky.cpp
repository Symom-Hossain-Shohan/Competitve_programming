#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    string s ;
    cin >> s ;
    int a = 0, b = 0 ; 
    a = s[0]+s[1]+s[2] - 3*'0'; 
    b = s[3]+s[4]+s[5] - 3*'0'; 
    if(a==b) cout << "YES\n" ; 
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