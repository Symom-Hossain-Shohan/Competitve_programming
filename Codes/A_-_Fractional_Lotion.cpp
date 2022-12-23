#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    string s; 
    while(cin >> s)
    {
        int n = 0; 
        for(int i=2;i<(int)s.size();i++)
        {
            n = n*10 + s[i]-'0'; 
        } 
        int ans = 0; 
        for(int x = n+1 ; x<= 2*n; x++)
        {
            int a = x*n , b = x-n ;
            if(a%b==0) ans++; 
        }
        cout << ans << endl; 
    }
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