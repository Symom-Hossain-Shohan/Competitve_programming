#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s ;
    
    int x = n/2 ;
    ll ans = 0; 
    for(int i=x;i>=0;i--)
    {
        if(s[i]==s[x]) ans++;
        else break;
    }
    for(int i=x+1;i<n;i++)
    {
        if(s[i]==s[x]) ans++;
        else break;
    }
    cout << ans << endl; 

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