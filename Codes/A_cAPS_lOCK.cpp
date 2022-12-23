#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    string s; 
    cin >> s; 
    ll cnt = 0; 
    for(int i = 1;i<(int)s.size(); i++) if(toupper(s[i])==s[i]) cnt++; 
    if(cnt == (int)s.size()-1)
    {
        for(int i = 0;i<(int)s.size();i++)
        {
            if(s[i]==tolower(s[i])) s[i] = toupper(s[i]);
            else s[i] = tolower(s[i]);
        }
    }
    cout << s << endl; 
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