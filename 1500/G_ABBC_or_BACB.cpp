#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    string s; 
    cin >> s; 
    if(s[0]=='B' or s.back()=='B') cout << count(s.begin(), s.end(), 'A') << endl; 
    else if(s.find("BB")!= ::string::npos) cout << count(s.begin(), s.end(), 'A') << endl; 
    else 
    {
        ll small = (int)s.size(); 
        ll cnt = 0; 
        ll n = (int) s.size(); 
        for(int i=0;i<n; i++)
        {
            if(s[i]=='A') cnt ++; 
            else 
            {
                small = min(small, cnt); 
                cnt = 0; 
            }
        }
        if(s.back()=='A') small = min(small, cnt); 
        cout << count(s.begin(), s.end(), 'A') - small << endl; 
        // cout << "#" << endl; 
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}