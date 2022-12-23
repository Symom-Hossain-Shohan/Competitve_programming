#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    string s; 
    cin >> s; 
    ll b =0 , r = 0 ;
    bool ok = true ;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='B') b++ ; 
        else if(s[i]=='R') r++ ; 
        else 
        {
            if((b>0 and r==0) or (r>0 and b==0)) ok = false ; 
            b=0, r=0 ;
        }
    }
    if((b>0 and r==0) or (r>0 and b==0)) ok = false ; 
    if(ok) cout << "YES\n" ; 
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