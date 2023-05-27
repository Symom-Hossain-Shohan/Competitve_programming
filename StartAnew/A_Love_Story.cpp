#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    string a = "codeforces", b; 
    cin >> b; 
    ll cnt = 0; 
    for(int i=0; i<10; i++)
    {
        if(a[i]!=b[i]) cnt++; 
    }
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