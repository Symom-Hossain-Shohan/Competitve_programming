#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    string s ;
    cin >> s ;
    bool ok = true ; 
    for(int i=1;i<(int)s.size()-1;i++)
    {
        if(s[i]=='a' and (s[i-1]=='b' and s[i+1]=='b')) ok = false ; 
        else if(s[i]=='b' and (s[i-1]=='a' and s[i+1]=='a')) ok = false ;
    }

    if(s.size()==1) ok = false ; 
    else if(s[0]!=s[1] or s[s.size()-1]!=s[s.size()-2] ) ok = false ; 
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