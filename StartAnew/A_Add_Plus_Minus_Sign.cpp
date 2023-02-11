#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n;
    string s; 
    cin >> s; 
    ll sum = s[0]-'0';
    for(int i=1;i<n;i++)
    {
        if(sum==1 and s[i]=='1') sum -= 1, cout << '-'; 
        else sum += s[i] -'0', cout << '+';
    }
    cout << endl; 
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