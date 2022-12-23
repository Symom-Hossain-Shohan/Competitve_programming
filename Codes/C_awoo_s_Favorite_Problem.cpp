#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    string s, t; 
    cin >> s >> t; 
    if(count(s.begin(), s.end(), 'b')!= count(t.begin(), t.end(), 'b'))
    {
        cout << "NO\n"; 
        return; 
    }
    for(int i=0, j=0;i<n;i++)
    {
        if(s[i]=='b') continue;
        while(t[j]=='b') j++; 

        if(s[i]!=t[j] or(s[i]=='a' and i>j) or (s[i]=='c' and i<j)) 
        {
            cout << "NO\n" ; 
            return; 
        }
        j++; 
    }

    cout << "YES\n" ; 
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