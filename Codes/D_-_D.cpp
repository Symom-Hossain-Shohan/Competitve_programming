#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    string s; 
    cin >> s  ;
    ll c = 0, sm = 0; 
    for(int i=0;i<(int)s.size();i++)
    {
        if(s[i]>='A' and s[i]<='Z') c++;
        else if(s[i]>='a' and s[i]<='z') sm++;
    }
    cout << c << ' ' << sm << endl ;
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