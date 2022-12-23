#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, r, b ;
    cin >> n >> r >> b ;

    ll t = r/(b+1) ;

    string s;
    ll x = b ;
    while(x--)
    {
        for(int i=0;i<t;i++) s.push_back('R') ;
        s.push_back('B');
    } 

    for(int i=0;i<t;i++) s.push_back('R') ;

    
    t = r%(b+1) ;
    for(int i=0;i<(int)s.size() ;i++)
    {
        if(s[i]=='B' and t)
        {
            cout << 'R' ;
            t--;
        }
        cout << s[i];
    }
    cout << endl;

     
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