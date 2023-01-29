#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9+7; 

void solve()
{
    string s; 
    cin >> s; 
    ll ans = 1;
    ll cnt = 0;  
    for(int i=0;i<(int)s.length(); i++)
    {
        if(s[i]=='a') cnt++; 
        else if(s[i]=='b')
        {
            ans = (ans *(cnt+1)) % mod; 
            cnt = 0; 
        }
    }

    cout << (ans *(cnt+1) -1) % mod << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    //cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}