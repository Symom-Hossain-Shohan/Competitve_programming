#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    string s ;
    cin >> s ;
    int a = 0 , b = 0;

    if(s.size()==1) cout << "NO\n" ; 
    else if(s[0]=='B' or s[s.size()-1]=='A') cout << "NO\n" ;
    else 
    {
        bool ok = true ; 
        for(int i =0; i<(int)s.size(); i++)
        {
            if(s[i]=='A') a++ ; 
            else b++ ; 
            if(b>a) ok =false ; 
        }

        if(ok) cout << "YES\n" ; 
        else cout << "NO\n" ; 
    }
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