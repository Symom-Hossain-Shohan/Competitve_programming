#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    string s; 
    cin >> s; 
    ll n = s.length(), ans = 0, cnt = 0; 
    for(int i = 0;i<n; i++)
    {
        if(s[i]=='1') cnt++; 
        else 
        {
            ans = max(ans, cnt);
            cnt = 0; 
        }
    }
    ans  = max(ans,  cnt);
    cnt = 0; 
    int i = 0; 
    while(s[i]=='1') cnt++, i++; 
    int j = n-1; 
    while(s[j]=='1' and j>=i) cnt++, j--; 
    ans = max(ans, cnt);
    if(count(s.begin(), s.end(), '1')==n)
    {
        cout << n*n << endl; 
        return; 
    }
    if(ans<=2) cout << ans << endl; 
    else 
    {
        if(ans%2)
        {
            cout << (ans+1)/2 * (ans+1)/2 << endl;  
        }
        else 
        {
            cout << (ans/2) * (ans/2+1) << endl; 
        }
    } 
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}