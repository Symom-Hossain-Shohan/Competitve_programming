#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    string s = "314159265358979323846264338327";
    string a; 
    cin >> a; 
    ll cnt = 0; 
    int i = 0; 
    while(s[i]==a[i] and i<(int)a.length()) i++, cnt++; 
    cout << cnt << endl; 
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