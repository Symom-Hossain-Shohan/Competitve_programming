#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    string s; 
    cin >> s;
    ll cnt = 0;  
    for(int i = 0;i<n;i++)
    {
        if(s[i]=='1')
        {
            cnt++; 
            if(s[i+1]=='0' and i+1<n) 
            {
                cnt++, i++; 
            }
            if(s[i+1]=='0' and i+1<n)
            {
                cnt++, i++; 
            }
        }
    }
    cout << cnt << endl; 

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